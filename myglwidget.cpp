#include "myglwidget.h"

#define RCIRC 0.05f
#define pTop -0.86f

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{
    z = 0;
    crono = new QTimer(this);
    connect(crono, SIGNAL(timeout()), this, SLOT(loop()));
    crono->start(33);
    posCirc = new Vetor2D(0.01, 0);
    direc = new Vetor2D(0.01, 0.02);

}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::paintGL(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(posCirc->getX(), posCirc->getY(), 0.0);
    drawCircle(RCIRC, 8);
    glLoadIdentity();
    fase1->draw();
    glLoadIdentity();
    glTranslatef(z,0,0);
    draw();

}

void MyGLWidget::initializeGL(){
    fase1 = new Blocos(10, 10, 0.08 , 0.15);
}

void MyGLWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void MyGLWidget::draw(){
    qglColor(Qt::white);

    //Plataforma
    glBegin(GL_QUADS);
        //glNormal3f(0,0,1);
        glVertex3f(0.0f, pTop, 0.0f);
        glVertex3f(0.3f, pTop, 0.0f);
        glVertex3f(0.3f, pTop - 0.1, 0.0f);
        glVertex3f(0.0f, pTop - 0.1, 0.0f);
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

void MyGLWidget::drawCircle(float r, int seg){
    int x = posCirc->getX(), y = posCirc->getY();

    qglColor(Qt::red);
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

void MyGLWidget::loop(){

    posCirc->somar(direc);
    if(posCirc->getX() + RCIRC > 1 || posCirc->getX() - RCIRC < -1){
        direc->refletirVert();
    }
    if(posCirc->getY() + RCIRC > 1){
        direc->refletirHori();
    }

    if(posCirc->getY() <= pTop && posCirc->getX() > z && posCirc->getX() < z + 0.3){
        direc->refletirHori();
    }

    if(posCirc->getY() - RCIRC < -1){
        //morreu
    }

    if(fase1->colisaoVer(posCirc, direc, RCIRC)){
        direc->refletirVert();

    }

    if(fase1->colisaoHor(posCirc, direc, RCIRC)){
        direc->refletirHori();
    }
    //direc->somar(new Vetor2D(-0.01, -0.01));
    //qDebug() << "Debug is on the table\n";
    update();
}


