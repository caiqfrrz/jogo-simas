#pragma once 

#include "../Estado.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"

namespace Estados
{
    namespace Menus
    {
        class Menu: public Estado
        {
        private:
            int pos;
            bool pressionou;
            bool deselecionado;
            static Gerenciadores::Gerenciador_Grafico* pGG;

            sf::Font* fonte;
            sf::Texture* imagem;
            sf::Sprite* bg;

            std::vector<std::string> opcoes;
            std::vector<sf::Vector2f> coords;
            std::vector<sf::Text> textos;
            std::vector<std::size_t> tamanhos;
        public:
            Menu();
            ~Menu();

            void set_valores();
            void loop_eventos();
            void desenhar();
            void executar();
        };
    }
}