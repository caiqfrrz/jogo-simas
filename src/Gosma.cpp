#include "../Entidades/Obstaculos/Gosma.h"
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
        void Gosma::passando(Entidade* pE)
        {
            sf::Vector2f vel = pE->getVelocidade();

            if(vel.x > 0)
            {
                pE->setVelocidade(pE->getVelocidade() - sf::Vector2f(5, 0));
                std::cout << "entrou dir";
            }
            else if(vel.x < 0)
            {
                pE->setVelocidade(pE->getVelocidade() + sf::Vector2f(5, 0));
                std::cout << "entrou esq";
            }
            else if(vel.x == 0) 
            {
                std::cout << "entrou 0";
            }
        }
    }
}