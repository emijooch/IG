//**************************************************************************
// Práctica 3
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
#include "escena.h"
#include "Tetraedro.h"
#include "Cubo.h"
#include <vector>
#include <cstdio>
#include "ply.h"
#include "vertex.h"
#include "Objeto3D.h"
#include "file_ply_stl.h"
#include "Revolucion.h"
#include "Cilindro.h"



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

    miTetraedro = new Tetraedro(1);
    miCubo = new Cubo(1);
    miCamion = new Bomberos();



}


Escena::Escena(char **argv){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    
    //Inicializacion de la figura que vayamos a dibujar

    miTetraedro = new Tetraedro(5.0);
    miCubo = new Cubo(1.0);
    miPly = new Ply(argv[1]);
    miRevolucion = new Revolucion(argv[1]);
    miCamion = new Bomberos();
    
    
    

    
    
}


//**************************************************************************
// Funcion para inicializar la escena
//***************************************************************************


void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/100;
	Height=UI_window_height/100;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
    
    switch(toupper(tecla)){
        case '2':
            this->miCubo->draw(teclaFuncion);
            break;
        case '1':
            this->miTetraedro->draw(teclaFuncion);
            break;
        case '3':
            
            this->miPly->draw(teclaFuncion);
            break;
        case '4':
            this->miRevolucion->generaRevolucion(rotacionParticiones);
            this->miRevolucion->generaTapas(rotacionParticiones, tapas);
            this->miRevolucion->draw(teclaFuncion);
            break;
        case '5':
            miCamion->setGrado(grado1,grado2,grado3,grado4, grado5);
            std::cout<<"grado 3 :"<<grado3<<endl;
            miCamion->setTecla(teclaFuncion);
            miCamion->dibujar();
            break;

    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-Width/escalar,Width/escalar,-Height/escalar,Height/escalar,Front_plane,Back_plane);
    
    
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
    Tecla1 = toupper(Tecla1);
        switch(Tecla1){
            case 'P':
                teclaFuncion='P';
                break;
            case 'L':
                teclaFuncion='L';
                break;
            case 'F':
                teclaFuncion='F';
                break;
            case 'C':
                teclaFuncion='C';
                break;
            case 'A':
                teclaFuncion='A';
                break;
            case '?':
                grado5+=0.5;
                break;
            case '=':
                grado5-=0.5;;
                break;
            case '*':
            if (grado4<=1.9){
                    grado4+=0.1;
                }else grado4=2.0;
                
                break;
            case '+':
                if (grado4>=0.1){
                    grado4-=0.1;
                }else grado4=0.0;
                break;
            case '_':
                if (grado3<=44.5){
                    grado3+=0.5;
                }else grado3=45.0;
                break;
            case '-':
                if (grado3>=0.5){
                    grado3-=0.5;
                }else grado3=0.0;
                grado3-=0.5;;
                break;
            case ':':
                grado2+=0.5;
                break;
            case '.':
                grado2-=0.5;;
                break;
            case ';':
                grado1+=2;
                break;
            case ',':
                grado1-=4;;
                break;
            case 'T':
                if(tapas == true){
                    tapas = false;
                }else
                tapas=true;
                break;
            case 'M':
                rotacionParticiones+=1;
                break;
            case 'N':
                rotacionParticiones-=1;
                break;
            case '<':
                escalar-=1;
                break;
            case '>':
                escalar+=1;
                break;
            case '1':
                tecla='1';
                break;
            case '2': 
                tecla='2';
                break;
            case '3': 
                tecla='3';
                break;
            case '4':
                tecla='4';
                break;
            case '5':
                tecla='5';
                break;
        }
        if (toupper(Tecla1)=='Q'){
        return 1;
    }
    else{
        return 0;  
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
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/100;
Height=newHeight/100;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
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






