//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>        //macOX
//#include <GLUT/glut.h>            //macOX
#include "escena.h"
#include "Tetraedro.h"
#include "Cubo.h"
#include <vector>
#include <cstdio>

using namespace std;

//**************************************************************************
// Constructor de escena, dibuja pantalla de salida y
//          creacion de objetos en la escena
//***************************************************************************


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    
    //Inicializacion de la figura que vayamos a dibujar

    
    miTetraedro = new Tetraedro(80.0);
    miCubo = new Cubo(50.0);
    miCubo->setValido(true);
    miTetraedro->setValido(false);
    
}

//**************************************************************************
// Funcion para inicializar la escena
//***************************************************************************


void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
    
    this->miCubo->draw();
    this->miTetraedro->draw();
    
}
//**************************************************************************
// Funcion que dibuja en blanco la pantalla para borrarla
//***************************************************************************


void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

//**************************************************************************
// Funcion que dibuja objetos en la escena en funcion de la tecla pulsada
//***************************************************************************


int Escena::teclaPulsada(unsigned char Tecla1,int x,int y){
    
    std::cout << "Tecla" << Tecla1<< std::endl;
    if (toupper(Tecla1)=='Q'){
        return 1;
    }
    else{
        switch(toupper(Tecla1)){
            case 'P':
                miCubo->setTecla('P');
                miTetraedro->setTecla('P');
                dibujar();
                return 0;
            case 'L':
                miCubo->setTecla('L');
                miTetraedro->setTecla('L');
                dibujar();
                return 0;
            case 'F':
                miCubo->setTecla('F');
                miTetraedro->setTecla('F');
                dibujar();
                return 0;
            case 'C':
                miCubo->setTecla('C');
                miTetraedro->setTecla('C');
                dibujar();
                return 0;
            case '1':
                miCubo->setValido(false);
                miTetraedro->setValido(true);
                miTetraedro->setTecla('P');
                dibujar();
                return 0;
            case '2': 
                miCubo->setValido(true);
                miTetraedro->setValido(false);
                miCubo->setTecla('P');
                dibujar();
                return 0;
            default: return 0;
        }
    }
}


void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaciÛn de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaciÛn de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}




