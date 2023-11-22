#include "../Entidades/Personagens/Jogador2.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador2::Jogador2():
        Personagem(sf::Vector2f(0, 0),false, true),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);
        }
        Jogador2::~Jogador2()
        {

        }
        void Jogador2::executar()
        {
            if(!morte)
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
        void Jogador2::mover()
        {
            velocidade = sf::Vector2f(0,0);
            
            if (pulando)
            {
                velocidade += sf::Vector2f(0, -pulo);

                pulo -= 0.8f;
                nochao = false;
                if(pulo <= 0)
                {
                    pulando = false;
                }
            }
            if (!nochao)
                velocidade += sf::Vector2f(0, 7.f);
           
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if(lento)
                {
                    if (!nochao)
                    {
                        velocidade += sf::Vector2f(2.f, 0);
                    }
                }
                else
                {
                    if (nochao)
                    {
                        velocidade = sf::Vector2f(6.f, 0);
                    }
                    else if (!nochao)
                    {
                        velocidade += sf::Vector2f(6.f, 0);
                    }
                }
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if(lento)
                {
                    if (!nochao)
                    {
                        velocidade += sf::Vector2f(-2.f, 0);
                    }
                }
                else
                {
                    if (nochao)
                    {
                        velocidade = sf::Vector2f(-6.f, 0);
                    }
                    else if (!nochao)
                    {
                        velocidade += sf::Vector2f(-6.f, 0);
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && nochao)
            {
                if(lento)
                {
                    pulando = true;
                    pulo = 15.f;
                }
                else
                {
                    pulando = true;
                    pulo = 21.f;
                    nochao = true;
                }
            }

            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }
    }
}