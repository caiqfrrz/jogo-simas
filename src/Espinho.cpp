#include "../Entidades/Obstaculos/Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos):
        Obstaculo(pos, true)
        {
            corpo.setFillColor(sf::Color::Red);
        }
        Espinho::~Espinho()
        {

        }
        void Espinho::executar()
        {
            
        }
        int Espinho::getDano()
        {
            return dano;
        }
        int Espinho::dano = 1;
    }
}