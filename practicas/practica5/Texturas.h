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

#ifndef _TEXTURAS_H
#define _TEXTURAS_H

#include "Objeto3D.h"

#include <vector>

class Texturas{
	public:
    
	std::vector<float> amb;// color ambiental de la fuente 
    std::vector<float> dif; // color difuso de la fuente 
    std::vector<float> spec; // color especular de la fuente
    float shine;

    Texturas();
    Texturas(std::vector<float>amb, std::vector<float>dif, std::vector<float>spec, float shine);
    void enciende();
    void material(char tecla);
    //void material(char tecla);
    
};

#endif
