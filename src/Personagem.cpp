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
        vida(10)
        {

        }
        Personagem::~Personagem()
        {
            num_vidas = 0;
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
        void Personagem::ResetColor()
        {
             corpo.setFillColor(sf::Color::Green);
             damaged = false;
        }
    }
}