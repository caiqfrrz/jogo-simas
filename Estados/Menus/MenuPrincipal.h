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

        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void set_valores();
            void desenhar();
            void selecionar();
        };
    }
}