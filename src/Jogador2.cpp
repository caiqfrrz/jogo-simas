#include "../Entidades/Personagens/Jogador2.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador2::Jogador2():
        Personagem(),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);
        }
        Jogador2::~Jogador2()
        {

        }
        void Jogador2::executar()
        {
            mover();

            if(damaged)
                if(clock() - 750 > timer)
                {
                    ResetColor();
                    damaged = false;
                }
        }
        void Jogador2::mover()
        {
            if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);  
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                velocidade += sf::Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocidade += sf::Vector2f(-0.1, 0);   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && nochao)
                velocidade += sf::Vector2f(0, -5.f);    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                velocidade += sf::Vector2f(0, 0.1);  
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }
    }
}