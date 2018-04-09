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
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>//macOX
//#include <GLUT/glut.h>//macOX
#include <string>
#include <vector>


class Objeto3D{

protected:
    std::vector<float> vertices;
    std::vector<int> caras;
    std::vector<float> colores;
    unsigned char tecla;
    bool valido;

    
    
    
public:
	void drawMode(GLenum tipo);
    void drawAll();
    void drawChess();
    void draw(char tecla);
};

#endif


