#pragma once

#include "Observer.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPausa;
    }
}

namespace Observers
{
    class MenuPausaObserver : public Observer
    {
    private:
        Estados::Menus::MenuPausa* pMenu;
    public:
        MenuPausaObserver();
        ~MenuPausaObserver();
        void update(sf::Keyboard::Key tecla);
        void setMenu(Estados::Menus::MenuPausa* pM);
    };
}