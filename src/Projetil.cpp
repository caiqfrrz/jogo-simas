#include<iostream>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam)
    {
        corpo.setSize(tam);
        velocidade = sf::Vector2f(-12, 0);
    }
    Projetil::~Projetil()
    {
    
    }
    void Projetil::executar()
    {
        this->desenhar();
        this->atirar();
    }
    void Projetil::atirar()
    {
        corpo.move(velocidade);
    }
    void Projetil::colidir()
    {
        setVelocidade(sf::Vector2f(0.f, 0.f));
    }
}