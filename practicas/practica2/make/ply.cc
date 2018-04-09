//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
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
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "Objeto3D.h"
#include "file_ply_stl.h"
#include "ply.h"
#include "vertex.h"

using namespace std;

Ply::Ply(){
  this->vertices.resize(0);
  this->caras.resize(0);
  this->colores.resize(0);
}

Ply::Ply(vector<_vertex3f> &Vertices, vector<_vertex3i> &Triangles){
  for (int i = 0; i < Vertices.size(); ++i){
    Objeto3D::vertices.push_back(Vertices[i].x);
    Objeto3D::vertices.push_back(Vertices[i].y);
    Objeto3D::vertices.push_back(Vertices[i].z);  
  }
  for (int i = 0; i < Triangles.size(); ++i){
    Objeto3D::caras.push_back(Triangles[i].x);
    Objeto3D::caras.push_back(Triangles[i].y);
    Objeto3D::caras.push_back(Triangles[i].z);

  }
}

void Ply::dibujar(){
  Objeto3D::draw();
}






