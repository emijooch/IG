//**************************************************************************
// Práctica 3
//
//  Emilio Jose Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>    
//#include <GLUT/glut.h>        
#include "Tetraedro.h"
#include "Objeto3D.h"
#include <vector>
#include <cstdio>


//**************************************************************************
// Constructores de Tetraedro
//***************************************************************************

//constructor con inicializacion a 0

Tetraedro::Tetraedro(){
    
    this->caras.resize(0);
    this->vertices.resize(0);
    this->colores.resize(0);
    
    
}

//constructor por parametros

Tetraedro::Tetraedro(std::vector<int>tCaras, std::vector<float>tVertices, std::vector<float>tColores){
    if(tCaras.size() == 12 && tVertices.size() == 12 && tColores.size() == 12){
        this->caras = tCaras ;
        this->vertices = tVertices;
        this->colores = tColores;
       
        
    }
    else Tetraedro();
    
}


//constructor con parametro de distancia

Tetraedro::Tetraedro(float distancia){
    if (distancia != 0) {
        this->vertices.resize(12);
        this->caras.resize(12);
        this->colores.resize(12);
        this->vertices={0,distancia,0, 0, 0, distancia, distancia, 0, -distancia, -distancia, 0,-distancia};
        this->caras = {1,2,0,3,1,0,2,3,0,3,2,1};
        this->colores = {255,0,0,255,0,0,255,0,0,255,0,0};
    }else Tetraedro();
}

