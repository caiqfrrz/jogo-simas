#include "../Entidades/Personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador():
        Personagem(),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);
        }
        Jogador::~Jogador()
        {

        }
        void Jogador::executar()
        {
            if(vida >= 0)
            {
                mover();

                if(damaged)
                    if(clock() - 750 > timer)
                    {
                        ResetColor();
                        damaged = false;
                    }
            
            }
            else
            {
                corpo.setFillColor(sf::Color(92, 20, 2));
            }

        }
        void Jogador::mover()
        {
            if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);  
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocidade += sf::Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocidade += sf::Vector2f(-0.1, 0);   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
                velocidade += sf::Vector2f(0, -5.f);    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                velocidade += sf::Vector2f(0, 0.1);  
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }
    }
}
