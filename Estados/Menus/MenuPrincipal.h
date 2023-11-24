#pragma once
#include "Menu.h"
#include "../Observers/MenuPrincipalObserver.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
        private:
            Observers::MenuPrincipalObserver* pObs;
            int num_jogadores;
            int pos_horizontal;
            Design::Text jgd1;
            Design::Text jgd2;

        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void set_valores();
            void desenhar();
            void selecionar();
            void sel_player();
        };
    }
}