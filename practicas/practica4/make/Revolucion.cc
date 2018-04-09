//**************************************************************************
// Práctica 4
//
//  Emilio Jose Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>    //macOX
//#include <GLUT/glut.h>        //macOX

#include "Objeto3D.h"
#include <vector>
#include <cstdio>
#include <cmath>
#include "math.h"
#include <iostream>
#include "file_ply_stl.h"
#include "Revolucion.h"
#include "ply.h"
#include "vertex.h"
#include "Cilindro.h"
using namespace std;

//**************************************************************************
// Constructores de Revolucion por defecto
//***************************************************************************

Revolucion::Revolucion(){
  this->vertices.resize(0);
  this->caras.resize(0);
  this->colores.resize(0);
  this->normalesVertices.resize(0);
}

//**************************************************************************
// Funcion constructor con parametro 1 ARGUMENTO
//***************************************************************************

Revolucion::Revolucion(char * archivo){
    _file_ply File_ply;
    colores.resize(0);
    revolucionVertices.resize(0);

  vector<_vertex3f> Vertices;
  vector<_vertex3i> Triangles;

  if (File_ply.open(archivo)){
    File_ply.read(Vertices,Triangles);


    for (int i = 0; i < Vertices.size(); ++i){
        this->vertices.push_back(Vertices[i].x);
        this->vertices.push_back(Vertices[i].y);
        this->vertices.push_back(Vertices[i].z);
        revolucionVertices.push_back(Vertices[i].x);
        revolucionVertices.push_back(Vertices[i].y);
        revolucionVertices.push_back(Vertices[i].z);
        colores.push_back(255);
        colores.push_back(0);
        colores.push_back(0);
        
      
    }

    std::cout << "File read correctly" << std::endl;
    
  }
  else std::cout << "File can't be opened" << std::endl;

  
  normalVertices();
}
/*
Revolucion::Revolucion(){

    for (int i = 0; i < vectorFigura.size(); i+=3){

        revolucionVertices.push_back(vectorFigura[i]);
        revolucionVertices.push_back(vectorFigura[i+1]);
        revolucionVertices.push_back(vectorFigura[i+2]);
        colores.push_back(255);
        colores.push_back(0);
        colores.push_back(0);   
    }
}
*/



void Revolucion::generaRevolucionZ(int particion){
    
    caras.resize(0);
    vertices.resize(0);

    if (revolucionVertices[0] == 0.0 && revolucionVertices[1] == 0.0){ 

        for (int i = 3; i < revolucionVertices.size(); i++){
            vertices.push_back(revolucionVertices[i]);
        }
        revolucionVertices.resize(0);
        for (int i = 0; i < vertices.size(); i++){
            revolucionVertices.push_back(vertices[i]);
        }

    }else{

        for (int i = 0; i < revolucionVertices.size(); i++){
            vertices.push_back(revolucionVertices[i]);
        }

    }

    if (vertices[vertices.size()-2]==0 && vertices[vertices.size()-3]==0){
        for (int i = 0; i < 3; ++i){
            vertices.pop_back();
            revolucionVertices.pop_back();
        }
        
    }

    for (int j = 0; j < (particion-1); j++){

        //Generamos todos los vertices
        for (unsigned int i = 0; i < revolucionVertices.size(); i+=3){

            double alpha=(2.0*M_PI)/particion;

            vertices.push_back(cos(alpha*(j+1))*revolucionVertices[i]-sin(alpha*(j+1))*revolucionVertices[i+1]);
            vertices.push_back(sin(alpha*(j+1))*revolucionVertices[i]+cos(alpha*(j+1))*revolucionVertices[i+1]);
            vertices.push_back(revolucionVertices[i+2]);
            
            colores.push_back(255);
            colores.push_back(0);
            colores.push_back(0);
            
            
            
        }
    }
        //creamos las cara
        
        for (int i = 0; i < particion-1; i++){



            for (int j = 0; j < (revolucionVertices.size()/3)-1 ; j++){
                
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+1);
                this->caras.push_back(j+(revolucionVertices.size()/3)*i);
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3));
                
                
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+1);
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3));
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3)+1);
                
                
                
                
                
                
            }

        }
        
        //Creamos la ultima cara a partir de la primera revolucion
        if (particion >= 1){
                for (int k = 0; k < (revolucionVertices.size()/3)-1 ; k++){
                
                    
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1));
                    this->caras.push_back(k);
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1)+1);
                
                
                    this->caras.push_back(k);
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1)+1);
                    this->caras.push_back(k+1);
                }
        }


}




//**************************************************************************
// Funcion para generar vertices y caras con 
//   parametro de numero de revoluciones
//***************************************************************************

