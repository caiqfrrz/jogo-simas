#include "../Estados/Menus/MenuPrincipal.h"
#include <iostream>
#include <fstream>

#define ARQUIVO_JOGADOR "Saves/jogadores.json"

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal():
        Menu(0, 4)
        {
            pObs = new Observers::MenuPrincipalObserver();
            pObs->setMenu(this);
            set_valores();
        }
        MenuPrincipal::~MenuPrincipal()
        {
            pObs = nullptr;
        }
        void MenuPrincipal::set_valores()
        {
            imagem->loadFromFile("Design/Imagens/menu-2.jpg");

            bg->setTexture(*imagem);

            opcoes = {"Novo jogo", "Continuar", "Ranking", "Sair"};
            textos.resize(4);
            coords = {{342,155}, {372,353}, {405,500}, {452,645}};
            tamanhos = {60,50,50,50};

            for(int i = 0; i<textos.size(); i++)
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
            if(!deselecionado)
            {
                deselecionado = true;
                if(pos == 0)
                {
                    pGE->setEstadoAtual(1);
                }
                if(pos == 1)
                {
                    infosSave();
                }
                if(pos == 3)
                {
                    pGG->fecharJanela();
                }
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
        }
        void MenuPrincipal::infosSave()
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            nlohmann::json json;

            if (!arquivo.is_open()) {
                std::cout << "Falha ao abrir o arquivo JSON" << std::endl;
                exit(1);
            }

            if (!(arquivo >> json)) {
                std::cout << "Erro ao fazer parsing do JSON" << std::endl;
                exit(2);
            }

            int fase = json["fase"];
            int n_jogadores = json["n_jogadores"];

            if(fase == 1)
            {
                if(n_jogadores == 1)
                {
                    Estados::Fases::FasePrimeira* fase1_1p = new Estados::Fases::FasePrimeira(2, false, true);
                }
                else
                {
                    Estados::Fases::FasePrimeira* fase1_2p = new Estados::Fases::FasePrimeira(2, true, true);
                }
                pGE->setEstadoAtual(2);
            }
            else
            {
                if(n_jogadores == 1)
                {
                    Estados::Fases::FaseSegunda* fase2_1p = new Estados::Fases::FaseSegunda(3, false, true);
                }
                else
                {
                    Estados::Fases::FaseSegunda* fase2_2p = new Estados::Fases::FaseSegunda(3, true, true);
                }
                pGE->setEstadoAtual(3);
            }
        }
    }
}