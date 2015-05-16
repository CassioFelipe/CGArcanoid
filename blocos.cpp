#include "blocos.h"

Blocos::Blocos()
{

}

Blocos::Blocos(int _nc, int _nr, float _alt, float _larg){
    ncol = _nc;
    nrow = _nr;
    alt = _alt;
    larg = _larg;
    gap = 0.01;
    x = gap - 1;
    y = 1 - gap;
    for(int i = 0; i < ncol; i++){
        for(int j = 0; j < nrow; j++){
            blocs[i][j] = 1;
        }
    }
    blocs[2][5] = 0;
}

void Blocos::draw(){
    glColor3f(0,0,1);
    for(int i = 0; i < ncol; i++){
        glLoadIdentity();
        glTranslatef(i*larg + i*gap, 0,0);
        for(int j = 0; j < nrow; j++){
            if(blocs[i][j] > 0){
                glBegin(GL_QUADS);
                   glVertex2f(x,y);
                   glVertex2f(x,y-alt);
                   glVertex2f(x+larg, y-alt);
                   glVertex2f(x+larg, y);
                glEnd();
            }
            glTranslatef(0, -alt - gap, 0.0);
        }
    }
}


int Blocos::colisao(Vetor2D * pos, float r){
    qDebug() << pos->getX() << ", " << pos->getY();
    int xm, ym;
    convert(pos->getX(), pos->getY(), xm, ym);
    if(xm >= 0 && xm < ncol && ym >= 0 && ym < nrow){
        if(blocs[xm][ym]){
            blocs[xm][ym]--;
            return 1;
        }
    }
    return 0;
}

void Blocos::convert(double xf, double yf, int & xm, int & ym){
    qDebug() << "xf antes: " << xf;
    xf += 1;
    qDebug() << "xf + 1 = " << xf;
    xm = (int) (xf / (larg + gap));
    qDebug() << "alt " << alt << " gap: " << gap << "alt + gap " << alt + gap << "xf / alt + gap " << xf / (alt + gap);


    yf -= 1;
    ym = (int) (yf / -(alt + gap));
    qDebug() << "Converter " << xm << " " << ym;
}
