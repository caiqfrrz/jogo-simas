#include "../Estados/Menus/Menu.h"

namespace Estados
{
    namespace Menus
    {
        Gerenciadores::Gerenciador_Grafico* Menu::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

        Menu::Menu(int i):
        Estado(i),
        saiu(false)
        {
            fonte = new sf::Font();
            imagem = new sf::Texture();
            bg = new sf::Sprite();
        }
        Menu::~Menu()
        {
            delete fonte;
            delete imagem;
            delete bg;
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
            while(pGG->get_JanelaAberta() && !saiu)
            {
                this->loop_eventos();
                this->desenhar();
            }
        }
    }
}