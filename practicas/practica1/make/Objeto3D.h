//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
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
	

    void drawPoint();
    void drawLine();
    void drawTriangle();
    void drawChess();
    void draw();
};

#endif


