#include "../Entidades/Personagens/Atirador.h"   

namespace Entidades
{
    namespace Personagens
    {
        Atirador::Atirador(Listas::ListaEntidades*jog, sf::Vector2f pos):
        Inimigo(pos, false, true),
        vida(5),
        jogadores(jog),
        dano(2),
        recarregar(0),
        firing(false),
        novo(sf::Vector2f(10, 5))
        {
            corpo.setFillColor(sf::Color::Yellow);
            setVida(5);
        }

        Atirador::~Atirador()
        {

        }
        void Atirador::executar()
        {
            if(getVida() <= 0)
            {
                corpo.setFillColor(sf::Color::Transparent);
            }
            else
                mover();
            //atirar();
        }
        void Atirador::mover()
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
                
                if(dist1 < 350 || dist2 < 350)
                {
                    corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                    atirar();
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

                if(dist1 < 450)
                {
                    corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                    atirar();
                }
                else
                    recarregar = 0;
            }
        }
        void Atirador::atirar()
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
        Projetil* Atirador::getProjetil()
        {
            return &novo;
        }
    }
}