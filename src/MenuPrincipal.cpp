#include "../Estados/Menus/MenuPrincipal.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal():
        Menu(0, 4),
        num_jogadores(1),
        pos_horizontal(0),
        jgd1("Jogadores: 1"),
        jgd2("Jogadores: 2")
        {
            pObs = new Observers::MenuPrincipalObserver();
            pObs->setMenu(this);
            set_valores();
        }
        MenuPrincipal::~MenuPrincipal()
        {

        }
        void MenuPrincipal::set_valores()
        {
            jgd1.setFont(fonte);
            jgd2.setFont(fonte);
            jgd1.setTamanho(18);
            jgd2.setTamanho(18);
            jgd1.setPos(sf::Vector2f(409, 744));
            jgd2.setPos(sf::Vector2f(409, 744));

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
        void MenuPrincipal::selecionar()
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
        void MenuPrincipal::sel_player()
        {
            if(pos_horizontal == 0)
            {
                pos_horizontal = 1;
                pressionou = true;
                num_jogadores = 2;
                pressionou = false;
                deselecionado = false;
            }
            else
            {
                pos_horizontal = 0;
                pressionou = true;
                num_jogadores = 1;
                pressionou = false;
                deselecionado = false;
            }
        }
        void MenuPrincipal::desenhar()
        {
            pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for(auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
            if(num_jogadores == 1)
            {
                jgd1.executar();
            }
            else
            {
                jgd2.executar();
            }
        }
    }
}