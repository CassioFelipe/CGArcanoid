#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGLWidget * w = new MyGLWidget;
    w->show();
    w->setWindowTitle("Arcanoid");


    return a.exec();
}
