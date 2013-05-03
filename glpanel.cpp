#include "glpanel.h"
#include <GL/glut.h>
#include <math.h>

#include <iostream>
#include <string>

#include "MathLib.hpp"
#include "Config.hpp"


glPanel::glPanel(QWidget *parent) : QGLWidget(parent)
{
    //timer setup
    timer = new QTimer(this);
    timer->start(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    this->cameraPosition = Vector3f(Config::convertSettingToFloat("camera", "position_x"),
                                    Config::convertSettingToFloat("camera", "position_y"),
                                    Config::convertSettingToFloat("camera", "position_z"));
}

void glPanel::initializeGL()
{
    //set background color
    glClearColor(0.0f, 0.05f, 0.15f, 1.0f);
    //setup opengl flags
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LESS);
    //glAlphaFunc(GL_GREATER, 0.1f);
    //glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    //glDisable(GL_COLOR_MATERIAL);
    qDebug() << glGetError();




    //glutInit(0, );
}

//draws the scene
void glPanel::paintGL()
{
    //clear to backgrond color and clear depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //clear matrix stack
    glLoadIdentity();
    //set camera <pos>, <look at pos>, <up>
    gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, 0, 0, 0, 0.0, 1.0, 0.0);

    glRotatef(angleX, 0.0f, 1.0f, 0.0f);
    //glRotatef(angleY, 1.0f, 0.0f, 0.0f);

    glColor4f(0.10f, 0.50f, 0.10f, 1.0f);

    //Draw the Ground:
    glBegin(GL_QUADS);

    glVertex3f(25.0f, -0.01f, 25.0f);
    glVertex3f(-25.0f, -0.01f, 25.0f);
    glVertex3f(-25.0f, -0.01f, -25.0f);
    glVertex3f(25.0f, -0.01f, -25.0f);

    glEnd();

    //glPanelUtil::drawCircle(2.5f, 25);

    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);

    this->tree.draw();
}

void glPanel::resizeGL(int width, int height){
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, width/height, 1, 200);
    glMatrixMode(GL_MODELVIEW);
}

/*
 * This function is called via qtimer and contains all particle system updates as well as repainting openGL
 */
void glPanel::update(){
    //System updates

    //openGL repaint
    paintGL();

}

//reset
void glPanel::initialize(){

}

void glPanel::saveEnvelope(void)
{
    tree.envelope.save();
}

void glPanel::loadEnvelope(void)
{
    std::string fileName = QFileDialog::getOpenFileName(this).toStdString();
    //tree.envelope.loadEnvelope(QFileDialog::getOpenFileName(this, ));
}

void glPanel::spawnAttractionPoints(void)
{
   tree.spawnAttractionPoints();
}

void glPanel::clearAttractionPoints(void)
{
    std::cout << "Clear" << std::endl;
}

void glPanel::drawAttractionPoints(int value)
{
    //Value 2 is checked or "ON"
    switch(value)
    {
        case 0:
            tree.drawAttractionPoints = false;
            break;

        case 2: 
            tree.drawAttractionPoints = true;
            break;

        default:
            std::cout << "Undefined behaviout for a check box." << std::endl;
            break;

    }

}

float xDelta = 5.0f;
float yDelta = 3.0f;

void glPanel::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
        case Qt::Key_A:
            angleX -= xDelta;
            break;

        case Qt::Key_Right:
        case Qt::Key_D:
            angleX += xDelta;
            break;

        case Qt::Key_Up:
        case Qt::Key_W:
            cameraPosition.y += Config::convertSettingToFloat("camera", "zoom_factor");
            break;

        case Qt::Key_Down:
        case Qt::Key_S:
            cameraPosition.y -= Config::convertSettingToFloat("camera", "zoom_factor");
            if(cameraPosition.y < 0)
            {
                cameraPosition.y = 0;
            }
            break;

        case Qt::Key_Space:
            tree.update();
            break;
    }
}

void glPanel::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
         oldMouseX = event->x();
         oldMouseY = event->y();
    }
}

void glPanel::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        //std::cout << "Move Left Up" << std::endl;
    }
}

void glPanel::mouseMoveEvent(QMouseEvent* event)
{
    angleX += (event->x() - oldMouseX) * 0.45f;
    //angleY -= (event->y() - oldMouseY) * 0.50f;



    oldMouseX = event->x();
    oldMouseY = event->y();

    if(angleY < 0.0f)
    {
        angleY = 0.0f;
    }
    else if(angleY > 180.f)
    {
        angleY = 180.0f;
    }
}

void glPanel::wheelEvent(QWheelEvent* event)
{
    if(event->angleDelta().y() > 0)
    {
        cameraPosition.z += Config::convertSettingToFloat("camera", "zoom_factor");
    }
    else
    {
        cameraPosition.z -= Config::convertSettingToFloat("camera", "zoom_factor");
    }

}

glPanel::~glPanel()
{
    return;
}

void glPanelUtil::drawCircle(float radius, float segments)
{
    //std::cout << "Drawing Circle" << std::endl;

    float delta = (2.0 * MathLib::PI) / segments;

    float deltaTan = tanf(delta);
    float deltaRadius = cosf(delta);

    float x = radius;
    float z = 0.0f;

    float tx = 0.0f;
    float tz = 0.0f;

    glBegin(GL_LINE_LOOP);
    for(int index = 0; index < segments; index++)
    {
        glVertex3f(x, 0.0f, z);

        tx = -z;
        tz = x;

        x += tx * deltaTan;
        z += tz * deltaTan;

        x *= deltaRadius;
        z *= deltaRadius;
    }
    glEnd();
}
