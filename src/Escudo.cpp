#include "../Entidades/Escudo.h"

namespace Entidades
{
    Escudo::Escudo():
    Entidade(),
    lancando(false),
    direcao(-1),
    desapareceu(false),
    parou(false),
    opacidade(255),
    contagem(CONTAGEM_PARAR)
    {
    }
    Escudo::~Escudo()
    {

    }
    void Escudo::executar()
    {
        if(lancando)
        {
            if(direcao == 1)
            {
                corpo.setSize(sf::Vector2f(LARGURA_ESCUDO, COMPRIMENTO_ESCUDO));
                if(contagem >= 0)
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
            else if(direcao == 0)
            {
                corpo.setSize(sf::Vector2f(LARGURA_ESCUDO, COMPRIMENTO_ESCUDO));
                if(contagem >= 0)
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
            else
            {
                corpo.setSize(sf::Vector2f(COMPRIMENTO_ESCUDO, LARGURA_ESCUDO));
                if(contagem >= 0)
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
        if(parou)
        {
            desaparecer();
        }
        desenhar();

    }
    void Escudo::setDirecao(short int dir)
    {
        direcao = dir;
    }
    void Escudo::lancar()
    {
        lancando = true;
    }
    void Escudo::desaparecer()
    {
        if(opacidade > 0)
        {
            corpo.setFillColor(sf::Color(255, 255, 255, opacidade));
            opacidade--;
        }
        else
            desapareceu = true;
    }
    /*void Escudo::getDano()
    {
        return dano;
    }*/
    void Escudo::colidir()
    {

    }
    bool Escudo::getDesapareceu()
    {
        return desapareceu;
    }
}