#include "../Entidades/Personagens/Jogador.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador():
        Personagem(sf::Vector2f(0, 0),true, false),
        recarga(0),
        last_key(1),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);
            grafico.setJg1(static_cast<Personagem*>(this));
            grafico.setPers(static_cast<Personagem*>(this));
        }
        Jogador::~Jogador()
        {

        }
        void Jogador::executar()
        {
            if(!morte)
            {
                grafico.executar();
                mover();

                if(damaged)
                    if(clock() - 1500 > timer)
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
           
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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
                last_key = 1;
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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
                last_key = 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                last_key = 3;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && recarga == 0) 
            {
                Projetil novoProj(sf::Vector2f(10, 5));

                if(last_key == 0)
                {
                    novoProj.setDirecao("esquerda");
                }
                else if (last_key == 1)
                    novoProj.setDirecao("direita");
                else
                {
                    Projetil novoProj(sf::Vector2f(5, 10));
                    novoProj.setDirecao("cima");
                }
                novoProj.setPosicao(sf::Vector2f(this->getPosicao().x+20.f, this->getPosicao().y+15.f));
                vet_proj.push_back(novoProj);
                recarga = TEMPO_RECARGA_JOG;
            }

            if(recarga > 0)
                recarga--;

            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
            atirar();
        }
        

        void Jogador::atirar()
        {
            for(int i = 0; i < vet_proj.size(); i++)
            {
                vet_proj[i].executar();
            }

            for(int i = 0; i < vet_proj.size(); i++)
            {
                if(fabs(vet_proj[i].getPosicao().x) - fabs(this->getPosicao().x) > 800 || fabs(vet_proj[i].getPosicao().y) - fabs(this->getPosicao().y) > 600)
                {
                    vet_proj.erase(vet_proj.begin() + i);
                }
            }
        }
        std::vector<Projetil>* Jogador::getVetProj()
        {
            return &vet_proj;
        }
    }
}
