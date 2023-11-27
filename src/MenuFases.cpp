#include "../Estados/Menus/MenuFases.h"
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        MenuFases::MenuFases() : num_jogadores(1),
                                 pos_horizontal(0),
                                 jgd1("Jogadores: 1"),
                                 jgd2("Jogadores: 2"),
                                 Menu(1, 2)
        {
            deselecionado = true;
            pObs = new Observers::MenuFasesObserver();
            pObs->setMenu(this);
            set_valores();
        }
        MenuFases::~MenuFases()
        {
            pObs = nullptr;
        }
        void MenuFases::set_valores()
        {
            jgd1.setFont(fonte);
            jgd2.setFont(fonte);
            jgd1.setTamanho(48);
            jgd2.setTamanho(48);
            jgd1.setPos(sf::Vector2f(350, 620));
            jgd2.setPos(sf::Vector2f(350, 620));

            imagem->loadFromFile("Design/Imagens/menu-jogadores.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Fase 1", "Fase 2"};
            textos.resize(2);
            coords = {{430, 350}, {427, 500}};
            tamanhos = {50, 50};

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
        void MenuFases::desenhar()
        {
            deselecionado = false;
            pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for (auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
            if (num_jogadores == 1)
            {
                jgd1.executar();
            }
            else
            {
                jgd2.executar();
            }
        }
        void MenuFases::sel_player()
        {
            if (pos_horizontal == 0)
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

        void MenuFases::selecionar()
        {
            if (!deselecionado)
            {
                deselecionado = true;
                if (pos == 0)
                {
                    if (num_jogadores == 1)
                    {
                        Estados::Fases::FasePrimeira* fase1_1p = new Estados::Fases::FasePrimeira(2, false, false);  
                        pGE->setEstadoAtual(2);
                    }
                    else
                    {
                        Estados::Fases::FasePrimeira* fase1_2p = new Estados::Fases::FasePrimeira(2, true, false);
                        pGE->setEstadoAtual(2);
                    }
                        
                    
                }
                else
                {
                    if (num_jogadores == 1)
                    {
                        Estados::Fases::FaseSegunda* fase2_1p = new Estados::Fases::FaseSegunda(3, false, false);
                        pGE->setEstadoAtual(3);
                    }
                    else
                    {
                        Estados::Fases::FaseSegunda* fase2_2p = new Estados::Fases::FaseSegunda(3, true, false);
                        pGE->setEstadoAtual(3);
                    }
                }
            }
        }
    }
}