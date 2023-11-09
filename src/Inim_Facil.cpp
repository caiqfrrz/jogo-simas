#include "../Entidades/Personagens/Inim_Facil.h"
//mudanca
namespace Entidades
{
    namespace Personagens
    {
        Inim_Facil::Inim_Facil(Listas::ListaEntidades*jog, sf::Vector2f pos):
        jogadores(jog),
        Inimigo(pos),
        vida(1),
        dano(1)
        {
            corpo.setFillColor(sf::Color::Magenta);
        }

        Inim_Facil::~Inim_Facil()
        {

        }

        void Inim_Facil::executar()
        {
            mover();
        }

        void Inim_Facil::mover()
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

