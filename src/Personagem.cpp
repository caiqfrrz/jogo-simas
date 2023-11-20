#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos):
        Entidade(pos),
        damaged((bool)0),
        timer(),
        num_vidas(1),
        lento(false),
        vida(10)
        {

        }
        Personagem::~Personagem()
        {
            num_vidas = 0;
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
        void Personagem::TomarDano()
        {
            corpo.setFillColor(sf::Color::Red);
            damaged = true;
            timer = clock();
        }
        void Personagem::morreu()
        {
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
        void Personagem::lentidao(bool l)
        {
            lento = l;
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