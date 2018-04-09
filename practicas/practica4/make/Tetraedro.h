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
#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H

#include "Objeto3D.h"
#include <vector>

class Tetraedro : public Objeto3D{
public:
    



    Tetraedro();
    
    Tetraedro(std::vector<int>tCaras, std::vector<float>tVertices, std::vector<float>tColores);
    
    Tetraedro(float distancia);
    
   
    
};

#endif