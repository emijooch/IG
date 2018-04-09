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
#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "Cubo.h"
#include "Tetraedro.h"
#include <cstdio>
#include <vector>
#include "vertex.h"
#include "ply.h"
#include "Revolucion.h"
#include "Cilindro.h"
#include "Bomberos.h"
#include "Iluminacion.h"
#include "Texturas.h"
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

	char tecla='0';
	char teclaFuncion='P';
	int escalar=1;
	int rotacionParticiones=0;
	bool tapas = true;
	bool luces = false;
	int foco=0;
	bool onOFF=false;
	int rotacionCamara=1;
	char textura='0';

    Cubo* miCubo = new Cubo();
    Tetraedro* miTetraedro = new Tetraedro();
    Ply* miPly = new Ply();
    Revolucion* miRevolucion = new Revolucion();
    Bomberos* miCamion = new Bomberos();
    Iluminacion* miIluminacion = new Iluminacion();
    Iluminacion* miIluminacion2 = new Iluminacion();
    Texturas* miTexturas= new Texturas();
    
    float grado1 = 0.0;
	float grado2 = 0.0;
	float grado3 = 0.0;
	float grado4 = 0.0;
	float grado5 = 0.0;
	float grado8 = 0.0;

	

public:
    
    Escena(char **argv);
    Escena();

    
    bool iluminacion(int foco);
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

};
#endif
