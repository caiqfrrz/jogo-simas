#pragma once 

#include "../Estado.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Design/Text.h"

namespace Estados
{
    namespace Menus
    {
        class Menu: public Estado
        {
        protected:
            int pos;
            int n_botoes;
            bool pressionou;
            bool deselecionado;
            bool saiu;
            static Gerenciadores::Gerenciador_Grafico* pGG;

            sf::Font* fonte;
            sf::Texture* imagem;
            sf::Sprite* bg;

            std::vector<std::string> opcoes;
            std::vector<sf::Vector2f> coords;
            std::vector<sf::Text> textos;
            std::vector<std::size_t> tamanhos;
        public:
            Menu(int i = -1, int nb = 0);
            ~Menu();

            virtual void selecionar() = 0;
            virtual void desenhar();
            virtual void executar();
            void cima();
            void baixo();
        };
    }
}