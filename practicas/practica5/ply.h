//**************************************************************************
// Práctica 4
//
//  Emilio Jose Ochando Pantigas
//
//  3¼C grupo C2
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
#ifndef _PLY_H
#define _PLY_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "ejes.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include <cstdio>
#include <string>
#include "vertex.h"


class Ply:public Objeto3D{
  public:

    Ply();

    Ply(char *archivo);


    
    
    
    
};

#endif