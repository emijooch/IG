//**************************************************************************
// Práctica 3
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


#include <vector>



void Objeto3D::drawAll(){



    glPolygonMode(GL_FRONT, GL_POINT);
    glPointSize(10);

    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glDrawElements( GL_POINTS, caras.size(), GL_UNSIGNED_INT, &caras[0]);
    

    glPolygonMode(GL_FRONT, GL_LINE);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]-1);
    
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);

    glPolygonMode(GL_FRONT, GL_FILL);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]-2);

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
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, &colores[0]);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glDrawElements( GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
    glDisable(GL_CULL_FACE);
}



//**************************************************************************
// Funcion para dibujar el objeto en modo ajedrez
//***************************************************************************

void Objeto3D::drawChess(){
    std::vector<unsigned int>carasPar;
    std::vector<unsigned int>carasImpar;
    std::vector<float>cNegativos;

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
            //case 'R':this->revolucion();break;
    }
}
