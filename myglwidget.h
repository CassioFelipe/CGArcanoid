#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QDebug>
#include <math.h>
#include <vetor2d.h>
#include <QTimer>

const float DEG2RAD = 3.14159/180;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    float z;
    Vetor2D *posCirc, *direc;
    QTimer * crono;

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);

//Drawing Functions
    void draw();
    void drawCircle(float r, int seg);

    void keyPressEvent(QKeyEvent * event);
public:
    void loop();
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

signals:

public slots:
};

#endif // MYGLWIDGET_H
