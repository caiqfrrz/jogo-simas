#include "../Entidades/Personagens/Boss.h"
#include <sstream>

namespace Entidades
{
    namespace Personagens
    {
        Boss::Boss(Listas::ListaEntidades *jog, Listas::ListaEntidades *inim, sf::Vector2f pos, sf::Vector2f vel, int dano) :
        Inimigo(pos, vel, false, dano),
        velocidadeDir({0, 0}),
        jogadores(jog),
        inimigos(inim),
        recarregar(0),
        firing(false)
        {
            corpo.setFillColor(sf::Color::Yellow);
            setVida(10);
            grafico.setPers(static_cast<Personagem *>(this));
        }

        Boss::~Boss()
        {
            
        }
        void Boss::executar()
        {
            if (!morte)
            {
                grafico.executar();
                desenhar();
                mover();
            }
        }
        void Boss::colidir(Entidade *pE, bool b)
        {
            if (getMorte() == false)
            {
                Personagem *jogador = static_cast<Personagem *>(pE);

                if (getMorte() == false)
                    jogador->TomarDano(dano, b);
            }
        }
        void Boss::mover()
        {
            if (getAtivo() == true)
            {
                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
                Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;

                if (pulando)
                {
                    velocidade += sf::Vector2f(0, -pulo);
                    pulo -= 0.8f;
                    nochao = false;
                    if (pulo <= 0)
                    {
                        pulando = false;
                    }
                }

                if (!nochao)
                    velocidade += sf::Vector2f(0, 0.1f);
                else
                    velocidade.y = 0;

                if (jgd != nullptr && jgd2 != nullptr)
                {
                    Entidade *jogadorMaisProx;

                    sf::Vector2f pos1 = (*jgd)->getPosicao();
                    sf::Vector2f pos2 = (*jgd2)->getPosicao();

                    sf::Vector2f cords = this->getPosicao();

                    float dist1 = sqrt(pow(pos1.x - cords.x, 2) + pow(pos1.y - cords.y, 2));
                    float dist2 = sqrt(pow(pos2.x - cords.x, 2) + pow(pos2.y - cords.y, 2));

                    Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                    Entidades::Personagens::Personagem *jogador2 = static_cast<Entidades::Personagens::Personagem *>(*jgd2);

                    if (jogador->getMorte() == true)
                    {
                        jogadorMaisProx = *jgd2;
                        float distMaisProx = dist2;
                    }
                    else if (jogador2->getMorte() == true)
                    {
                        jogadorMaisProx = *jgd;
                        float distMaisProx = dist1;
                    }
                    else if (dist1 >= dist2)
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

                    velocidade.x = direcao.x * 1.f;

                    if (!firing)
                    {
                        firing = true;
                    }

                    if (dist1 < 450 || dist2 < 450)
                    {
                        corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                        atirar();
                    }
                    else if (dist1 < 800 || dist2 < 800)
                    {
                        velocidade = direcao;
                        ultrathrust();
                    }
                    else
                        recarregar = 0;
                }
                if (jgd2 == nullptr)
                {
                    sf::Vector2f cords = this->getPosicao();

                    sf::Vector2f pos = (*jgd)->getPosicao();
                    sf::Vector2f direcao = pos - getPosicao();

                    float dist1 = sqrt(pow(pos.x - cords.x, 2) + pow(pos.y - cords.y, 2));
                    float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                    if (comprimento != 0)
                    {
                        direcao /= comprimento;
                    }
                    velocidade.x = direcao.x * 1.f;

                    if (!firing)
                    {
                        firing = true;
                    }

                    if (dist1 < 450)
                    {
                        corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                        atirar();
                    }
                    else if (dist1 < 800)
                    {
                        velocidade = direcao;
                        ultrathrust();
                    }
                    else
                        recarregar = 0;
                }
            }
            else
            {
                recarregar--;
                if (recarregar == 0)
                    setAtivo(true);
            }

            corpo.setPosition(getPosicao().x, getPosicao().y + velocidade.y);

            nochao = false;
        }
        void Boss::atirar()
        {
            if (recarregar == 0)
            {
                auto aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Fantasma(jogadores, sf::Vector2f(this->getPosicao().x, this->getPosicao().y - 70.f)));
                if (aux)
                    inimigos->incluir(aux);
                firing = false;
                recarregar = TEMPO_RECARGABOSS;
            }
            else
            {
                recarregar--;
            }
        }
        void Boss::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"id\": \"chefao\", \"morto\": " << morte << ", \"posicao\": [" << getPosicao().x << ", " << getPosicao().y << "], \"velocidade\": [" << velocidade.x << ", " << velocidade.y << "]}";

        }
        void Boss::ultrathrust()
        {
            corpo.setPosition(getPosicao().x + velocidade.x * 5, getPosicao().y + velocidade.y * 5);
        }
    }
}