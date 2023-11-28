#include "../Design/HUD.h"
#include "../Entidades/Personagens/Personagem.h"
#include <iostream>

namespace Design
{
    Gerenciadores::Gerenciador_Grafico *HUD::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

    HUD::HUD() : pJogador(nullptr),
                 pJogador2(nullptr),
                 pPersonagem(nullptr)
    {
        barra_vermelha.setSize(sf::Vector2f(50, 5));
        barra_vermelha.setFillColor(sf::Color::Red);
        barra_verde.setSize(sf::Vector2f(50, 5));
        barra_verde.setFillColor(sf::Color::Green);
    }
    HUD::~HUD()
    {
        pGG = nullptr;
        pJogador2 = nullptr;
        pJogador = nullptr;
        pPersonagem = nullptr;
    }
    void HUD::executar()
    {
        setPosicao();
        if (pPersonagem == pJogador || pPersonagem == pJogador2)
        {
            sf::Texture *hp = new sf::Texture;
            hp->loadFromFile("Design/Imagens/greenbar (1).png");

            barra_verde.setTexture(hp);
            barra_verde.setTextureRect(sf::IntRect(10, 22, 26, 8));
            barra_verde.setSize(sf::Vector2f(pPersonagem->getVida() * var * 6, 30));
            barra_vermelha.setSize(sf::Vector2f(300, 30));
        }
        else
            barra_verde.setSize(sf::Vector2f(pPersonagem->getVida() * var, 5));
        desenhar();
    }
    void HUD::setPers(Entidades::Personagens::Personagem *pPers)
    {
        if (pPers)
        {
            pPersonagem = pPers;
            if(pPersonagem->getVida() > 0)
                var = 50 / pPersonagem->getVida();
            else
                barra_verde.setSize(sf::Vector2f(0,0));
        }
    }
    void HUD::setJg1(Entidades::Personagens::Personagem *pPers)
    {
        if (pPers)
        {
            pJogador = pPers;
            if(pJogador->getVida() > 0)
                var = 50 / pJogador->getVida();

        }
    }
    void HUD::setJg2(Entidades::Personagens::Personagem *pPers)
    {
        if (pPers)
        {
            pJogador2 = pPers;
            if(pJogador2->getVida() > 0)
                var = 50 / pJogador2->getVida();
        }
    }
    void HUD::desenhar()
    {
        pGG->desenhar(&barra_vermelha);
        pGG->desenhar(&barra_verde);
    }
    void HUD::setPosicao()
    {
        if (pPersonagem == pJogador)
        {
            barra_verde.setPosition(sf::Vector2f(pGG->getCentro().x - 500, pGG->getCentro().y - 500));
            barra_vermelha.setPosition(sf::Vector2f(pGG->getCentro().x - 500, pGG->getCentro().y - 500));

            sf::Sprite p1;
            p1.setPosition(sf::Vector2f(barra_verde.getPosition().x, barra_verde.getPosition().y + 40));

            sf::Texture P1;
            P1.loadFromFile("Design/Imagens/P1-24-11-2023 (1).png");
            p1.setTexture(P1);

            p1.scale(sf::Vector2f(0.5, 0.5));
            pGG->desenhar(&p1);
        }
        else if (pPersonagem == pJogador2)
        {
            barra_verde.setPosition(sf::Vector2f(pGG->getCentro().x + 500, pGG->getCentro().y - 500));
            barra_vermelha.setPosition(sf::Vector2f(pGG->getCentro().x + 500, pGG->getCentro().y - 500));
            barra_vermelha.setScale(-1.f, 1.f);
            barra_verde.setScale(-1.f, 1.f);

            sf::Sprite p1;
            p1.setPosition(sf::Vector2f(barra_verde.getPosition().x - 130, barra_verde.getPosition().y + 40));

            sf::Texture P1;
            P1.loadFromFile("Design/Imagens/P2-24-11-2023 (1).png");
            p1.setTexture(P1);

            p1.scale(sf::Vector2f(0.5, 0.5));
            pGG->desenhar(&p1);
        }
        else
        {
            barra_verde.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y - 12.f));
            barra_vermelha.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y - 12.f));
        }
    }

}