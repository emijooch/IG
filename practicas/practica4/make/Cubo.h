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

#ifndef _CUBO_H
#define _CUBO_H

#include "Objeto3D.h"

#include <vector>

class Cubo:public Objeto3D{
	public:
    
    Cubo();
    
    Cubo(std::vector<int>cCaras, std::vector<float>cVertices, std::vector<float>cColores);
    
    Cubo(float distancia);
    
    void redimension(float distancia);
    
    
};

#endif
