//**************************************************************************
// Práctica 4
//
//  Emilio Jose Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>    //macOX
//#include <GLUT/glut.h>        //macOX
#include "Iluminacion.h"
#include "Objeto3D.h"
#include <vector>
#include <cstdio>
#include "math.h"
#include <iostream>

//**************************************************************************
// Constructores de Cubo
//***************************************************************************
void Iluminacion::enciendeFocos(){
    GLfloat posicion[] = { 3.0,-0.5,0.7, 1.0 };
    GLfloat direccion[] = {7,-1.0,0.0 };
    GLfloat caf[]= { 0.0, 0.0, 0.0, 1.0 };// color ambiental de la fuente 
    GLfloat cdf[]= { 1.0, 1.0, 1.0, 1.0 }; // color difuso de la fuente 
    GLfloat csf[] = { 1.0, 1.0, 1.0, 1.0 }; // color especular de la fuente
    GLfloat val= 90;
    GLfloat spot_exponent=9999;
    glEnable(GL_LIGHT5);

    
    GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 0.2 }; 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    
    glLightfv( GL_LIGHT5 , GL_AMBIENT, &caf[0] ); // hace SiA := (ra, ga, ba) 
    glLightfv( GL_LIGHT5 , GL_DIFFUSE, &cdf[0] ); // hace SiD := (rd, gd, bd) 
    glLightfv( GL_LIGHT5 , GL_SPECULAR, &csf[0] ); // hace SiS := (rs, gs, bs)  
    glLightfv( GL_LIGHT5 , GL_POSITION, &posicion[0] );  
   /* glLightfv( GL_LIGHT5 ,  GL_SPOT_DIRECTION, &direccion[0] );
    glLightf(GL_LIGHT5,GL_SPOT_EXPONENT,spot_exponent);
    glLightf(GL_LIGHT5,GL_SPOT_CUTOFF,val);
    glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE ); 
    glutPostRedisplay();*/
}




void Iluminacion::enciende(int foco){
    glEnable(GL_LIGHT0+foco);

    GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 0.2 }; 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightfv( GL_LIGHT0+foco , GL_AMBIENT, &caf[0] ); // hace SiA := (ra, ga, ba) 
    glLightfv( GL_LIGHT0+foco , GL_DIFFUSE, &cdf[0] ); // hace SiD := (rd, gd, bd) 
    glLightfv( GL_LIGHT0+foco , GL_SPECULAR, &csf[0] ); // hace SiS := (rs, gs, bs)  
    glLightfv( GL_LIGHT0+foco , GL_POSITION, &dirf[0] );  
    glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE ); 
}
void Iluminacion::apaga(int foco){
    glDisable(GL_LIGHT0+foco);
}

Iluminacion::Iluminacion(){
    caf= { 0.0, 0.0, 0.0, 1.0 };// color ambiental de la fuente 
    cdf= { 1.0, 1.0, 1.0, 1.0 }; // color difuso de la fuente 
    csf = { 1.0, 1.0, 1.0, 1.0 }; // color especular de la fuente
    dirf = { 0.0, 0.0, 20.0, 1.0 };
    foco = 0;
}

Iluminacion::Iluminacion(std::vector<float>lcaf, std::vector<float>lcdf, std::vector<float>lcsf, std::vector<float>ldirf, int lfoco){
    this->caf=lcaf;
    this->cdf=lcdf;
    this->csf=lcsf;
    this->dirf=ldirf;
    this->foco=lfoco;
}

void Iluminacion::rotacionCamara(int positionNext, int foco){
    

    double alpha=(2.0*M_PI)/positionNext;
    float pX = cos(alpha)*dirf[0]+sin(alpha)*dirf[2]; 
    float pZ = (-sin(alpha)*dirf[0])+cos(alpha)*dirf[2];


    this->dirf[0]=pX;
    this->dirf[2]=pZ;
    glMatrixMode( GL_MODELVIEW ) ;
      glPushMatrix() ;
       glLoadIdentity() ; // hacer M = Identidad  
       //glMultMatrix( A ) ; // A podría ser Ide,V o VN  // rotación a grados en torno a eje Y 
       // rotación b grados en torno al eje X 
       //glRotatef( b, -1.0, 0.0, 0.0 ) ;  // luz paralela eje Z+ 
       glLightfv( GL_LIGHT0+foco, GL_POSITION, &dirf[0]); 
       glPopMatrix() ;
    std::cout<<"despues de rotar x "<<dirf[0]<<std::endl;
    std::cout<<"despues de rotar z "<<dirf[2]<<std::endl;

}




void Iluminacion::rotacion(){
    GLfloat posicion[] = { -3.0, -0.5, 0.7, 0.0 };
     glMatrixMode( GL_MODELVIEW ) ;
      glPushMatrix() ;
       glLoadIdentity() ; // hacer M = Identidad  
       //glMultMatrix( A ) ; // A podría ser Ide,V o VN  // rotación a grados en torno a eje Y 
       // rotación b grados en torno al eje X 
       glTranslatef(3.0,-0.5,-0.70);
       glLightfv( GL_LIGHT5, GL_POSITION, &posicion[0]); 
       glPopMatrix();
       glutPostRedisplay(); 
}
