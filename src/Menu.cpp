#include "../Estados/Menus/Menu.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico *Menu::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Menu::Menu(int i, int nb) : 
        Estado(i),
        n_botoes(nb),
        pos(0),
        pressionou(false),
        deselecionado(false),
        saiu(false)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();
            bg = new sf::Sprite();

            fonte->loadFromFile("Design/Fontes/Pixel-Digivolve.otf");
        }
        Menu::~Menu()
        {
            delete fonte;
            delete imagem;
            delete bg;
        }
        void Menu::desenhar()
        {
            /*pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for (auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }*/
        }
        void Menu::executar()
        {
            desenhar();
        }
        void Menu::cima()
        {
            if(!pressionou)
            {
                if (pos > 0)
                {
                    pos--;
                    pressionou = true;
                    textos[pos].setOutlineColor(sf::Color(72, 221, 137));
                    textos[pos].setOutlineThickness(5.f);
                    textos[pos + 1].setOutlineThickness(0);
                    textos[pos + 1].setOutlineColor(sf::Color::Transparent);
                    pressionou = false;
                    deselecionado = false;
                }
            }
            
        }
        void Menu::baixo()
        {
            if(!pressionou)
            {
                if (pos < n_botoes - 1)
                {
                pos++;
                pressionou = true;
                textos[pos].setOutlineColor(sf::Color(72, 221, 137));
                textos[pos].setOutlineThickness(5.f);
                textos[pos - 1].setOutlineThickness(0);
                textos[pos - 1].setOutlineColor(sf::Color::Transparent);
                pressionou = false;
                deselecionado = false;
                } 
            }
        }
    }
}