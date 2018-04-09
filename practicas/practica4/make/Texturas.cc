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
#include "Texturas.h"
#include "Objeto3D.h"
#include <vector>
#include <cstdio>

//**************************************************************************
// Constructores de Texturas
//***************************************************************************


Texturas::Texturas(){
    
    amb ={ 0.0f,0.0f,0.0f,1.0f };
    dif ={ 0.1f,0.35f,0.1f,1.0f};
    spec ={0.45f,0.55f,0.45f,1.0f };
    shine = 32.0f ;

}

Texturas::Texturas(std::vector<float>amb, std::vector<float>dif, std::vector<float>spec, float shine){
    this->amb=amb;
    this->dif=dif;
    this->spec=spec;
    this->shine=shine;

}
void Texturas::enciende(){
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, &amb[0]);
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, &dif[0]);
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, &spec[0]);
    glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, &shine);
    //GLfloat emision[] = {0.3, 0.3, 0.3, 1.0};
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);
}

void Texturas::material(char tecla){
    float brillo=0;

    switch(tecla){
            case '1':
                //bronze
                this-> amb = {0.25f, 0.148f, 0.06475f, 1.0f  }; 
                this-> dif = {0.4f, 0.2368f, 0.1036f, 1.0f};
                this-> spec = {0.774597f, 0.458561f, 0.200621f, 1.0f };
                brillo=27.8974;
                break;
                
            case '2':
                //ruby
                this-> amb = { 0.1745f, 0.01175f, 0.01175f, 0.55f };
                this-> dif = { 0.61424f, 0.04136f, 0.04136f, 0.55f };
                this-> spec = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
                brillo=76.8f;
                break;
            case '3':
                //tin
                this-> amb = {0.105882f, 0.058824f, 0.113725f, 1.0f };
                this-> dif = { 0.427451f, 0.470588f, 0.541176f, 1.0f };
                this-> spec = { 0.333333f, 0.333333f, 0.521569f, 1.0f  };
                brillo=9.84615f;
                break;
                
    }      

}


