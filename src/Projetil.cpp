#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>

#include "../Entidades/Projetil.h"

namespace Entidades
{
    Projetil::Projetil(std::string dir, sf::Vector2f tam, sf::Vector2f pos, bool at) : dano(1),
                                                            direcao(dir)
    {
        setAtivo(at);
        if(at == false)
        {
            corpo.setFillColor(sf::Color::Transparent);
        }
        corpo.setSize(tam);
        setPosicao(pos);

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
    Projetil::Projetil(sf::Vector2f tam, sf::Vector2f pos, sf::Vector2f vel): dano(1)
    {
        corpo.setSize(tam);
        setPosicao(pos);
        setVelocidade(vel);
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

                if (aux->getMorte() == false)
                {
                    aux->TomarDano(dano, b);
                }
            }
        }
        setAtivo(false);
    }
    void Projetil::colidir()
    {
        if(getAtivo() == true)
        {
            corpo.setFillColor(sf::Color::Transparent);
            setAtivo(false);
        }
    }
    void Projetil::reset()
    {
        corpo.setFillColor(sf::Color::White);
    }
    int Projetil::getDano()
    {
        return dano;
    }
    void Projetil::salvar(std::ostringstream* entrada)
    {
        
        (*entrada) << "{\"posicao\": [" << getPosicao().x << "," << getPosicao().y << "],\"ativo\": "<< getAtivo() << ", \"dano\": " << getDano() << ", \"direcao\": \"" << direcao << "\"}";
        
    }
}