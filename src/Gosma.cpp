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
        }
        Gosma::~Gosma()
        {

        }
        void Gosma::executar()
        {

        }
        void Gosma::passando(Entidade* pE, bool l)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);
            aux->lentidao(l);
        }
    }
}