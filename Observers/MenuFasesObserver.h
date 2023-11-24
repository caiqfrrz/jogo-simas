#pragma once

#include "Observer.h"

namespace Estados
{
    namespace Menus
    {
        class MenuFases;
    }
}

namespace Observers
{
    class MenuFasesObserver : public Observer
    {
    private:
        Estados::Menus::MenuFases* pMenu;
    public:
        MenuFasesObserver();
        ~MenuFasesObserver();
        void update(sf::Keyboard::Key tecla);
        void setMenu(Estados::Menus::MenuFases* pM);
    };
}