#include "../Entidades/Obstaculos/Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos):
        Obstaculo(pos, true)
        {
            corpo.setFillColor(sf::Color::Red);
            morreu();
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
        void Espinho::colidir(Entidade* pE)
        {
            static_cast<Personagens::Personagem*>(pE)->TomarDano(dano);
        }
        int Espinho::dano = 1;
    }
}