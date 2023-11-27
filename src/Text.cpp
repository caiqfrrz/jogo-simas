#include "../Design/Text.h"

namespace Design
{
    Gerenciadores::Gerenciador_Grafico* Text::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

    Text::Text(std::string str)
    {
        texto.setString(str);
        texto.setOrigin(0.f,0.f);
        texto.setPosition(sf::Vector2f(0.f, 0.f));
    }
    Text::~Text()
    {
        pGG = nullptr;
    }
    void Text::executar()
    {
        pGG->desenharText(&texto);
    }
    void Text::setFont(sf::Font* fonte)
    {
        texto.setFont(*fonte);
    }

    void Text::setTamanho(unsigned int tam)
    {
        texto.setCharacterSize(tam);
    }
    void Text::setCor(sf::Color cor)
    {
        texto.setFillColor(cor);
    }
    void Text::setPos(sf::Vector2f pos)
    {
        texto.setPosition(pos);
    }

}