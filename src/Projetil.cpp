#include<iostream>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam)
    {
        corpo.setSize(tam);
    }
    Projetil::~Projetil()
    {
    
    }
    void Projetil::executar()
    {

    }
    void Projetil::atirar(int vel)
    {
        corpo.move(-vel, 0);
    }
    void Projetil::setPos(sf::Vector2f pos)
    {
        corpo.setPosition(pos);
    }
}