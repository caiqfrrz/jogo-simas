#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <math.h>
#include <iostream>

#define CR 0.2

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes():
    obstaculos(nullptr),
    jogadores(nullptr),
    inimigos(nullptr)
    {

    }
    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {

    }
    void Gerenciador_Colisoes::colisao_simples()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        bool gosmento = false;
        
        while (jgd != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                Entidades::Obstaculos::Obstaculo* aux2 = static_cast<Entidades::Obstaculos::Obstaculo*>(*obst);
                Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(*jgd);
                if (colidiu(*jgd, *obst))
                {
                    if(aux2->ehGosma())
                    {
                        gosmento = true;
                    }
                    else
                        gosmento = false;

                    if(gosmento)
                    {
                        Entidades::Obstaculos::Gosma* aux2 = static_cast<Entidades::Obstaculos::Gosma*>(*obst);
                        aux2->passando(*jgd, true);
                    }
                    else
                        (aux)->setLento(false);
                    
                    if(aux2->ehDanoso())
                    {
                        Entidades::Obstaculos::Espinho* aux2 = static_cast<Entidades::Obstaculos::Espinho*>(*obst);
                        
                        if(aux->getDamaged() == true)
                            break;

                        aux->setVida(aux->getVida() - aux2->getDano());
                        (aux)->TomarDano();
                    }
                
                    (*jgd)->colidir();
                    (*obst)->colidir();
                }
                    
                obst++;
            }

            inim = inimigos->get_primeiro();
            jgd = jogadores->get_primeiro();

            while(inim != nullptr)
            {
                if(jgd != nullptr)
                {
                    Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*>(*jgd);
                    std::vector<Entidades::Projetil>* pVec = aux->getVetProj();

                    if(pVec->size() > 0)
                    {
                        for(int i = 0; i<pVec->size(); i++)
                        {
                            Entidades::Entidade* proj = static_cast<Entidades::Entidade*>(&pVec->at(i));
                            if(colBala(*inim, proj))
                            {
                                Entidades::Personagens::Personagem* aux2 = static_cast<Entidades::Personagens::Personagem*>(*inim);
                                std::cout << "COLIDIU" << std::endl;
                                if(proj->getAtivo() == true)
                                {
                                    aux2->setVida(aux2->getVida() - 1);
                                    proj->setAtivo(false);
                                }
                                //std::cout << "vida: " << aux2->getVida() << std::endl;
                            }
                        }
                    }
                }
                inim++;
            }
            jgd++;
        }

        inim = inimigos->get_primeiro();

        while (inim != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                Entidades::Personagens::Inimigo* aux = static_cast<Entidades::Personagens::Inimigo*>(*inim);

                if(aux->ehFantasma() == false)
                {
                    if (colidiu(*inim, *obst))
                    {
                        (*inim)->colidir();
                        (*obst)->colidir();
                    }
                }
                if(aux->ehAtirador())
                {
                    Entidades::Personagens::Atirador* aux = static_cast<Entidades::Personagens::Atirador*>(*inim);
                    Entidades::Entidade* proj = static_cast<Entidades::Entidade*>(aux->getProjetil());

                    if(colidiu(proj, *obst))
                    {
                        proj->colidir();
                        proj->setAtivo(false);
                    }
                }
                obst++;
            }
            inim++;
        }

    }
    int Gerenciador_Colisoes::colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
        tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
        d(
            fabs((pos1.x - pos2.x)) - ((tam1.x + tam2.x) / 2.f),
            fabs((pos1.y - pos2.y)) - ((tam1.y + tam2.y) / 2.f)
        );

        if (d.x < 0 && d.y < 0)
        {

            if (d.x < d.y)
            {
                if (pos1.y <= pos2.y)
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y - (tam1.y + tam2.y) / 2));
                    e1->setNochao(true);
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * CR));
                    return 4;
                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y + (tam1.y + tam2.y) / 2));  
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * CR));
                    return 2;
                }
            }
            else
            {
                if (pos1.x >= pos2.x)
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x + (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * CR, e1->getVelocidade().y));
                    return 1;

                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x - (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * CR, e1->getVelocidade().y));
                    return 3;
                }
            }
        }

        return 0;
    }

    int Gerenciador_Colisoes::colBala(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
        tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
        d(
            fabs((pos1.x - pos2.x)) - ((tam1.x + tam2.x) / 2.f),
            fabs((pos1.y - pos2.y)) - ((tam1.y + tam2.y) / 2.f)
        );

        if (d.x < 0 && d.y < 0)
        {
            return 1;
        }

        return 0;
    }

}