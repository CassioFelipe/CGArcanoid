#ifndef BLOCOS_H
#define BLOCOS_H

#include <QGLWidget>
#include <qopengl.h>
#include <QColor>
#include <vetor2d.h>
#include <QWidget>
#include <QtOpenGL>
#include <QDebug>

class Blocos
{
private:
    int ncol, nrow;
    float alt, larg, gap;
    float x, y;
    int blocs[1000][1000];
    void convert(int & xm, int & ym);

public:
    Blocos();
    Blocos(int _nc, int _nr, float _alt, float _larg);
    int colisao(Vetor2D *pos, float r);
    void draw();
};

#endif // BLOCOS_H
