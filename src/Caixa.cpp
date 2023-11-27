#include "../Entidades/Obstaculos/Caixa.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos):
        Obstaculo(pos, false)
        {
            textura.loadFromFile("Design/Imagens/caixa.png");
            corpo.setTexture(&textura);
            corpo.setFillColor(sf::Color(82, 16, 16));

            morreu();
        }
        Caixa::~Caixa()
        {

        }
        void Caixa::executar()
        {
            
        }
        void Caixa::colidir(Entidade* pE, bool b)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            aux->setLento(false);
        }
    }
}