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
        void Espinho::colidir(Entidade* pE)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            aux->setLento(false);
        }
        int Espinho::getDano()
        {
            return dano;
        }
        int Espinho::dano = 1;
    }
}