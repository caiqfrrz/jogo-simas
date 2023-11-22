#include "../Design/HUD.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Design
{
    Gerenciadores::Gerenciador_Grafico* HUD::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

    HUD::HUD():
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
        barra_verde.setSize(sf::Vector2f(pPersonagem->getVida()*var, 5));
        desenhar();
    }
    void HUD::setPers(Entidades::Personagens::Personagem* pPers)
    {
        if(pPers)
            pPersonagem = pPers;

        var = 50/pPersonagem->getVida();
    }
    void HUD::desenhar()
    {
        pGG->desenhar(&barra_vermelha);
        pGG->desenhar(&barra_verde);
    }
    void HUD::setPosicao()
    {
        barra_verde.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y-12.f));
        barra_vermelha.setPosition(sf::Vector2f(pPersonagem->getPosicao().x, pPersonagem->getPosicao().y-12.f));
    }

}