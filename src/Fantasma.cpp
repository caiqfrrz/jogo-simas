#include "../Entidades/Personagens/Fantasma.h"

//mudanca
namespace Entidades
{
    namespace Personagens
    {
        Fantasma::Fantasma(Listas::ListaEntidades*jog, sf::Vector2f pos, int dano):
        Inimigo(pos, true, dano),
        jogadores(jog)
        {
            setVida(2);
            corpo.setFillColor(sf::Color::Magenta);
            grafico.setPers(static_cast<Personagem*>(this));
        }

        Fantasma::~Fantasma()
        {

        }
        void Fantasma::colidir(Entidade* pE, bool b)
        {
            Personagem* jogador = static_cast<Personagem*>(pE);

            if(getMorto() == false)
                jogador->TomarDano(dano, b);
        }

        void Fantasma::executar()
        {
            if(!morte)
            {
                grafico.executar();
                mover();
                desenhar();
            }
        }

        void Fantasma::mover()
        {
            
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
            Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;


            if(jgd != nullptr && jgd2 != nullptr)
            {
                Entidade* jogadorMaisProx;

                sf::Vector2f pos1 = (*jgd)->getPosicao();
                sf::Vector2f pos2 = (*jgd2)->getPosicao();

                sf::Vector2f cords = this->getPosicao();

                float dist1 = sqrt(pow(pos1.x - cords.x, 2) + pow(pos1.y - cords.y, 2));
                float dist2 = sqrt(pow(pos2.x - cords.x, 2) + pow(pos2.y - cords.y, 2));

                Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(*jgd); 
                Entidades::Personagens::Personagem* jogador2 = static_cast<Entidades::Personagens::Personagem*>(*jgd2); 
                
                float distMaisProx = 0;

                if(jogador->getMorto() == true)
                {
                    jogadorMaisProx = *jgd2;
                    distMaisProx = dist2;
                }
                else if(jogador2->getMorto() == true)
                {
                    jogadorMaisProx = *jgd;
                    distMaisProx = dist1;
                }
                else if(dist1 >= dist2)
                {
                    jogadorMaisProx = *jgd2;
                    distMaisProx = dist2;
                }
                else
                {
                    jogadorMaisProx = *jgd;
                    distMaisProx = dist1;
                }

                sf::Vector2f posProx = jogadorMaisProx->getPosicao();
                sf::Vector2f direcao = posProx - getPosicao();

                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                if (comprimento != 0) 
                {
                    direcao /= comprimento;
                }

                velocidade = direcao * 1.f;

                if(distMaisProx <= 350)
                    corpo.setPosition(corpo.getPosition() + velocidade);
            }
            if(jgd2 == nullptr)
            {
                sf::Vector2f pos = (*jgd)->getPosicao();
                sf::Vector2f direcao = pos - getPosicao();

                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                if(comprimento != 0)
                {
                    direcao /= comprimento;
                }
                velocidade = direcao * 1.f;

                corpo.setPosition(corpo.getPosition() + velocidade);
            }
        }
    }
}

