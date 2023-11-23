#include "../Estados/Menus/MenuPrincipal.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal():
        Menu(0)
        {
            set_valores();
            std::cout << id << std::endl;
        }
        MenuPrincipal::~MenuPrincipal()
        {

        }
        void MenuPrincipal::set_valores()
        {
            imagem->loadFromFile("Design/Imagens/menu-2.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Novo jogo", "Continuar", "Ranking", "Sair"};
            textos.resize(4);
            coords = {{342,185}, {366,380}, {400,520}, {450,670}};
            tamanhos = {30,24,24,24};

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
        void MenuPrincipal::loop_eventos()
        {
            sf::Event evento;
            while(pGG->get_Janela()->pollEvent(evento))
            {
                std::cout << pos << std::endl;
                if(evento.type == sf::Event::Closed)
                {
                    pGG->fecharJanela();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressionou)
                {
                    if(pos < 3)
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
                        pGE->setEstadoAtual(1);
                        saiu = true;
                    }
                    if(pos == 3)
                    {
                        pGG->fecharJanela();
                    }
                }
            }
        }
    }
}