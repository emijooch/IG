//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

#ifndef _CUBO_H
#define _CUBO_H

#include "Objeto3D.h"
#include <vector>

class Cubo:public Objeto3D{
	public:
    
    Cubo();
    
    Cubo(std::vector<int>cCaras, std::vector<float>cVertices, std::vector<float>cColores);
    
    Cubo(float distancia);
    
    void setTecla(unsigned char newTecla);
    
    unsigned char getTecla();
    
    void setValido(bool cValido);
    
    bool getValido();
    
    void dibuja();
    
    void redimension(float distancia);
    
    
};

#endif
