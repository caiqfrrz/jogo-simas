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
        public:
            MenuFases();
            ~MenuFases();
            void set_valores();
            void selecionar();
            void desenhar();
        };
    }
}