#pragma once

#include "Menu.h"
#include "../../Observers/MenuPausaObserver.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPausa : public Menu
        {
        private:
            Observers::MenuPausaObserver* pObs;
        public:
            MenuPausa();
            ~MenuPausa();
            void set_valores();
            void desenhar();
            void selecionar();

        };
    }
}