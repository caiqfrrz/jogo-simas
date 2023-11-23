#pragma once
#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
        private:
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void set_valores();
            void loop_eventos();
        };
    }
}