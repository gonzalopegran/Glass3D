#include "customcameracontroller.h"


//#######################
//###                 ###
//###   CONSTRUCTOR   ###
//###                 ###
//#######################

CustomCameraController::CustomCameraController(Qt3DCore::QNode *parent):
    Qt3DCore::QEntity(parent)
{
    m_leftButtonPressed = false;
    m_keyUpPressed      = false;
    m_dx                = 0;
    m_dy                = 0;
    m_lookSpeed         = -100.0;
    m_linearSpeed       = 15.0;
    m_camera            = nullptr;

    m_mouseDevice       = new Qt3DInput::QMouseDevice(this);
    m_keyboardDevice    = new Qt3DInput::QKeyboardDevice(this);
    m_logicalDevice     = new Qt3DInput::QLogicalDevice(this);

    m_keyUpAction       = new Qt3DInput::QAction(this);
    m_leftButtonAction  = new Qt3DInput::QAction(this);
    m_keyUpInput        = new Qt3DInput::QActionInput(this);
    m_leftButtonInput   = new Qt3DInput::QActionInput(this);
    m_xAxis             = new Qt3DInput::QAxis(this);
    m_yAxis             = new Qt3DInput::QAxis(this);
    m_mouseXInput       = new Qt3DInput::QAnalogAxisInput(this);
    m_mouseYInput       = new Qt3DInput::QAnalogAxisInput(this);

    // prueba
    m_wheelYAxis        = new Qt3DInput::QAxis(this);
    m_wheelYInput       = new Qt3DInput::QAnalogAxisInput(this);
    // prueba

    m_frameAction       = new Qt3DLogic::QFrameAction(this);

    // Teclado: Flecha Arriba
    m_keyUpInput->setButtons(QVector<int>() << Qt::Key_Up);
    m_keyUpInput->setSourceDevice(m_keyboardDevice);
    m_keyUpAction->addInput(m_keyUpInput);
    m_keyUpAction->setObjectName("Key_Up");

    // Click IZQ mouse
    m_leftButtonInput->setButtons(QVector<int>() << Qt::LeftButton);
    m_leftButtonInput->setSourceDevice(m_mouseDevice);
    m_leftButtonAction->addInput(m_leftButtonInput);
    m_leftButtonAction->setObjectName("Left_Button");

    // WHEEL: EJE Y
    m_wheelYInput->setAxis(Qt3DInput::QMouseDevice::WheelY);
    m_wheelYInput->setSourceDevice(m_mouseDevice);
    m_wheelYAxis->addInput(m_wheelYInput);
    m_wheelYAxis->setObjectName("Wheel_Y");

    // Movimiento mouse: Eje X
    m_mouseXInput->setAxis(Qt3DInput::QMouseDevice::X);
    m_mouseXInput->setSourceDevice(m_mouseDevice);
    m_xAxis->addInput(m_mouseXInput);
    m_xAxis->setObjectName("Axis_X");

    // Movimiento mouse: Eje Y
    m_mouseYInput->setAxis(Qt3DInput::QMouseDevice::Y);
    m_mouseYInput->setSourceDevice(m_mouseDevice);
    m_yAxis->addInput(m_mouseYInput);
    m_yAxis->setObjectName("Axis_Y");


    m_logicalDevice->addAction(m_keyUpAction);
    m_logicalDevice->addAction(m_leftButtonAction);
    m_logicalDevice->addAxis(m_xAxis);
    m_logicalDevice->addAxis(m_yAxis);
    m_logicalDevice->addAxis(m_wheelYAxis);

    connect(m_keyUpAction,      SIGNAL(activeChanged(bool)), this, SLOT(activeChanged(bool)));
    connect(m_leftButtonAction, SIGNAL(activeChanged(bool)), this, SLOT(activeChanged(bool)));
    connect(m_xAxis,            SIGNAL(valueChanged(float)), this, SLOT(valueChanged(float)));
    connect(m_yAxis,            SIGNAL(valueChanged(float)), this, SLOT(valueChanged(float)));
    connect(m_wheelYAxis,       SIGNAL(valueChanged(float)), this, SLOT(valueChanged(float)));

    connect(m_frameAction, SIGNAL(triggered(float)), this, SLOT(frameActionTriggered(float)));
}


//#############################
//###                       ###
//###   GETTERS + SETTERS   ###
//###                       ###
//#############################

Qt3DRender::QCamera *CustomCameraController::camera() const             { return m_camera; }
void CustomCameraController::setCamera(Qt3DRender::QCamera *newCamera)  { m_camera = newCamera; }
float CustomCameraController::lookSpeed() const                         { return m_lookSpeed; }
void CustomCameraController::setLookSpeed(float newLookSpeed)           { m_lookSpeed = newLookSpeed; }
float CustomCameraController::linearSpeed() const                       { return m_linearSpeed; }
void CustomCameraController::setLinearSpeed(float newLinearSpeed)       { m_linearSpeed = newLinearSpeed; }


//#####################
//###               ###
//###   FUNCTIONS   ###
//###               ###
//#####################

void CustomCameraController::activeChanged(bool isActive)
{
    if (sender()->objectName() == "Key_Up") {
        m_keyUpPressed = isActive;
    } else if (sender()->objectName() == "Left_Button"){
        m_leftButtonPressed = isActive;
    }
}

void CustomCameraController::valueChanged(float value)
{
    if (sender()->objectName() == "Axis_X") {
        m_dx = value;
    } else if (sender()->objectName() == "Axis_Y"){
        m_dy = value;
    } else if (sender()->objectName() == "Wheel_Y") {
        zoomCamera(value);
    }
}

void CustomCameraController::frameActionTriggered(float dt)
{
    if (m_camera == 0) return;

    if (m_leftButtonPressed == true) {
        m_camera->panAboutViewCenter(m_dx * m_lookSpeed * dt);
        m_camera->tiltAboutViewCenter(m_dy * m_lookSpeed * dt);
    }

    if (m_keyUpPressed == true) {
        m_camera->rollAboutViewCenter(0.5 * m_lookSpeed * dt);
    }
}

void CustomCameraController::zoomCamera(float dt)
{
    if (m_camera == nullptr) {
        return;
    }

    m_camera->translate(QVector3D(0, 0, dt * m_linearSpeed), m_camera->TranslateViewCenter);
}



