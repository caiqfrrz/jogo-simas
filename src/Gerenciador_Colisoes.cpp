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

    void Gerenciador_Colisoes::colInimJogador()
    {
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();

        while(jgd != nullptr)
        {
            while(inim != nullptr)
            {
                if((*inim)->getMorto() == false)
                {
                    if (colidiu(*jgd, *inim))
                    {
                        (*inim)->colidir(*jgd);
                    }
                }
                inim++;
            }
            inim = inimigos->get_primeiro();
            jgd++;
        }
            
    }

    void Gerenciador_Colisoes::colJogadorObs()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();         

        while (jgd != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                if (colidiu(*jgd, *obst))
                {
                    (*obst)->colidir(*jgd);
                }   
                obst++;
            }
            jgd++;
        }
    }

    void Gerenciador_Colisoes::colbalaInim()
    {
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();         

        while (inim != nullptr)
        {
            Entidades::Personagens::Jogador* jgd_atira = static_cast<Entidades::Personagens::Jogador*>(*jgd);
            std::vector<Entidades::Projetil>* pVec = jgd_atira->getVetProj();

            if(pVec->size() > 0)
            {
                for(int i = 0; i<pVec->size(); i++)
                {
                    Entidades::Entidade* proj = static_cast<Entidades::Entidade*>(&pVec->at(i));
                    if((*inim)->getMorto() == false)
                    {
                        if(colisao_projetil(*inim, proj) == 1)
                        { 
                            proj->colidir(*inim);
                        }   
                    } 
                }                
            }
            inim++;
        }

    }

    void Gerenciador_Colisoes::colInimObs()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();         

        while (inim != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                Entidades::Personagens::Inimigo* ini = static_cast<Entidades::Personagens::Inimigo*>(*inim);

                if(ini->ehFantasma() == false)
                    colidiu(*inim, *obst);
                
                obst++;
            }
            inim++;
        }
    }

    void Gerenciador_Colisoes::colbalaObs()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst = obstaculos->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();         

        while (obst != nullptr)
        {
            Entidades::Personagens::Jogador* jgd_atira = static_cast<Entidades::Personagens::Jogador*>(*jgd);
            std::vector<Entidades::Projetil>* pVec = jgd_atira->getVetProj();

            if(pVec->size() > 0)
            {
                for(int i = 0; i<pVec->size(); i++)
                {
                    Entidades::Entidade* proj = static_cast<Entidades::Entidade*>(&pVec->at(i));
                    if(colisao_projetil(*obst, proj) == 1)
                    {
                        proj->colidir(*obst);
                    }   
                }                
            }
            obst++;
        }

    }

    void Gerenciador_Colisoes::colisao()
    {
        colInimJogador();
        colInimObs();
        colbalaInim();
        colJogadorObs();
        colbalaObs();
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

    int Gerenciador_Colisoes::colisao_projetil(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
        tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
        d(
            fabs((pos1.x - pos2.x)) - ((tam1.x + tam2.x) / 2.f),
            fabs((pos1.y - pos2.y)) - ((tam1.y + tam2.y) / 2.f)
        );

        sf::Vector2f somaMetadeRectangle(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);

        if ((d.x - somaMetadeRectangle.x) < 0.0f && (d.y - somaMetadeRectangle.y) < 0.0f)
        {
            return 1;
        }

        return 0;
    }
}
