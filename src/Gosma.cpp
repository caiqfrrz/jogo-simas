#include "../Entidades/Obstaculos/Gosma.h"
#include "../Entidades/Personagens/Personagem.h"
#include <iostream>

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(sf::Vector2f pos):
        Obstaculo(pos, false, true),
        força(2.f)
        {
            corpo.setFillColor(sf::Color(139,69,19));
            morreu();
        }
        Gosma::~Gosma()
        {

        }
        void Gosma::executar()
        {

        }
        void Gosma::colidir(Entidade* pE, bool b)
        {
            Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(pE);

            jogador->setLento(true);;
        }
    }
}