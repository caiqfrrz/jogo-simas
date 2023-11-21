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
        Personagem(),
        recarga(0),
        pulando(false),
        pulo(0.f),
        last_key(1),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);

            if (!fonte.loadFromFile("arial.ttf"))
            {
                std::cout << "Nao carregou fonte" << std::endl;
            }
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
            velocidade = sf::Vector2f(0,0);

            std::stringstream x;

            x << "Projeteis: " << vet_proj.size();
            std::string str = x.str();

            Design::Text texto(str);

            texto.setFont(&fonte);
            texto.setCor(sf::Color::White);
            texto.setTamanho(30);
            texto.executar();
            
            if (pulando)
            {
                velocidade += sf::Vector2f(0, -pulo);

                pulo -= 0.8f;

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
                }
                
            } 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && recarga == 0) 
            {
                if(last_key == 0)
                {
                    vet_dir.push_back(false);
                }
                else if (last_key == 1)
                    vet_dir.push_back(true);

                Projetil novoProj(sf::Vector2f(10, 5));
                vet_proj.push_back(novoProj);
                vet_pos.push_back(sf::Vector2f(this->getPosicao().x, this->getPosicao().y + 20.f));
                recarga = TEMPO_RECARGA_JOG;
            }
            //std::cout << "Velocidade: " << velocidade.x << std::endl;

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
                if(fabs(vet_proj[i].getPosicao().x) - fabs(this->getPosicao().x) > 800 || fabs(vet_proj[i].getPosicao().y) - fabs(this->getPosicao().y) > 600)
                {
                    vet_proj.erase(vet_proj.begin() + i);
                    vet_pos.erase(vet_pos.begin() + i);
                    vet_dir.erase(vet_dir.begin() + i);
                }
                if(vet_dir[i] == true)
                {
                    vet_proj[i].setPosicao(vet_pos[i] + sf::Vector2f(12, 0));
                    vet_pos[i] = vet_proj[i].getPosicao();
                    vet_proj[i].desenhar();
                }
                else if(vet_dir[i] == false)
                {
                    vet_proj[i].setPosicao(vet_pos[i] + sf::Vector2f(-12, 0));
                    vet_pos[i] = vet_proj[i].getPosicao();
                    vet_proj[i].desenhar();
                }
                
            }
        }
        std::vector<Projetil>* Jogador::getVetProj()
        {
            return &vet_proj;
        }
    }
}
