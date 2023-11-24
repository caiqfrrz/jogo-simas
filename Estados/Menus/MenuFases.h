#pragma once

#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuFases : public Menu
        {
        private:
        public:
            MenuFases();
            ~MenuFases();
            void set_valores();
            void loop_eventos();
            void selecionar();
        };
    }
}