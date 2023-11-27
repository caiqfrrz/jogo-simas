#include "../Estados/Menus/MenuPausa.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuPausa::MenuPausa():
        Menu(4,2)
        {
            pObs = new Observers::MenuPausaObserver();
            pObs->setMenu(this);
            set_valores();
        }
        MenuPausa::~MenuPausa()
        {

        }
        void MenuPausa::set_valores()
        {
            imagem->loadFromFile("Design/Imagens/menu-jogadores.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Continuar", "Menu principal"};
            textos.resize(2);
            coords = {{378, 350}, {360, 510}};
            tamanhos = {50, 38};

            for (int i = 0; i < textos.size(); i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setString(opcoes[i]);
                textos[i].setPosition(coords[i]);
                textos[i].setCharacterSize(tamanhos[i]);
            }
            textos[0].setOutlineColor(sf::Color(72, 221, 137));
            textos[0].setOutlineThickness(5.f);
        }
        void MenuPausa::desenhar()
        {
            pGG->limpar();
            pGG->resetarCamera();
            pGG->desenhar(bg);
            for (auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
        }
        void MenuPausa::selecionar()
        {
            if(!deselecionado)
            {
                deselecionado = true;
                if(pos == 0)
                {
                    pGE->setEstadoAtual(pGE->getEstadoAnterior());
                }
                else if(pos == 1)
                {
                    pGE->pausePMenu();
                }
            }
        }
    }
}