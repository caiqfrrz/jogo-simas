#pragma once 

#include "Menu.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Design/Text.h"

namespace Estados
{
    namespace Menus
    {
        class Ranking: public Menu
        {
        protected:
           sf::Font* fonte2;
        public:
            Ranking(int i = -1, int nb = 0);
            ~Ranking();
            virtual void selecionar();
            virtual void desenhar();
            virtual void executar();
        };
    }
}