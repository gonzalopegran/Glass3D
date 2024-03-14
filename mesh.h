#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <sstream>
#include <vector>

#include <fstream>
#include <string>
#include <QFile>

#include "vec3.h"
#include "triangle.h"

class Mesh {
public:
    Mesh() {}

    void add(Triangle t) { Triangles.push_back(t); }

    void add(const Point3& vertex1,
             const Point3& vertex2,
             const Point3& vertex3)
    {
        Triangle t(vertex1, vertex2, vertex3);
        Triangles.push_back(t);
    }

    void clear() { Triangles.clear(); }

    int size() { return Triangles.size(); }

    Mesh& scale(const Vec3& s)
    {
        double x, y, z;
        x = ((s.x()!=0) ? s.x() : 1);
        y = ((s.y()!=0) ? s.y() : 1);
        z = ((s.z()!=0) ? s.z() : 1);
        Vec3 _s(x, y, z);

        Vec3 v1, v2, v3;
        for (auto& t : Triangles) {
            v1 = t.v1 * _s;
            v2 = t.v2 * _s;
            v3 = t.v3 * _s;
            t = {v1, v2, v3};
        }
        return *this;
    }

    Mesh& translate(const Vec3& trans)
    {
        Vec3 v1, v2, v3;
        for (auto& t : Triangles) {
            v1 = t.v1 + trans;
            v2 = t.v2 + trans;
            v3 = t.v3 + trans;
            t = {v1, v2, v3};
        }
        return *this;
    }

    Mesh& rotate(double deg, const Vec3& n)
    {
        Vec3 v1, v2, v3;
        for (auto& t : Triangles) {
            v1 = rodrigues_rotate(t.v1, deg, n);
            v2 = rodrigues_rotate(t.v2, deg, n);
            v3 = rodrigues_rotate(t.v3, deg, n);
            t = {v1, v2, v3};
        }
        return *this;
    }

    Mesh& flip_normal()
    {
        for( auto& t : Triangles) {
            t.flip_normal();
        }
        return *this;
    }

    void stl_write_init(const std::string& filename, const std::string& name="") const {
        std::ofstream file(filename);
        file << "solid" << " " << name << std::endl;
        file.close();
    }

    void binarystl_write_init(long triangles) const {
        //binary file
        std::string filename = "binTemp.stl";
        std::string header_info = "solid " + filename + "-output";
        char head[80];
        std::strncpy(head,header_info.c_str(),sizeof(head)-1);

        std::ofstream myfile;

        myfile.open(filename,  std::ios::out | std::ios::binary);
        myfile.write(head,sizeof(head));
        myfile.write((char*)&triangles,4);
        myfile.close();
    }

    void stl_write_triangles(const std::string& filename) const {
        std::ofstream file(filename,std::ios_base::app);

        for (const auto& t : Triangles) {
            file << "facet normal" << " " << t.normal() << std::endl;
            file << "outer loop" << std::endl;
            file << "vertex" << " " << t.vertex1() << std::endl;
            file << "vertex" << " " << t.vertex2() << std::endl;
            file << "vertex" << " " << t.vertex3() << std::endl;
            file << "endloop" << std::endl;
            file << "endfacet" << std::endl;
        }

        file.close();
    }



    void binarystl_write_triangles(QByteArray triangles) const {
        QFile file("binTemp.stl");
        file.open(QIODevice::Append);
        file.write(triangles);
        file.close();
    }

    void stl_write_end(const std::string& filename, const std::string& name="") const {
        std::ofstream file(filename,std::ios_base::app);
        file << "endsolid" << " " << name << std::endl;
        file.close();
    }


    Mesh& operator+=(const Mesh &m) {
        Triangles.insert(Triangles.end(), (m.Triangles).begin(), (m.Triangles).end());
        return *this;
    }

public:
    std::vector<Triangle> Triangles;

};

inline Mesh operator+(const Mesh &m1, const Mesh &m2) {
    Mesh m;
    (m.Triangles).insert((m.Triangles).end(), (m1.Triangles).begin(), (m1.Triangles).end());
    (m.Triangles).insert((m.Triangles).end(), (m2.Triangles).begin(), (m2.Triangles).end());
    return m;
}

inline Mesh create_quadrilateral (const Point3& p1,
                                 const Point3& p2,
                                 const Point3& p3,
                                 const Point3& p4)
{
    Mesh m;
    m.add(p1, p2, p4);
    m.add(p4, p2, p3);
    return m;
};

inline Mesh create_cube ()
{
    Mesh m;
    Point3 vertex1, vertex2, vertex3;

    vertex1 = {0, 0, 1};
    vertex2 = {1, 0, 1};
    vertex3 = {0, 1, 1};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 1, 1};
    vertex2 = {0, 1, 1};
    vertex3 = {1, 0, 1};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 0, 1};
    vertex2 = {1, 0, 0};
    vertex3 = {1, 1, 1};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 1, 0};
    vertex2 = {1, 1, 1};
    vertex3 = {1, 0, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 0, 0};
    vertex2 = {0, 0, 0};
    vertex3 = {1, 1, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {0, 1, 0};
    vertex2 = {1, 1, 0};
    vertex3 = {0, 0, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {0, 0, 0};
    vertex2 = {0, 0, 1};
    vertex3 = {0, 1, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {0, 1, 1};
    vertex2 = {0, 1, 0};
    vertex3 = {0, 0, 1};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {0, 1, 1};
    vertex2 = {1, 1, 1};
    vertex3 = {0, 1, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 1, 0};
    vertex2 = {0, 1, 0};
    vertex3 = {1, 1, 1};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {1, 0, 1};
    vertex2 = {0, 0, 1};
    vertex3 = {1, 0, 0};
    m.add(vertex1, vertex2, vertex3);

    vertex1 = {0, 0, 0};
    vertex2 = {1, 0, 0};
    vertex3 = {0, 0, 1};
    m.add(vertex1, vertex2, vertex3);

    m.translate(Vec3(-0.5, -0.5, -0.5));
    return m;
}

inline Mesh stl_read(const std::string& filename) {
    Mesh m;

    std::ifstream file(filename);
    if ( file.fail() ) {
        std::cerr << "Failed to open " << filename << "." << std::endl;
        return m;
    }

    std::string line, buf;
    double px, py, pz;
    Vec3 v[3];
    int i=0;
    while ( getline(file, line) ) {
        if( line.find("vertex") != std::string::npos ) {
            std::istringstream s(line);
            s >> buf >> px >> py >> pz;
            v[i] = {px, py, pz};
            if(++i>=3) {
                i=0;
                Triangle t(v[0], v[1], v[2]);
                m.add(t);
            }
            continue;
        }
    }
    return m;
}

#endif
