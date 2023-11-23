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
            Menu(int i = -1);
            ~Menu();

            virtual void set_valores() = 0;
            virtual void loop_eventos() = 0;
            void desenhar();
            void executar();
        };
    }
}