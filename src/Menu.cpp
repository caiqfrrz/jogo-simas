#include "../Estados/Menus/Menu.h"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Menu::Menu():
        Estado(0)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();
            bg = new sf::Sprite();
            set_valores();
        }
        Menu::~Menu()
        {
            delete fonte;
            delete imagem;
            delete bg;
        }
        void Menu::set_valores()
        {
            pos = 0;
            pressionou = false;
            deselecionado = false;

            fonte->loadFromFile("Design/Fontes/Dungeon-Depths.ttf");
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
        }
        void Menu::loop_eventos()
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
                    if(pos == 3)
                    {
                        pGG->fecharJanela();
                    }
                }
            }
        }
        void Menu::desenhar()
        {
            pGG->get_Janela()->clear();
            pGG->desenhar(bg);
            for(auto t : textos)
            {
                pGG->get_Janela()->draw(t);
            }
            pGG->mostrar();
        }
        void Menu::executar()
        {
            while(pGG->get_JanelaAberta())
            {
                loop_eventos();
                desenhar();
            }
        }
    }
}