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

//**************************************************************************
// Constructores de Cubo
//***************************************************************************

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
    dirf = { 0.0, 50.0, 0.0, 1.0 };
    foco = 0;
}

Iluminacion::Iluminacion(std::vector<float>lcaf, std::vector<float>lcdf, std::vector<float>lcsf, std::vector<float>ldirf, int lfoco){
    this->caf=lcaf;
    this->cdf=lcdf;
    this->csf=lcsf;
    this->dirf=ldirf;
    this->foco=lfoco;
}

void Iluminacion::rotacionCamara(){
  for (int j = 0; j < (particion-1); j++){

        //Generamos todos los vertices
        for (unsigned int i = 0; i < revolucionVertices.size(); i+=3){

            double alpha=(2.0*M_PI)/particion;

            float pX=cos() 
            float pZ=
            vertices.push_back(cos(alpha*(j+1))*revolucionVertices[i]-sin(alpha*(j+1))*revolucionVertices[i+1]);
            vertices.push_back(sin(alpha*(j+1))*revolucionVertices[i]+cos(alpha*(j+1))*revolucionVertices[i+1]);
            vertices.push_back(revolucionVertices[i+2]);
}

void Iluminacion::rotacion(int eje, int foco){
    

    



     glMatrixMode( GL_MODELVIEW ) ;
      glPushMatrix() ;
       glLoadIdentity() ; // hacer M = Identidad  
       //glMultMatrix( A ) ; // A podría ser Ide,V o VN  // rotación a grados en torno a eje Y 
       glRotatef( eje, 0.0, 1.0, 0.0 ) ;  // rotación b grados en torno al eje X 
       //glRotatef( b, -1.0, 0.0, 0.0 ) ;  // luz paralela eje Z+ 
       glLightfv( GL_LIGHT0+foco, GL_POSITION, &dirf[0]); 
       glPopMatrix() ; 
}
