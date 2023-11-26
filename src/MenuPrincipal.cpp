#include "../Estados/Menus/MenuPrincipal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal(Estados::Menus::Ranking *pR) : Menu(0, 4),
                                                                    pRanking(pR)
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
            imagem->loadFromFile("Design/Imagens/menu-2.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Novo jogo", "Continuar", "Ranking", "Sair"};
            textos.resize(4);
            coords = {{342, 155}, {372, 353}, {405, 500}, {452, 645}};
            tamanhos = {60, 50, 50, 50};

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
        void MenuPrincipal::selecionar()
        {
            if (!deselecionado)
            {
                deselecionado = true;
                if (pos == 0)
                {
                    pGE->setEstadoAtual(1);
                }
                if (pos == 2)
                {
                    usarfuncaoreSize(pRanking, ARQUIVO_COLOCACAO_1);
                    usarfuncaoCriarTextos(pRanking, ARQUIVO_COLOCACAO_1);
                    pGE->setEstadoAtual(6);
                }
                if (pos == 3)
                {
                    pGG->fecharJanela();
                }
            }
        }
        void MenuPrincipal::usarfuncaoreSize(Estados::Menus::Ranking *objRanking, std::string caminho)
        {
            objRanking->reSize(caminho);
        }
        void MenuPrincipal::usarfuncaoCriarTextos(Estados::Menus::Ranking *objRanking, std::string caminho)
        {
            objRanking->CriarTextos(caminho);
        }
        void MenuPrincipal::desenhar()
        {
            pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for (auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
        }
    }
}