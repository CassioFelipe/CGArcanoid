#include "vetor2d.h"

Vetor2D::Vetor2D()
{

}

Vetor2D::Vetor2D(double x_, double y_): x(x_), y(y_){}

void Vetor2D::somar(Vetor2D *a){
    x += a->getX();
    y += a->getY();
}

double Vetor2D::getX(){
    return x;
}

double Vetor2D::getY(){
    return y;
}

void Vetor2D::refletirVert(){
    x = -x;
}

void Vetor2D::refletirHori(){
    y = -y;
}
