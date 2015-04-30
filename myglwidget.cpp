#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{
    z = 0;
}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::paintGL(){
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawCircle(0,0,0.05,20);
        glTranslatef(z,0,0);
        draw();

}

void MyGLWidget::initializeGL(){

}

void MyGLWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void MyGLWidget::draw(){
    qglColor(Qt::white);

    glBegin(GL_QUADS);
        //glNormal3f(0,0,1);
        glVertex3f(0.0f, -0.86f, 0.0f);
        glVertex3f(0.3f, -0.86f, 0.0f);
        glVertex3f(0.3f, -0.96f, 0.0f);
        glVertex3f(0.0f, -0.96f, 0.0f);
    glEnd();


    glFlush();
}

void MyGLWidget::keyPressEvent(QKeyEvent * event){

    if(event->key() == Qt::Key_D && z < 0.7){
        z+=0.05;
    }else if(event->key() == Qt::Key_A && z > -1){
        z-=0.05;
    }

    update();
}

void MyGLWidget::drawCircle(int x, int y, float r, int seg){
    qglColor(Qt::blue);
        glBegin( GL_TRIANGLE_FAN);
           glVertex2f(x,y);
           int n;
           for(n = 0; n <= seg; ++n){
               float const t = 2*M_PI*(float)n/(float)seg;
               glVertex2f(x + sin(t)*r, y + cos(t)*r);
           }
        glEnd();

        glFlush();
}