void Revolucion::generaRevolucion(int particion){
    
    caras.resize(0);
    vertices.resize(0);

    if (revolucionVertices[0] == 0.0 && revolucionVertices[2] == 0){ 

        for (int i = 3; i < revolucionVertices.size(); i++){
            vertices.push_back(revolucionVertices[i]);
        }
        revolucionVertices.resize(0);
        for (int i = 0; i < vertices.size(); i++){
            revolucionVertices.push_back(vertices[i]);
        }

    }else{

        for (int i = 0; i < revolucionVertices.size(); i++){
            vertices.push_back(revolucionVertices[i]);
        }

    }

    if (vertices[vertices.size()-1]==0 && vertices[vertices.size()-3]==0){
        for (int i = 0; i < 3; ++i){
            vertices.pop_back();
            revolucionVertices.pop_back();
        }
        
    }


    
    
    
    
    

    for (int j = 0; j < (particion-1); j++){

        //Generamos todos los vertices
        for (unsigned int i = 0; i < revolucionVertices.size(); i+=3){

            double alpha=(2.0*M_PI)/particion;

            vertices.push_back(cos(alpha*(j+1))*revolucionVertices[i]+sin(alpha*(j+1))*revolucionVertices[i+2]);
            vertices.push_back(revolucionVertices[i+1]);
            vertices.push_back(-sin(alpha*(j+1))*revolucionVertices[i]+cos(alpha*(j+1))*revolucionVertices[i+2]);
            
            colores.push_back(255);
            colores.push_back(0);
            colores.push_back(0);
            
            
            
        }
    }
    
    

        //creamos las cara
        
        for (int i = 0; i < particion-1; i++){



            for (int j = 0; j < (revolucionVertices.size()/3)-1 ; j++){
                
                this->caras.push_back(j+(revolucionVertices.size()/3)*i); //0
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3));
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+1);
                
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+1);
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3));
                this->caras.push_back(j+(revolucionVertices.size()/3)*i+(revolucionVertices.size()/3)+1); 
                
            }

        }
        
        //Creamos la ultima cara a partir de la primera revolucion
        if (particion >= 1){
                for (int k = 0; k < (revolucionVertices.size()/3)-1 ; k++){
                
                    
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1));
                    this->caras.push_back(k);
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1)+1);
                
                    this->caras.push_back(k+(revolucionVertices.size()/3)*(particion-1)+1);
                    this->caras.push_back(k);
                    this->caras.push_back(k+1);
                }
        }
        
}


//**************************************************************************
// Funcion para generar las tapas del objeto en revolucion
//***************************************************************************

void Revolucion::generaTapas(int particion, bool tapas){
    if (particion >= 2 && tapas == true){
        vertices.push_back(0);
        vertices.push_back(revolucionVertices[1]);
        vertices.push_back(0);

        vertices.push_back(0);
        vertices.push_back(revolucionVertices[revolucionVertices.size()-2]);
        vertices.push_back(0);

        

        colores.push_back(255);
        colores.push_back(0);
        colores.push_back(0);
        colores.push_back(255);
        colores.push_back(0);
        colores.push_back(0);

                for (int i = 0; i < particion-1; i++){
                    caras.push_back(revolucionVertices.size()/3 * i);
                    caras.push_back(vertices.size()/3-2);
                    caras.push_back((revolucionVertices.size()/3) * (i+1));

                    caras.push_back(vertices.size()/3-1);
                    caras.push_back(revolucionVertices.size()/3 * i + (revolucionVertices.size()/3-1));
                    caras.push_back((revolucionVertices.size()/3) * (i+1)+(revolucionVertices.size()/3-1));
                    

                }
            
            
            caras.push_back(vertices.size()/3-2);
            caras.push_back(0);
            caras.push_back((revolucionVertices.size()/3) * (particion-1));
            
            
            
            

            caras.push_back(vertices.size()/3-1);
            caras.push_back(revolucionVertices.size()/3 * (particion-1) + (revolucionVertices.size()/3-1));
            caras.push_back(revolucionVertices.size()/3-1);
            


    }
            
    std::cout<<"estos son los vertices con las tapas : ";
    for (int i = 0; i < vertices.size(); i++){
                std::cout<<vertices[i]<<",";
        }

    std::cout<<"estos son las caras con tapas : ";
        for (int i = 0; i < caras.size(); i++){
            std::cout<<caras[i]<<",";
            }
    std::cout<<"verticesR "<<vertices.size();
    std::cout<<"carasR "<<caras.size();
    std::cout<<"coloresR "<<colores.size();
            cout<< "numero revoluciones "<< particion << endl;
}









