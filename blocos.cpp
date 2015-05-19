#include "blocos.h"
#include <string>

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
    /*for(int i = 0; i < ncol; i++){
        for(int j = 0; j < nrow; j++){
            blocs[i][j] = 1;
        }
    }
    blocs[4][8] = -1;
    blocs[5][9] = 2;*/

    LoadStage("1");
}

void Blocos::draw(){
    glColor3f(0,0,1);
    for(int i = 0; i < ncol; i++){
        glLoadIdentity();
        glTranslatef(i*larg + i*gap, 0,0);
        for(int j = 0; j < nrow; j++){
            if(blocs[i][j] != 0){
                if(blocs [i][j] == -1){
                    glColor3f(1,0,0);
                }else if(blocs [i][j] == 2){
                    glColor3f(0,1,0);
                }else{
                    glColor3f(0,0,1);
                }

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
    //qDebug() << pos->getX() << ", " << pos->getY();

/*
    convert(pos->getX() + r, pos->getY(), xm, ym);
    if(xm >= 0 && xm < ncol && ym >= 0 && ym < nrow){
        if(blocs[xm][ym]){
            blocs[xm][ym]--;
            retorno += 2;
        }
    }

    convert(pos->getX() - r, pos->getY(), xm, ym);
    if(xm >= 0 && xm < ncol && ym >= 0 && ym < nrow){
        if(blocs[xm][ym]){
            blocs[xm][ym]--;
            retorno += 2;
        }
    }*/
    return 0;
}

bool Blocos::colisaoHor(Vetor2D *pos, Vetor2D *dir, float r){
    int xm, ym, d = (dir->getY() < 0)?-1:1;
    convert(pos->getX(), pos->getY() + r*d, xm, ym);
    if(xm >= 0 && xm < ncol && ym >= 0 && ym < nrow){
        if(blocs[xm][ym]){

            if(blocs[xm][ym] > 0){
            blocs[xm][ym]--;
            }

            return true;
        }
    }
    return false;
}

bool Blocos::colisaoVer(Vetor2D *pos, Vetor2D *dir, float r){
    int xm, ym, d = (dir->getX() < 0)?-1:1;
    convert(pos->getX() + r*d, pos->getY() , xm, ym);
    if(xm >= 0 && xm < ncol && ym >= 0 && ym < nrow){
        if(blocs[xm][ym]){
            if(blocs[xm][ym] > 0){
            blocs[xm][ym]--;}

            return true;
        }
    }
    return false;
}

void Blocos::convert(double xf, double yf, int & xm, int & ym){
    //qDebug() << "xf antes: " << xf;
    xf += 1;
    //qDebug() << "xf + 1 = " << xf;
    xm = (int) (xf / (larg + gap));
    //qDebug() << "alt " << alt << " gap: " << gap << "alt + gap " << alt + gap << "xf / alt + gap " << xf / (alt + gap);


    yf -= 1;
    ym = (int) (yf / -(alt + gap));
    //qDebug() << "Converter " << xm << " " << ym;
}

void Blocos::LoadStage(QString StageNumber){
   QString Filename, line;

   Filename = ":/Stage"+ StageNumber +".txt";

   qDebug() << Filename;

   QFile myfile(Filename);


   if(myfile.open(QFile::ReadOnly)){
    QTextStream in(&myfile);
    in.setCodec("UTF-8");

       for(int i=0;i<10;i++){
           line = in.readLine();

           for(int j = 0; j < 13; j++){
               if(j >= line.size()){
                   qDebug() << "numero de col insuficiente";
                    break;
               }
               int val;
               if(line.at(j).digitValue() == 9){
                   val = -1;
               }else{
                   val = line.at(j).digitValue();
               }
               blocs[j][i] = val;

           }
       }

   }else{
       qDebug() << "could not open file";
   }
}
