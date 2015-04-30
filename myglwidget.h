#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QDebug>
#include <math.h>

const float DEG2RAD = 3.14159/180;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    float z;

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);

//Drawing Functions
    void draw();
    void drawCircle(int x, int y, float r, int seg);

    void keyPressEvent(QKeyEvent * event);
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

signals:

public slots:
};

#endif // MYGLWIDGET_H
