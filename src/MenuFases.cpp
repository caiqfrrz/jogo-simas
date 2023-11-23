#include "../Estados/Menus/MenuFases.h"

namespace Estados
{
    namespace Menus
    {
        MenuFases::MenuFases():
        Menu(2)
        {
            set_valores();
        }
        MenuFases::~MenuFases()
        {

        }
        void MenuFases::set_valores()
        {
            imagem->loadFromFile("Design/Imagens/menu-jogadores.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Fase 1", "Fase 2"};
            textos.resize(2);
            coords = {{388,380}, {385,520}};
            tamanhos = {22,22};

            for(int i = 0; i<textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setPosition(coords[i]);
                textos[i].setCharacterSize(tamanhos[i]);
            }
            textos[0].setOutlineColor(sf::Color::Green);
            textos[0].setOutlineThickness(5.f);
        }
        void MenuFases::loop_eventos()
        {
            sf::Event evento;
            while(pGG->get_Janela()->pollEvent(evento))
            {
                if(evento.type == sf::Event::Closed)
                {
                    pGG->fecharJanela();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressionou)
                {
                    if(pos < 1)
                    {
                        pos++;
                        pressionou = true;
                        textos[pos].setOutlineColor(sf::Color::Green);
                        textos[pos].setOutlineThickness(5.f);
                        textos[pos-1].setOutlineThickness(0);
                        textos[pos-1].setOutlineColor(sf::Color::Transparent);
                        pressionou = false;
                        deselecionado = false;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressionou)
                {
                    if(pos > 0)
                    {
                        pos--;
                        pressionou = true;
                        textos[pos].setOutlineColor(sf::Color::Green);
                        textos[pos].setOutlineThickness(5.f);
                        textos[pos+1].setOutlineThickness(0);
                        textos[pos+1].setOutlineColor(sf::Color::Transparent);
                        pressionou = false;
                        deselecionado = false;
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !deselecionado)
                {
                    deselecionado = true;
                    if(pos == 0)
                    {
                        pGE->setEstadoAtual(3);
                        saiu = true;
                    }
                    if(pos == 1)
                    {
                        pGE->setEstadoAtual(4);
                        saiu = true;
                    }
                }
            }
        }
    }
}