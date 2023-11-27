#include "../Gerenciadores/Gerenciador_Colisoes.h"

#include <math.h>
#include <iostream>

#define CR 0.2

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes() : obstaculos(nullptr),
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

        while (jgd != nullptr)
        {
            while (inim != nullptr)
            {
                if ((*inim)->getMorte() == false)
                {
                    if (colidiu(*jgd, *inim))
                    {
                        (*inim)->colidir(*jgd, true);
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
                if((*obst)->getAtivo())
                {
                    if (colidiu(*jgd, *obst))
                    {
                        (*obst)->colidir(*jgd, true);
                    }
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
            Entidades::Personagens::Jogador *jgd_atira = static_cast<Entidades::Personagens::Jogador*>(*jgd);
            std::vector<Entidades::Projetil> *pVec = jgd_atira->getVetProj();

            if (pVec != nullptr)
            {
                for (int i = 0; i < pVec->size(); i++)
                {
                    Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVec->at(i));
                    if ((*inim)->getMorte() == false)
                    {
                        if (colisao_projetil(*inim, proj) == true)
                        {
                            proj->colidir(*inim, false);
                        }
                    }
                }
            }
            inim++;
        }
    }

    void Gerenciador_Colisoes::colbalaJgd()
    {
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
        std::vector<Entidades::Projetil> *pVec;

        while (inim != nullptr)
        {
            Entidades::Personagens::Inimigo *inim_atira = static_cast<Entidades::Personagens::Inimigo *>(*inim);
            pVec = inim_atira->getVetProj();

            if (pVec != nullptr)
            {
                while (jgd != nullptr)
                {

                    if (pVec->size() > 0)
                    {
                        for (int i = 0; i < pVec->size(); i++)
                        {
                            Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVec->at(i));
                            if (colisao_projetil(*jgd, proj) == true)
                            {
                                proj->colidir(*jgd, true);
                            }
                        }
                    }
                    jgd++;
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
                Entidades::Personagens::Inimigo *ini = static_cast<Entidades::Personagens::Inimigo *>(*inim);

                if (ini->ehFantasma() == false && (*obst)->getAtivo())
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
        std::vector<Entidades::Projetil> *pVec;

        while (obst != nullptr)
        {
            Entidades::Personagens::Jogador *jgd_atira = static_cast<Entidades::Personagens::Jogador *>(*jgd);
            pVec = jgd_atira->getVetProj();

            if (pVec->size() > 0)
            {
                for (int i = 0; i < pVec->size(); i++)
                {
                    if((*obst)->getAtivo())
                    {
                        Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVec->at(i));
                        if (colisao_projetil(*obst, proj) == true)
                        {
                            proj->colidir(*obst, false);
                            (*obst)->colidir();
                        }
                    }
                }
            }
            obst++;
        }
    }

    void Gerenciador_Colisoes::colbalaInimObs()
    {
        Listas::Lista<Entidades::Entidade>::Iterador obst = obstaculos->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        std::vector<Entidades::Projetil> *pVec;

        while (inim != nullptr)
        {
            Entidades::Personagens::Inimigo *inim_atira = static_cast<Entidades::Personagens::Inimigo *>(*inim);
            pVec = inim_atira->getVetProj();

            if (pVec != nullptr)
            {
                while (obst != nullptr)
                {

                    if (pVec->size() > 0)
                    {
                        for (int i = 0; i < pVec->size(); i++)
                        {
                            if((*obst)->getAtivo())
                            {
                                Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVec->at(i));
                                if (colisao_projetil(*obst, proj) == true)
                                {
                                    proj->colidir();
                                }
                            }
                        }
                    }
                    obst++;
                }
            }
            inim++;
        }
    }

    void Gerenciador_Colisoes::colEscInim()
    {
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro()++;

        if (jgd != nullptr)
        {
            while (inim != nullptr)
            {
                Entidades::Personagens::Jogador *jgd_shield = static_cast<Entidades::Personagens::Jogador*>(*jgd);
                std::deque<Entidades::Escudo> *pDq = jgd_shield->getDqEscudo();

                if (pDq != nullptr)
                {
                    for (int i = 0; i < pDq->size(); i++)
                    {
                        Entidades::Entidade *escudo = static_cast<Entidades::Entidade *>(&pDq->at(i));
                        if (colisao_projetil(*inim, escudo))
                        {
                            escudo->colidir(*inim, false);
                        }
                    }
                }
                inim++;
            }
        }
    }

    void Gerenciador_Colisoes::colEscJgd()
    {
        Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();

        if (jgd2 != nullptr)
        {
            while (jgd != nullptr)
            {
                Entidades::Personagens::Jogador *jgd_shield = static_cast<Entidades::Personagens::Jogador*>(*jgd2);
                std::deque<Entidades::Escudo> *pDq = jgd_shield->getDqEscudo();

                if (pDq != nullptr)
                {
                    for (int i = 0; i < pDq->size(); i++)
                    {
                        Entidades::Entidade *escudo = static_cast<Entidades::Entidade *>(&pDq->at(i));
                        if (colisao_projetil(*jgd, escudo))
                        {
                            escudo->colidir(*jgd, false);
                        }
                    }
                }
                jgd++;
            }
        }
    }

    void Gerenciador_Colisoes::colEscbalaInim()
    {
        Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores->get_primeiro()++;
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();

        if (jgd2 != nullptr)
        {

            Entidades::Personagens::Jogador *jgd_shield = static_cast<Entidades::Personagens::Jogador *>(*jgd2);
            std::deque<Entidades::Escudo> *pDq = jgd_shield->getDqEscudo();

            if (pDq != nullptr)
            {
                for (int i = 0; i < pDq->size(); i++)
                {
                    Entidades::Entidade *escudo = static_cast<Entidades::Entidade *>(&pDq->at(i));

                    while (inim != nullptr)
                    {
                        Entidades::Personagens::Inimigo *inim_atira = static_cast<Entidades::Personagens::Inimigo *>(*inim);
                        std::vector<Entidades::Projetil> *pVec = inim_atira->getVetProj();

                        if (pVec != nullptr)
                        {

                            if (pVec->size() > 0)
                            {
                                for (int i = 0; i < pVec->size(); i++)
                                {
                                    Entidades::Entidade *proj = static_cast<Entidades::Entidade *>(&pVec->at(i));
                                    if (colisao_projetil(escudo, proj) == true)
                                    {
                                        proj->colidir(nullptr, false);
                                    }
                                }
                            }
                        }
                        inim++;
                    }
                }
            }
        }
    }

    void Gerenciador_Colisoes::colisao()
    { 
        chamarColBalas();
        chamarColCorpos();
        chamarColEscudo();
    }

    void Gerenciador_Colisoes::chamarColBalas()
    {
        colbalaInim();
        colbalaJgd();
        colbalaObs();
        colbalaInimObs();
    }
    void Gerenciador_Colisoes::chamarColCorpos()
    {
        colInimJogador();
        colInimObs();
        colJogadorObs();
    }
    void Gerenciador_Colisoes::chamarColEscudo()
    {
        colEscInim();
        colEscJgd();
        colEscbalaInim();
    }
    int Gerenciador_Colisoes::colidiu(Entidades::Entidade *e1, Entidades::Entidade *e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
                     tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
                     d(
                         fabs((pos1.x - pos2.x)) - ((tam1.x + tam2.x) / 2.f),
                         fabs((pos1.y - pos2.y)) - ((tam1.y + tam2.y) / 2.f));

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

    bool Gerenciador_Colisoes::colisao_projetil(Entidades::Entidade *e1, Entidades::Entidade *e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
                     tam1 = e1->getTamanho(), tam2 = e2->getTamanho();

        float left1 = pos1.x;
        float right1 = pos1.x + tam1.x;
        float top1 = pos1.y;
        float bottom1 = pos1.y + tam1.y;

        float left2 = pos2.x;
        float right2 = pos2.x + tam2.x;
        float top2 = pos2.y;
        float bottom2 = pos2.y + tam2.y;

        // Check for intersection
        return (right1 >= left2 && left1 <= right2 &&
                bottom1 >= top2 && top1 <= bottom2);
    }
}
