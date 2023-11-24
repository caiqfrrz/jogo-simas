#include "../Design/HUD.h"
#include "../Entidades/Personagens/Personagem.h"
#include <iostream>

namespace Design
{
    Gerenciadores::Gerenciador_Grafico* HUD::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

    HUD::HUD():
    pJogador(nullptr),
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

    }
    void HUD::executar()
    {
        setPosicao();
        if(pPersonagem == pJogador || pPersonagem == pJogador2)
        {
            sf::Texture *hp = new sf::Texture;
            hp->loadFromFile("Design/Imagens/greenbar (1).png");

            barra_verde.setTexture(hp);
            barra_verde.setTextureRect(sf::IntRect(10,22,26,8));
            barra_verde.setSize(sf::Vector2f(pPersonagem->getVida()*var * 5, 30));
            barra_vermelha.setSize(sf::Vector2f(250, 30));
        }
        else
            barra_verde.setSize(sf::Vector2f(pPersonagem->getVida()*var, 5));
        desenhar();
    }
    void HUD::setPers(Entidades::Personagens::Personagem* pPers)
    {
        if(pPers)
            pPersonagem = pPers;

        var = 50/pPersonagem->getVida();
    }
    void HUD::setJg1(Entidades::Personagens::Personagem* pPers)
    {
        if(pPers)
            pJogador = pPers;

        var = 50/pJogador->getVida();
    }
    void HUD::setJg2(Entidades::Personagens::Personagem* pPers)
    {
        if(pPers)
            pJogador2 = pPers;

        var = 50/pJogador2->getVida();
    }
    void HUD::desenhar()
    {
        pGG->desenhar(&barra_vermelha);
        pGG->desenhar(&barra_verde);
    }
    void HUD::setPosicao()
    {
        if(pPersonagem == pJogador)
        {
            barra_verde.setPosition(sf::Vector2f(pGG->getCentro().x - 500,pGG->getCentro().y - 500));
            barra_vermelha.setPosition(sf::Vector2f(pGG->getCentro().x - 500,pGG->getCentro().y - 500));
        }
        else if(pPersonagem == pJogador2)
        {
            barra_verde.setPosition(sf::Vector2f(pGG->getCentro().x + 250,pGG->getCentro().y - 500));
            barra_vermelha.setPosition(sf::Vector2f(pGG->getCentro().x + 250,pGG->getCentro().y - 500));
        }
        else
        {
            barra_verde.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y-12.f));
            barra_vermelha.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y-12.f));
        }
    }

}