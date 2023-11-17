#include "../Entidades/Personagens/Inim_Medio.h"   

namespace Entidades
{
    namespace Personagens
    {
        Inim_Medio::Inim_Medio(Listas::ListaEntidades*jog, sf::Vector2f pos):
        jogadores(jog),
        Inimigo(pos),
        dano(2),
        recarregar(0),
        num_proj(0),
        firing(false),
        novo(sf::Vector2f(10, 5))
        {
            corpo.setFillColor(sf::Color::Yellow);
        }

        Inim_Medio::~Inim_Medio()
        {

        }
        void Inim_Medio::executar()
        {
            mover();
            atirar();
        }
        void Inim_Medio::mover()
        {
            velocidade = sf::Vector2f(1.f, 0);

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

                if(dist1 >= dist2)
                {
                    jogadorMaisProx = *jgd2;
                    float distMaisProx = dist2;
                }
                else
                {
                    jogadorMaisProx = *jgd;
                    float distMaisProx = dist1;
                }
                sf::Vector2f posProx = jogadorMaisProx->getPosicao();
                sf::Vector2f direcao = posProx - getPosicao();

                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                if (comprimento != 0) 
                {
                    direcao /= comprimento;
                }

                velocidade = direcao * 1.f;
                
                
                if(dist1 < 350 || dist2 < 350)
                {
                    corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                }

                if(!firing)
                {
                    if(getPosicao().x < posProx.x)
                    {
                        novo.setVelocidade(sf::Vector2f(12, 0));
                        firing = true;
                    }
                    else
                    {
                        novo.setVelocidade(sf::Vector2f(-12, 0));
                        firing = true;
                    }
                }
            }
            if(jgd2 == nullptr)
            {
                sf::Vector2f cords = this->getPosicao();
               
                sf::Vector2f pos = (*jgd)->getPosicao();
                sf::Vector2f direcao = pos - getPosicao();

                float dist1 = sqrt(pow(pos.x - cords.x, 2) + pow(pos.y - cords.y, 2));
                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
                    
                if(comprimento != 0)
                {
                    direcao /= comprimento;
                }
                velocidade = direcao * 1.f;

                if(dist1 < 350)
                {
                    corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                }

                if(!firing)
                {
                    if(getPosicao().x < pos.x)
                    {
                        novo.setVelocidade(sf::Vector2f(12, 0));
                        firing = true;
                    }
                    else
                    {
                        novo.setVelocidade(sf::Vector2f(-12, 0));
                        firing = true;
                    }
                }
            }
        }
        void Inim_Medio::atirar()
        {
            sf::Vector2f z = this->getTamanho() / 2.f;

            if(recarregar == 0)
            {
                novo.setPosicao(this->getPosicao() + (z));
                firing = false;
                novo.executar();
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
                novo.executar();
            }
        }
    }
}