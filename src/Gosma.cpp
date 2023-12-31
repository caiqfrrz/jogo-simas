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
            textura.loadFromFile("Design/Imagens/gosma.png");
            corpo.setTexture(&textura);

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

            jogador->setLento(true);
        }
        void Gosma::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"id\": \"gosma\", \"posicao\": [" << getPosicao().x << ", " << getPosicao().y << "]}";
        }
    }
}