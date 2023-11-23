#include "../Entidades/Personagens/Jogador2.h"
#define TEMPO_RECARREGAR 300

namespace Entidades
{
    namespace Personagens
    {
        Jogador2::Jogador2():
        Personagem(sf::Vector2f(0, 0),false, true),
        fila_escudo(),
        direcao(1),
        escudos(0),
        recarregar(0),
        pontos(0)
        {
            corpo.setFillColor(sf::Color::Green);
            grafico.setPers(static_cast<Personagem*>(this));
        }
        Jogador2::~Jogador2()
        {

        }
        void Jogador2::executar()
        {
            if(!morte)
            {
                grafico.executar();
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
                direcao = 1;
                
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
                direcao = 0;
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                direcao = 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
            {
                if(recarregar == 0)
                {    
                    Escudo aux_escudo = Escudo();
                    aux_escudo.setDirecao(direcao);
                    switch(direcao)
                    {
                        case(2):
                        {
                            aux_escudo.setPosicao(sf::Vector2f(getPosicao().x-2.5f, getPosicao().y-7.f));
                            break;
                        }
                        case(1):
                        {
                            aux_escudo.setPosicao(sf::Vector2f(getPosicao().x+57.f, getPosicao().y-2.5f));
                            break;
                        }
                        case(0):
                        {
                            aux_escudo.setPosicao(sf::Vector2f(getPosicao().x-7.f, getPosicao().y-2.5f));
                            break;
                        }
                    }
                    aux_escudo.lancar();
                    fila_escudo.push_back(aux_escudo);

                    if(escudos == 2)
                    {
                        recarregar = TEMPO_RECARREGAR;
                        escudos = 0;
                    }
                    else
                    {
                        escudos++;
                        recarregar = 25; 
                    }
                           
                }
            }
            else if(recarregar > 0)
                recarregar--;

            lancar_escudos();
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }
        void Jogador2::lancar_escudos()
        {
            std::deque<Escudo>::iterator it;
            for(it = fila_escudo.begin(); it != fila_escudo.end(); it++)
            {
                (*it).executar();
                if((*it).getDesapareceu())
                    fila_escudo.pop_front();
            }
        }
    }
}