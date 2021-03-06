//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

#include <GL/gl.h>
#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>    //macOX
//#include <GLUT/glut.h>        //macOX
#include "Cubo.h"
#include "Objeto3D.h"
#include <vector>
#include <cstdio>

//**************************************************************************
// Constructores de Cubo
//***************************************************************************

//Constructor de inicializacion a 0

Cubo::Cubo(){
    this->vertices.resize(0);
    this->caras.resize(0);
    this->colores.resize(0);
    this->tecla = '0';
    this->valido= false;
}

//Constructor por parametros

Cubo::Cubo(std::vector<int>cCaras, std::vector<float>cVertices, std::vector<float>cColores){
    if(cVertices.size()== 24 && cCaras.size()== 36 && cColores.size()== 24){
        this->vertices = cVertices;
        this->caras = cCaras;
        this->colores = cColores;
        this->tecla = '0';
        this->valido = true;
    }
    else Cubo();
}

//Constructor con parametro distancia

Cubo::Cubo(float distancia){
    if (distancia != 0) {
        this->vertices.resize(24);
        
        this->vertices={-distancia,-distancia,distancia, distancia, -distancia, distancia, distancia, -distancia,-distancia,-distancia, -distancia ,-distancia,-distancia, distancia, distancia, distancia, distancia, distancia, distancia, distancia, -distancia, -distancia, distancia,-distancia};
    
        this->caras = {0,1,5,5,4,0,1,2,6,6,5,1,2,3,7,7,6,2,3,0,4,4,7,3,7,4,5,5,6,7,2,1,0,0,3,2};
        this->colores = { 255 ,0, 0, 255 ,0, 0, 255 ,0, 0, 255 ,0, 0, 255 ,0, 0, 255 ,0, 0, 255 ,0, 0, 255 ,0, 0};
    }else Cubo();
}

//**************************************************************************
// Funcion cambio de perspectiva segun tecla pulsada
//***************************************************************************


void Cubo::setTecla(unsigned char newTecla){
    this->tecla= newTecla;
}
unsigned char Cubo::getTecla(){
    return this->tecla;
}

//**************************************************************************
// Funcion booleana para comprobar los parametros del cubo
//***************************************************************************


void Cubo::setValido(bool cvalido){
    this->valido = cvalido;
}

bool Cubo::getValido(){
    return this->valido;
}


//**************************************************************************
// Funcion de dibujado del cubo
//***************************************************************************


void Cubo::dibuja(){
    if (valido) Objeto3D::draw();
}
