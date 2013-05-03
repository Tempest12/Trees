#ifndef GLPANEL_H
#define GLPANEL_H

#include <QGLWidget>
#include <vector>
#include <QTimer>
#include <cmath>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QCursor>
#include "Tree.hpp"
#include "Vector3f.hpp"

class glPanel : public QGLWidget
{
    Q_OBJECT
public:
    //constructor
    explicit glPanel(QWidget *parent = 0);
    ~glPanel();

    //public functions
    void initializeGL();
    void paintGL();
    void resizeGL(int x, int h);
    void update();
    //GLuint LoadTextureRAW( const char * filename, int wrap );

    //public variables
    QTimer* timer;

    Tree tree;

    bool mouseLeftDown = false;
    
    int oldMouseX;
    int oldMouseY;

    float angleX = 0.0f;
    float angleY = 15.0f;

    float angleDelta = 1.05f;

    Vector3f cameraPosition;


protected:

     void mousePressEvent(QMouseEvent* event);
     void mouseReleaseEvent(QMouseEvent* event);
     void mouseMoveEvent(QMouseEvent* event);
     void wheelEvent(QWheelEvent* event);

     void keyPressEvent(QKeyEvent* event);

signals:

    //void drawAttractionPoints(int value);


public slots:
    void initialize();

    void saveEnvelope(void);
    void loadEnvelope(void);

    void spawnAttractionPoints(void);
    void clearAttractionPoints(void);

    void drawAttractionPoints(int value);
};


namespace glPanelUtil
{
    void drawCircle(float radius, float segments);
}
#endif // GLPANEL_H
