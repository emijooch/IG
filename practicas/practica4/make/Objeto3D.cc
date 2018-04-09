//**************************************************************************
// Práctica 4
//
//  Emilio Jose Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <OpenGL/OpenGL.h>        //macOX
//#include <GLUT/glut.h>            //macOX
#include <string>
#include "Objeto3D.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

#include <vector>



void Objeto3D::drawAll(){



    glPolygonMode(GL_FRONT, GL_POINT);
    glPointSize(10);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glNormalPointer( GL_FLOAT, 0, &normalesVertices[0]);
    glDrawElements( GL_POINTS, caras.size(), GL_UNSIGNED_INT, &caras[0]);
    

    glPolygonMode(GL_FRONT, GL_LINE);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]-1);
    glNormalPointer( GL_FLOAT, 0, &normalesVertices[0]);
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

    glPolygonMode(GL_FRONT, GL_FILL);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]-2);

    glNormalPointer( GL_FLOAT, 0, &normalesVertices[0]);
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
    glDisable(GL_CULL_FACE);
    
}




//**************************************************************************
// Funcion para dibujar el objeto en todos sus modos(punto, linea, solido)
//***************************************************************************
void Objeto3D::drawMode( GLenum tipo){
    



    glPolygonMode(GL_FRONT, tipo);
    glPointSize(10);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glNormalPointer( GL_FLOAT, 0, &normalesVertices[0]);
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
    glDisable(GL_CULL_FACE);
    glDisable(GL_NORMALIZE);
}



//**************************************************************************
// Funcion para dibujar el objeto en modo ajedrez
//***************************************************************************

void Objeto3D::drawChess(){
    std::vector<unsigned int>carasPar;
    std::vector<unsigned int>carasImpar;
    std::vector<float>cNegativos;
    std::vector<float>cColores;

    carasPar.resize(0);
    carasImpar.resize(0);
    cNegativos.resize(0);
    
    
    //Funcion para crear los negativos de los colores
    for (int i = 0; i <= this->colores.size(); i += 3){
        
        
        int r = 0, g = 0, b = 0;
        r = 255 - colores[i];
        g = 255 - colores[i + 1];
        b = 255 - colores[i + 2];
        
        cNegativos.push_back(r);
        cNegativos.push_back(g);
        cNegativos.push_back(b);
    }
    
    for (int i = 0; i <= caras.size(); i += 3){
        if (i%2 != 0){
            carasImpar.push_back(caras[i]);
            carasImpar.push_back(caras[i + 1]);
            carasImpar.push_back(caras[i + 2]);
        } 
    }
    
    
    glPolygonMode(GL_FRONT, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    

    glColorPointer(3, GL_FLOAT, 0, &colores[0]);
    glDrawElements( GL_TRIANGLES, carasImpar.size(), GL_UNSIGNED_INT, &carasImpar[0]);
    
    
    glColorPointer(3, GL_FLOAT, 0, &cNegativos[0]);
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

//**************************************************************************
// Funcion para modelar el dibujado del objeto segun la tecla pulsada
//***************************************************************************

void Objeto3D::draw(char tecla){
        switch(tecla){
            case 'P':this->drawMode(GL_POINT);break;
            case 'L':this->drawMode(GL_LINE);break;
            case 'F':this->drawMode(GL_FILL);break;
            case 'C':this->drawChess();break;
            case 'A':this->drawAll();break;
            
    }
}

void Objeto3D::normalVertices(){
    // Calculamos las normales de las caras
    normalesVertices.resize(vertices.size());
    for(int i = 0; i < caras.size(); i+=3){
        

        //_vertex3f A, B, C;
        //caraA=caras[i]*3;
        //Ax,Ay,Az
        float Ax = vertices[3*caras[i+1]] - vertices[3*caras[i]];
        float Ay = vertices[3*caras[i+1]+1] - vertices[3*caras[i]+1];
        float Az = vertices[3*caras[i+1]+2] - vertices[3*caras[i]+2];
        //Bx, By, Bz
        float Bx = vertices[3*caras[i+2]] - vertices[3*caras[i]];
        float By = vertices[3*caras[i+2]+1] - vertices[3*caras[i]+1];
        float Bz = vertices[3*caras[i+2]+2] - vertices[3*caras[i]+2];

        float nx = Ay*Bz-Az*By;
        float ny = -(Ax*Bz-Az*Bx);
        float nz = Ax*By-Ay*Bx;

        
        normalesVertices[3*caras[i]]+=nx;
        normalesVertices[3*caras[i]+1]+=ny;
        normalesVertices[3*caras[i]+2] += nz;

        normalesVertices[3*caras[i+1]]   += nx;
        normalesVertices[3*caras[i+1]+1] += ny;
        normalesVertices[3*caras[i+1]+2] += nz;

        normalesVertices[3*caras[i+2]]   += nx;
        normalesVertices[3*caras[i+2]+1] += ny;
        normalesVertices[3*caras[i+2]+2] += nz;
    }

    for (int i = 0; i < normalesVertices.size(); i+=3){
           float cX = normalesVertices[i];
           float cY = normalesVertices[i+1];
           float cZ = normalesVertices[i+2];

           float modulo= sqrt(pow(cX,2) + pow(cY,2) + pow(cZ,2));

           normalesVertices[i] = (cX/modulo);
           normalesVertices[i+1] = (cY/modulo);
           normalesVertices[i+2] = (cZ/modulo);

    }
    
}


