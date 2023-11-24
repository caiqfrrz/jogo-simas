#include "../Estados/Menus/MenuFases.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuFases::MenuFases():
        Menu(1, 2)
        {
            deselecionado = true;
            pObs = new Observers::MenuFasesObserver();
            pObs->setMenu(this);
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
        void MenuFases::desenhar()
        {
            deselecionado = false;
            pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for(auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
        }
        
        void MenuFases::selecionar()
        {
            if(!deselecionado)
            {
                deselecionado = true;
                if(pos == 0)
                {
                    pGE->setEstadoAtual(2);
                }
                else
                {
                    pGE->setEstadoAtual(3);
                }
            }
        }
    }
}