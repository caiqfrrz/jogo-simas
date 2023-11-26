#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f tam, std::string dir) : dano(1),
                                                            direcao(dir)
    {
        corpo.setSize(tam);

        if (direcao == "esquerda")
        {
            velocidade = sf::Vector2f(-12, 0);
        }
        else if (direcao == "direita")
        {
            velocidade = sf::Vector2f(12, 0);
        }
        else if (direcao == "cima")
        {
            velocidade = sf::Vector2f(0, -12);
        }
        else
            velocidade = sf::Vector2f(0, 0);
    }
    Projetil::~Projetil()
    {
    }
    void Projetil::setVelocidade(sf::Vector2f v)
    {
        velocidade = v;
    }
    void Projetil::executar()
    {
        this->desenhar();
        this->atirar();
    }
    void Projetil::atirar()
    {
        velocidade += sf::Vector2f(0, 0.02);
        corpo.move(velocidade);
    }
    void Projetil::colidir(Entidade *pE, bool b)
    {
        if (getAtivo() == true)
        {
            corpo.setFillColor(sf::Color::Transparent);

            if (pE != nullptr)
            {
                Entidades::Personagens::Personagem *aux = static_cast<Entidades::Personagens::Personagem *>(pE);

                if (aux->getMorto() == false)
                {
                    aux->TomarDano(dano, b);
                }
            }
        }

        setAtivo(false);
    }
    void Projetil::reset()
    {
        corpo.setFillColor(sf::Color::White);
    }
    int Projetil::getDano()
    {
        return dano;
    }
}