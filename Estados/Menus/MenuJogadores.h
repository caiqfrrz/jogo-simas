#pragma once

#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuJogadores : public Menu
        {
        private:
        public:
            MenuJogadores();
            ~MenuJogadores();
            void set_valores();
            void loop_eventos();
        };
    }
}