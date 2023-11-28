#include "../Entidades/Personagens/Personagem.h"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos,sf::Vector2f vel) : Entidade(pos),
                                                                       damaged((bool)0),
                                                                       timer(),
                                                                       lento(false),
                                                                       pulando(false),
                                                                       pulo(0.f),
                                                                       grafico(),
                                                                       vida(10)
        {
            setVelocidade(vel);
        }
        Personagem::~Personagem()
        {
            vida = 0;
        }
        int Personagem::getVida()
        {
            return vida;
        }
        void Personagem::setVida(int v)
        {
            vida = v;
        }
        void Personagem::TomarDano(int d, bool b)
        {
            if (!damaged)
            {
                setVida(getVida() - d);
                if (b)
                {
                    corpo.setFillColor(sf::Color::Red);
                    damaged = true;
                    timer = clock();
                }
            }
        }
        void Personagem::morreu()
        {
            morte = true;
        }
        void Personagem::reviver()
        {
            vida = 10;
            morte = false;
            
        }
        bool Personagem::getMorte()
        {
            return morte;
        }
        void Personagem::ResetColor()
        {
            corpo.setFillColor(sf::Color::Green);
            damaged = false;
        }
        bool Personagem::getDamaged()
        {
            return damaged;
        }

        bool Personagem::getLento()
        {
            return lento;
        }

        void Personagem::setLento(bool b)
        {
            lento = b;
        }
    }
}