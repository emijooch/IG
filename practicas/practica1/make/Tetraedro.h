//**************************************************************************
// Práctica 1
//
//  Emilio José Ochando Pantigas
//
//  3ºC grupo C2
//**************************************************************************

#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H

#include "Objeto3D.h"
#include <vector>

class Tetraedro : public Objeto3D{
public:
    
    Tetraedro();
    
    Tetraedro(std::vector<int>tCaras, std::vector<float>tVertices, std::vector<float>tColores);
    
    Tetraedro(float distancia);
    
    void setTecla(unsigned char nuevaTecla);
    
    unsigned char getTecla();
    
    void setValido(bool cvalido);
    
    bool getValido();
    
    void dibuja();
    
};

#endif
