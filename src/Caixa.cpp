#include "../Entidades/Obstaculos/Caixa.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos):
        Obstaculo(pos, false)
        {
            corpo.setFillColor(sf::Color::Cyan);
        }
        Caixa::~Caixa()
        {

        }
        void Caixa::executar()
        {
            
        }
        void Caixa::colidir(Entidade* pE)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            aux->setLento(false);
        }
    }
}