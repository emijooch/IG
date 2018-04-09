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

#ifndef _ILUMINACION_H
#define _ILUMINACION_H

#include "Objeto3D.h"

#include <vector>

class Iluminacion:Objeto3D{
	public:
    


    std::vector<float> caf;// color ambiental de la fuente 
    std::vector<float> cdf; // color difuso de la fuente 
    std::vector<float> csf; // color especular de la fuente
    std::vector<float> dirf; // (x,y,z,w) 
    int foco=0;
    void enciende(int foco);
    void apaga(int foco);
    Iluminacion(std::vector<float>caf, std::vector<float>cdf, std::vector<float>csf, std::vector<float>dirf, int foco);
    Iluminacion();
    void rotacionCamara(int positionNext, int foco);
    void rotacion();
    void enciendeFocos();
    
};

#endif
