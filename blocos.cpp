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
    for(int i = 0; i < ncol; i++){
        for(int j = 0; j < nrow; j++){
            blocs[i][j] = 1;
        }
    }
    blocs[2][5] = 0;
    qDebug() << ncol << " " << nrow << "\n";
}

void Blocos::draw(){
    glColor3f(0,0,1);
    for(int i = 0; i < ncol; i++){
        for(int j = 0; j < nrow; j++){

            qDebug() << "Aqui: " << i*larg + i*gap << " " << j*alt + j*gap << "\n";
            if(blocs[i][j] > 0){
                glLoadIdentity();
                glTranslatef(i*larg + i*gap, j*alt + j*gap, 0.0);
                glBegin(GL_QUADS);
                   glVertex2f(x,y);
                   glVertex2f(x,y+alt);
                   glVertex2f(x+larg, y+alt);
                   glVertex2f(x+larg, y);
                glEnd();
            }
        }
    }
}
