#include "../Entidades/Escudo.h"
#include <iostream>

namespace Entidades
{
    Escudo::Escudo(std::string dir, sf::Vector2f pos, bool lanc, int cont, short int opac, bool par) : Entidade(pos),
                       lancando(lanc),
                       direcao(dir),
                       desapareceu(false),
                       parou(par),
                       opacidade(opac),
                       contagem(cont)
    {
        ajustarTam();
    }
    Escudo::~Escudo()
    {
    }
    void Escudo::executar()
    {
        if (lancando)
        {
            if (direcao == "direita")
            {
                if (contagem >= 0)
                {
                    corpo.move(sf::Vector2f(VEL_ESCUDO, 0));
                    contagem--;
                }
                else
                {
                    parou = true;
                    lancando = false;
                    contagem = CONTAGEM_PARAR;
                }
            }
            else if (direcao == "esquerda")
            {
                if (contagem >= 0)
                {
                    corpo.move(sf::Vector2f(-VEL_ESCUDO, 0));
                    contagem--;
                }
                else
                {
                    parou = true;
                    lancando = false;
                    contagem = CONTAGEM_PARAR;
                }
            }
            else if(direcao == "cima")
            {
                if (contagem >= 0)
                {
                    corpo.move(sf::Vector2f(0, -VEL_ESCUDO));
                    contagem--;
                }
                else
                {
                    parou = true;
                    lancando = false;
                    contagem = CONTAGEM_PARAR;
                }
            }
        }
        if (parou)
        {
            desaparecer();
        }
        desenhar();
    }
    void Escudo::setDirecao(std::string dir)
    {
        direcao = dir;
        ajustarTam();
    }
    void Escudo::ajustarTam()
    {
        if(direcao == "esquerda")
        {
            corpo.setSize(sf::Vector2f(LARGURA_ESCUDO, COMPRIMENTO_ESCUDO));
        }
        else if (direcao == "direita")
        {
            corpo.setSize(sf::Vector2f(LARGURA_ESCUDO, COMPRIMENTO_ESCUDO));
        }
        else if (direcao == "cima")
        {
            corpo.setSize(sf::Vector2f(COMPRIMENTO_ESCUDO, LARGURA_ESCUDO));
        }
    }
    void Escudo::lancar()
    {
        lancando = true;
    }
    void Escudo::desaparecer()
    {
        if (opacidade > 0)
        {
            corpo.setFillColor(sf::Color(255, 255, 255, opacidade));
            opacidade -= 0.7;
        }
        else
            desapareceu = true;
    }
    void Escudo::colidir(Entidade *pE, bool b)
    {
        sf::Vector2f z = pE->getPosicao();
        pE->setVelocidade(sf::Vector2f(0, 0));
        pE->setNochao(true);
        if (direcao == "direita")
        {
            if (z.y + pE->getTamanho().y >= this->getPosicao().y + 5)
            {
                z.x += 7.f;
                pE->setPosicao(z);
            }
            else
            {
                z.y -= 7.f;
                pE->setPosicao(z);
            }
        }
        else if (direcao == "esquerda")
        {
            if (z.y + pE->getTamanho().y >= this->getPosicao().y + 5)
            {
                z.x -= 7.f;
                pE->setPosicao(z);
            }
            else
            {
                z.y -= 7.f;
                pE->setPosicao(z);
            }
        }
        else if(direcao == "cima")
        {
            z.y -= 7.f;
            pE->setPosicao(z);
        }
    }
    bool Escudo::getDesapareceu()
    {
        return desapareceu;
    }
    void Escudo::salvar(std::ostringstream* entrada)
    {
        if(!desapareceu)
        {
            (*entrada) << "{\"posicao\": [" << getPosicao().x << "," << getPosicao().y << "], \"direcao\": \"" << direcao << "\", \"contagem\": "<< contagem << ",\"opacidade\": "<< opacidade <<", \"lancando\": "<< lancando <<", \"parou\": " << parou << "}";
        }
    }
}