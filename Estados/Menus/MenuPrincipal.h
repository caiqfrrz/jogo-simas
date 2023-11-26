#pragma once
#include "Menu.h"
#include "../Observers/MenuPrincipalObserver.h"
#include "../Estados/Fases/FasePrimeira.h"
#include "../Estados/Fases/FaseSegunda.h"
#include "../Fases/json.hpp"

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
            void infosSave();
        };
    }
}