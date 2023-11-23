#include "../Estados/Menus/MenuJogadores.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuJogadores::MenuJogadores():
        Menu(1)
        {
            set_valores();
        }
        MenuJogadores::~MenuJogadores()
        {

        }
        void MenuJogadores::set_valores()
        {
            pos = 0;
            pressionou = false;
            deselecionado = false;

            fonte->loadFromFile("Design/Fontes/Dungeon-Depths.ttf");
            imagem->loadFromFile("Design/Imagens/menu-jogadores.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Um jogador", "Dois jogadores"};
            textos.resize(2);
            coords = {{368,380}, {365,520}};
            tamanhos = {22,20};

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
        void MenuJogadores::loop_eventos()
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
                    if(pos < 1)
                    {
                        std::cout << "ue" << std::endl;
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
                    if(pos == 1)
                    {
                        pGE->setEstadoAtual(2);
                        saiu = true;
                    }
                }
            }
        }
    }
}