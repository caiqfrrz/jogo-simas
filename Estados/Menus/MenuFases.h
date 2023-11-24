#pragma once

#include "Menu.h"
#include "../Observers/MenuFasesObserver.h"

namespace Estados
{
    namespace Menus
    {
        class MenuFases : public Menu
        {
        private:
            Observers::MenuFasesObserver* pObs;
            Design::Text jgd1;
            Design::Text jgd2;
            int pos_horizontal;
            int num_jogadores;
        public:
            MenuFases();
            ~MenuFases();
            void set_valores();
            void selecionar();
            void desenhar();
            void sel_player();
        };
    }
}