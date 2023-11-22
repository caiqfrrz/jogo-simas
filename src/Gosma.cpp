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
        void Gosma::colidir(Entidade* pE)
        {
            Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(pE);

            jogador->setLento(true);;
        }
        void Gosma::passando(Entidade* pE, bool l)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);
            aux->lentidao(l);
            /*if(pE->getVelocidade().x > 0)
            {
                pE->setVelocidade(pE->getVelocidade() - sf::Vector2f(força, 0));
            }
            if(pE->getVelocidade().x < 0)
            {
                pE->setVelocidade(pE->getVelocidade() + sf::Vector2f(força, 0));
            }
            else if(pE->getVelocidade().x == 0)
            {
                std::cout << "vel = 0" << std::endl;
            }*/
        }
    }
}