#ifndef VETOR2D_H
#define VETOR2D_H


class Vetor2D
{

private:
    double x, y;
public:
    static Vetor2D vertical, horizontal;

    Vetor2D();
    Vetor2D(double x, double y);
    Vetor2D normal();
    double angulo(Vetor2D v);
    double modulo();
    void refletir(double angle);
    void somar(Vetor2D *a);
    double getX();
    double getY();

};

#endif // VETOR2D_H
