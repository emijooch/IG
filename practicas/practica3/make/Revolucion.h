//**************************************************************************
// Práctica 3
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

#ifndef _REVOLUCION_H
#define _REVOLUCION_H

#include "Objeto3D.h"
#include <vector>
#include <cstdio>
#include "Cilindro.h"

class Revolucion:public Objeto3D{
	private:
    std::vector<float> revolucionVertices;
    
        
    public:

    Revolucion();
    
    Revolucion(char *archivo);
    //Revolucion(std::vector<float>vectorFigura);
    void generaRevolucion(int rotacionParticiones);
    void generaRevolucionZ(int rotacionParticiones);
    
    void generaTapas(int particion, bool tapas);
};

#endif
