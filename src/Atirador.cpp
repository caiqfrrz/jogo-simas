#include "../Entidades/Personagens/Atirador.h"   

namespace Entidades
{
    namespace Personagens
    {
        Atirador::Atirador(Listas::ListaEntidades*jog, sf::Vector2f pos):
        Inimigo(pos, false),
        vida(5),
        jogadores(jog),
        dano(2),
        recarregar(0),  
        dir(""),
        firing(false),
        vec_proj()
        {
            corpo.setFillColor(sf::Color::Yellow);
            setVida(5);
            grafico.setPers(static_cast<Personagem*>(this));
        }

        Atirador::~Atirador()
        {

        }
        void Atirador::executar()
        {
            if(!morte)
            {
                grafico.executar();
                desenhar();
                mover();
            }
        }
        void Atirador::colidir()
        {
            //if(getMorto() == false);
        }
        void Atirador::mover()
        {
            if(getAtivo() == true)
            {
                velocidade = sf::Vector2f(1.f, 0);

                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
                Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;

                if(pulando)
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

                    if(jogador->getMorto() == true)
                    {
                        jogadorMaisProx = *jgd2;
                        float distMaisProx = dist2;
                    }
                    else if(jogador2->getMorto() == true)
                    {
                        jogadorMaisProx = *jgd;
                        float distMaisProx = dist1;
                    }
                    else if(dist1 >= dist2)
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
                            firing = true;
                            dir = "direita";
                        }
                        else
                        {
                            firing = true;
                            dir = "esquerda";
                        }
                    }
                    
                    if(dist1 < 350 || dist2 < 350)
                    {
                        corpo.setPosition(getPosicao().x + velocidade.x, getPosicao().y);
                        atirar();
                    }
                    else
                        recarregar = 0;

                
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
                            firing = true;
                            dir = "direita";
                        }
                        else
                        {
                            firing = true;
                            dir = "esquerda";
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
            else
            {
                recarregar--;
                if(recarregar == 0)
                    setAtivo(true);
            }

            for(int i = 0; i < vec_proj.size() ; i++)
            {
                vec_proj[i].executar();
            }

            if(vec_proj.size()>50)
            {
                for(int i = 0; i<vec_proj.size()/2; i++)
                {
                    vec_proj.erase(vec_proj.begin() + i);
                }
            }
        }
        void Atirador::atirar()
        {
            sf::Vector2f z = this->getTamanho() / 2.f;

            if(dir == "direita")
                z.x += 50;
            else
                z.x -= 50;

            if(recarregar == 0)
            {
                Projetil novoProj(sf::Vector2f(10, 5));
                novoProj.setPosicao(sf::Vector2f(this->getPosicao().x+20.f, this->getPosicao().y+15.f));
                novoProj.setDirecao(dir);
                vec_proj.push_back(novoProj);
                firing = false;
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
            }
        }
        Projetil* Atirador::getProjetil()
        {
           // return &novo;
        }
    }
}