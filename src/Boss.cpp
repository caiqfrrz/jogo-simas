#include "../Entidades/Personagens/Boss.h"

namespace Entidades
{
    namespace Personagens
    {
        Boss::Boss(Listas::ListaEntidades *jog, sf::Vector2f pos) : Inimigo(pos, false),
                                                                    vida(5),
                                                                    velocidadeDir({0, 0}),
                                                                    jogadores(jog),
                                                                    dano(3),
                                                                    recarregar(0),
                                                                    firing(false),
                                                                    vec_proj()
        {
            corpo.setFillColor(sf::Color::Yellow);
            setVida(5);
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
            if (getMorto() == false)
            {
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

                    if (jogador->getMorto() == true)
                    {
                        jogadorMaisProx = *jgd2;
                        float distMaisProx = dist2;
                    }
                    else if (jogador2->getMorto() == true)
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
                        recarregar = 0;
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
                        recarregar = 0;
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

            for (int i = 0; i < vec_proj.size(); i++)
            {
                vec_proj[i].executar();
            }

            if (vec_proj.size() > 50)
            {
                for (int i = 0; i < vec_proj.size() / 2; i++)
                {
                    vec_proj.erase(vec_proj.begin() + i);
                }
            }

            nochao = false;
        }
        void Boss::atirar()
        {
            bolasdefogo();
        }
        std::vector<Projetil> *Boss::getVetProj()
        {
            return &vec_proj;
        }
        void Boss::ultrathrust()
        {
            corpo.setPosition(getPosicao().x + velocidade.x * 5, getPosicao().y + velocidade.y * 5);
        }
        void Boss::bolasdefogo()
        {
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
            Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;

            if (jgd != nullptr && jgd2 != nullptr)
            {
                Entidade *jogadorMaisProx;

                sf::Vector2f pos1 = sf::Vector2f((*jgd)->getPosicao().x, (*jgd)->getPosicao().y);
                sf::Vector2f pos2 = sf::Vector2f((*jgd2)->getPosicao().x, (*jgd2)->getPosicao().y);

                sf::Vector2f cords = sf::Vector2f(this->getPosicao().x, this->getPosicao().y - 50.f);

                float dist1 = sqrt(pow(pos1.x - cords.x, 2) + pow(pos1.y - cords.y, 2));
                float dist2 = sqrt(pow(pos2.x - cords.x, 2) + pow(pos2.y - cords.y, 2));

                Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                Entidades::Personagens::Personagem *jogador2 = static_cast<Entidades::Personagens::Personagem *>(*jgd2);

                if (jogador->getMorto() == true)
                {
                    jogadorMaisProx = *jgd2;
                    float distMaisProx = dist2;
                }
                else if (jogador2->getMorto() == true)
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
                sf::Vector2f direcao = posProx - cords;

                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                if (comprimento != 0)
                {
                    direcao /= comprimento;
                }

                sf::Vector2f velocidadeBola = direcao * 1.f;
                velocidadeDir = velocidadeBola;
            }
            if (jgd2 == nullptr)
            {
                sf::Vector2f pos = sf::Vector2f((*jgd)->getPosicao().x, (*jgd)->getPosicao().y);
                sf::Vector2f cords = sf::Vector2f(this->getPosicao().x, this->getPosicao().y - 50.f);

                sf::Vector2f direcao = pos - cords;

                float dist1 = sqrt(pow(pos.x - cords.x, 2) + pow(pos.y - cords.y, 2));
                float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

                if (comprimento != 0)
                {
                    direcao /= comprimento;
                }
                sf::Vector2f velocidadeBola = direcao * 1.f;
                velocidadeDir = velocidadeBola;
            }

            if (recarregar == 0)
            {
                Projetil novoProj(sf::Vector2f(10, 5), "direita");
                novoProj.setPosicao(sf::Vector2f(this->getPosicao().x, this->getPosicao().y - 50.f));
                novoProj.setVelocidade(sf::Vector2f(velocidadeDir.x * 6, velocidadeDir.y * 6));
                vec_proj.push_back(novoProj);
                firing = false;
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
            }
        }
    }
}