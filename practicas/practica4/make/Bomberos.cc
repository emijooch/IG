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

#include "Objeto3D.h"
#include "Bomberos.h"
#include <vector>
#include <cstdio>
#include "Cubo.h"
#include "Revolucion.h"
#include "Cilindro.h"





Bomberos::Bomberos(){
    grado1 = 0;
    grado2 = 0;
    
    
    }

void Bomberos::setGrado(float grado1,float grado2, float grado3, float grado4, float grado5){
    this->grado1 = grado1;
    this->grado2 = grado2;
    this->grado3 = grado3;
    this->grado4 = grado4;
    this->grado5 = grado5;
    }

void Bomberos::setTecla(char tecla){
        teclaFun=tecla;
    }




void Bomberos::cuerpo(){
    glPushMatrix();
    glTranslatef(0,-0.75,0);
    glScalef(3,0.75,1);
    elcubo->draw(teclaFun);
    glPopMatrix();
}

void Bomberos::faros(){
    glPushMatrix();
    
    glRotatef(90, 0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    miCilindro->draw(teclaFun);
    glPopMatrix();
}





void Bomberos::eje(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glRotatef(90, 1.0,0.0,0.0);
    glScalef(0.1,1,0.1);
    miCilindro->draw(teclaFun);
    glPopMatrix();
}






void Bomberos::rueda(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glRotatef(90, 1.0,0.0,0.0);
    glScalef(0.6,0.2,0.6);
    miCilindro->draw(teclaFun);
    glPopMatrix();
}






/*-----------------------------*/

void Bomberos::cabeza(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glScalef(1,1,1);
    elcubo->draw(teclaFun);
    glPopMatrix();
}
void Bomberos::cristalDelantero(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(0.4,0.9,0.1);
    elcubo->draw(teclaFun);
    glPopMatrix();
}

void Bomberos::ventana(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glScalef(0.35,0.35,0.1);
    elcubo->draw(teclaFun);
    glPopMatrix();
}

void Bomberos::puerta(){
    glPushMatrix();
    //glTranslatef(0,45,0);
    glScalef(0.4,0.9,0.01);
    elcubo->draw(teclaFun);
    glPopMatrix();
}







/*----------------------------------*/


void Bomberos::cilindroGiratorio(){
    glPushMatrix();
    glTranslatef(0,-0.4,0.0);
    glScalef(1.0,0.4,1.0);
    miCilindro->draw(teclaFun);
    glPopMatrix();
}

void Bomberos::escaleraDos(){
    glPushMatrix();
    glTranslatef(1,0.5,0);
    glScalef(1,0.5,0.5);
    elcubo->draw(teclaFun);
    glPopMatrix();
}



void Bomberos::escaleraUno(){
    glPushMatrix();
    glTranslatef( 0.0+grado4, 0.0,0.0);
    glTranslatef(1.2,0.5,0);
    glScalef(1.2,0.4,0.4);
    elcubo->draw(teclaFun);
    glPopMatrix();
}

void Bomberos::dibujar(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(grado5, 0.0, 0.0);
    //cuerpo Unido Bomberos
        glPushMatrix();
            cuerpo();
                //Faros delanteros
                glPushMatrix();  
                    glTranslatef(3.0,-0.5,-0.70);
                        faros();
                glPopMatrix();
                glPushMatrix();  
                    glTranslatef(3.0,-0.5,0.70);
                    faros();
                glPopMatrix();
                    //Ruedas y Ejes
                    glPushMatrix();
                        glTranslatef(-1.5,-1.5, 0.0);
                        glRotatef(0+grado1,0.0, 0.0, 1.0);
                        eje();
                            glPushMatrix();
                            glTranslatef(0.0, 0.0, 1);
                            rueda();
                            glPopMatrix(); 
                            glPushMatrix();
                            glTranslatef(0.0, 0.0, -1);
                            rueda();
                            glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();  
                        glTranslatef(1.5,-1.5,0.0);
                        glRotatef(0+grado1,0.0, 0.0, 1.0);
                        eje();
                            glPushMatrix();
                            glTranslatef(0.0, 0.0, 1);
                            rueda();
                            glPopMatrix(); 
                            glPushMatrix();
                            glTranslatef(0.0, 0.0, -1);
                            rueda();
                            glPopMatrix();    
                    glPopMatrix();
                    //Cabeza delantera camion
                    glPushMatrix();
                        glTranslatef(1.75,1.0,0.0);
                        cabeza();
                            //Cristal delantero y todos los accesorios
                            glPushMatrix();
                                glTranslatef(1,0.5,0.0);
                                cristalDelantero();
                            glPopMatrix();
                            //ventanas Laterales
                            glPushMatrix();
                                glTranslatef(0.5,0.0,-1);
                                puerta();
                            glPopMatrix();
                            glPushMatrix();
                                glTranslatef(0.5,0.0,1);
                                puerta();
                            glPopMatrix();
                            glPushMatrix();
                                glTranslatef(-0.5,0.5,1);
                                ventana();
                            glPopMatrix();
                            glPushMatrix();
                                glTranslatef(-0.5,0.5,-1);
                                ventana();
                            glPopMatrix();
                            glPushMatrix();
                                glTranslatef(0.5,0.5,1);
                                ventana();
                            glPopMatrix();
                            glPushMatrix();
                                glTranslatef(0.5,0.5,-1);
                                ventana();
                            glPopMatrix();
                    glPopMatrix();
                   //Escaleras y cilindro de rotacion
                   glPushMatrix();
                        glTranslatef(-1.2,0.8,0.0);
                        glRotatef(grado2,0.0,1.0,0.0);
                        cilindroGiratorio();
                        //Escaleras
                        glPushMatrix();
                            glRotatef(35.0+grado3,0.0,0.0,1.0);                   
                            escaleraDos();
                            escaleraUno();
                        glPopMatrix();      
                    glPopMatrix();
            glPopMatrix();
        glPopMatrix();  
    glPopMatrix();
}

