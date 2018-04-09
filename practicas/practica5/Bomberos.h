//**************************************************************************
// Práctica 4
//
//  Emilio Jose Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************
#ifdef __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <GLUT/glut.h>
        #include <OpenGL/OpenGL.h>
    #endif
#elif defined _WIN32 || defined _WIN64
    #include <GL\glut.h>
#endif 

#ifndef _BOMBEROS_H
#define _BOMBEROS_H


#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <iostream>
#include "escena.h"
#include <vector>
#include <cstdio>
#include "ply.h"
#include "vertex.h"
#include "Objeto3D.h"
#include "file_ply_stl.h"
#include "Revolucion.h"
#include "Cilindro.h"
#include "Iluminacion.h"
#include "Texturas.h"




class Bomberos{
	private:
    float grado1 ;
    float grado2 ;
    float grado3 ;
    float grado4 ;
    float grado5 ;
    float grado8;
    float teclaFun;
    

    Cubo* elcubo = new Cubo(1);
    Cilindro* miCilindro = new Cilindro();
    Ply* miPly = new Ply();
    //std::vector<float> v = miCilindro->getVertices();
    //Revolucion* ciRevolucion= new Revolucion(v);
    



    public:
    
    Bomberos();

    void setGrado(float grado1,float grado2, float grado3, float grado4, float grado5, float grado8);
    
    void setTecla(char tecla);

    void suelo();
    void cuerpo();
    void faros();
    void eje();
    void rueda();
    void cabeza();
    void cristalDelantero();
    void ventana();
    void puerta();
    void cilindroGiratorio();
    void escaleraUno();
    void escaleraDos();
    void dibujar();
    void esferaSuelo();

    
    
    
    
};

#endif
