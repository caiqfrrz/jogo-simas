#pragma once

#include "Observer.h"
namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal;
    }
}

namespace Observers
{
    class MenuPrincipalObserver : public Observer
    {
    private:
        Estados::Menus::MenuPrincipal* pMenu;
    public:
        MenuPrincipalObserver();
        ~MenuPrincipalObserver();
        void update(sf::Keyboard::Key tecla);
        void setMenu(Estados::Menus::MenuPrincipal* pM);
    };
}