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

//**************************************************************************
// Funcion constructor por defecto
//***************************************************************************

Ply::Ply(){
  this->vertices.resize(0);
  this->caras.resize(0);
  this->colores.resize(0);
  this->normalesVertices.resize(0);
}


//**************************************************************************
// Funcion constructor con parametro 1 ARGUMENTO
//***************************************************************************
Ply::Ply(char *archivo){

  this->vertices.resize(0);
  this->caras.resize(0);
  this->colores.resize(0);

  _file_ply File_ply;

  vector<_vertex3f> Vertices;
  vector<_vertex3i> Triangles;

  if (File_ply.open(archivo)){
    File_ply.read(Vertices,Triangles);


    for (int i = 0; i < Vertices.size(); ++i){
      vertices.push_back(Vertices[i].x);
      vertices.push_back(Vertices[i].y);
      vertices.push_back(Vertices[i].z);
      colores.push_back(255);
      colores.push_back(0);
      colores.push_back(0);
    }
    for (int i = 0; i < Triangles.size(); ++i){
      caras.push_back(Triangles[i].x);
      caras.push_back(Triangles[i].y);
      caras.push_back(Triangles[i].z);
    }

    

    std::cout << "File read correctly" << std::endl;
    if (Triangles.size() < Vertices.size()/2)
    {
      std::cout << "la Imagen no tiene suficientes caras para DIBUJAR por carga (3)" << std::endl;
    }
  }
  else std::cout << "File can't be opened" << std::endl;

  normalVertices();
}







