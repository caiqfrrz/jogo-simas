#include<iostream>
#include <time.h>
#include <stdlib.h>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam):
    dano(1)
    {
        corpo.setSize(tam);
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
        if(direcao == "esquerda")
        {
            velocidade = sf::Vector2f(-12, 0);
            corpo.move(velocidade);
        }
        else if(direcao == "direita")
        {
            velocidade = sf::Vector2f(12, 0);
            corpo.move(velocidade);
        }
        else
        {
            velocidade = sf::Vector2f(0, -12);
            corpo.move(velocidade);
        }
    }
    void Projetil::colidir(Entidade* pE)
    {
        if(getAtivo() == true)
        {
            //corpo.setFillColor(sf::Color::Transparent);
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            if(aux->getMorto() == false)
            {
                aux->TomarDano(dano);
            }
        }
        
        setAtivo(false);
    }
    void Projetil::reset()
    {
        corpo.setFillColor(sf::Color::White);
    }
    void Projetil::setDirecao(std::string d)
    {
        direcao = d;
    }
    int Projetil::getDano()
    {
        return dano;
    }
}