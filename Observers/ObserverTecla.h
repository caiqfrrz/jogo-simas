#pragma once 

#include "Observer.h"

namespace Observers
{
    class ObserverTecla : public Observer
    {
    private:
    public:
        ObserverTecla();
        ~ObserverTecla();
        void update(sf::Keyboard::Key tecla);
    };
}