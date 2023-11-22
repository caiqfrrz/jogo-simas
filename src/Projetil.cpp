#include<iostream>
#include <time.h>
#include <stdlib.h>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam):
    dano(1),
    ativo(true)
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
        corpo.setFillColor(sf::Color::Transparent);
    }
    void Projetil::reset()
    {
        //corpo.setFillColor(sf::Color::White);
    }
    int Projetil::getDano()
    {
        return dano;
    }
    bool Projetil::getAtivo()
    {
        return ativo;
    }

    void Projetil::setAtivo(bool b)
    {
        ativo = b;
    }

}