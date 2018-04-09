//**************************************************************************
// Pr‡ctica 1
//
//  Emilio JosŽ Ochando Pantigas
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
#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include <cstdio>
#include <vector>
#include "vertex.h"
#include "ply.h"
using namespace std;



class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000

Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();
    
    Cubo* miCubo = new Cubo();
    Tetraedro* miTetraedro = new Tetraedro();
    Ply* miPly = new Ply();


public:
    
    Escena();

    Escena(vector<_vertex3f> Vertices, vector<_vertex3i> Triangles);
    
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
