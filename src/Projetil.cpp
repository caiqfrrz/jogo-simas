#include<iostream>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam)
    {
        corpo.setSize(tam);
        setPosicao(sf::Vector2f(0.f, 0.f));
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
        velocidade = sf::Vector2f(-12, 0);
        corpo.move(velocidade);
    }
}