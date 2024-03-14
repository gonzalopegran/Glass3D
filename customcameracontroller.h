#ifndef CUSTOMCAMERACONTROLLER_H
#define CUSTOMCAMERACONTROLLER_H

#include <QEntity>
#include <QMouseDevice>
#include <QKeyboardDevice>
#include <QLogicalDevice>
#include <QAction>
#include <QActionInput>
#include <QAxis>
#include <QAnalogAxisInput>
#include <QCamera>
#include <QFrameAction>


class CustomCameraController : public Qt3DCore::QEntity
{
    Q_OBJECT

public:
    CustomCameraController(Qt3DCore::QNode *parent = Q_NULLPTR);

    float   lookSpeed() const;
    void    setLookSpeed(float newLockSpeed);

    float   linearSpeed() const;
    void    setLinearSpeed(float newLinearSpeed);

    void                setCamera(Qt3DRender::QCamera *newCamera);
    Qt3DRender::QCamera *camera() const;

protected slots:
    void activeChanged(bool isActive);
    void valueChanged(float value);
    void frameActionTriggered(float dt);
    void zoomCamera(float dt);

private:
    Qt3DInput::QMouseDevice     *m_mouseDevice;
    Qt3DInput::QKeyboardDevice  *m_keyboardDevice;
    Qt3DInput::QLogicalDevice   *m_logicalDevice;

    Qt3DInput::QAction          *m_keyUpAction;
    Qt3DInput::QAction          *m_leftButtonAction;
    Qt3DInput::QActionInput     *m_keyUpInput;
    Qt3DInput::QActionInput     *m_leftButtonInput;
    Qt3DInput::QAxis            *m_xAxis;
    Qt3DInput::QAxis            *m_yAxis;
    Qt3DInput::QAnalogAxisInput *m_mouseXInput;
    Qt3DInput::QAnalogAxisInput *m_mouseYInput;
    Qt3DInput::QAxis            *m_wheelYAxis;
    Qt3DInput::QAnalogAxisInput *m_wheelYInput;

    Qt3DLogic::QFrameAction     *m_frameAction;

    Qt3DRender::QCamera         *m_camera;
    float                       m_lookSpeed;
    float                       m_linearSpeed;

    bool                        m_leftButtonPressed;
    bool                        m_keyUpPressed;

    float                       m_dx;
    float                       m_dy;
};

#endif // CUSTOMCAMERACONTROLLER_H
