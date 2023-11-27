#include "../Observers/ObserverTecla.h"
#include <iostream>

namespace Observers
{
    ObserverTecla::ObserverTecla():
    Observer()
    {
        pGEv->add_obs(this);
    }
    ObserverTecla::~ObserverTecla()
    {

    }
    void ObserverTecla::update(sf::Keyboard::Key tecla)
    {
        if(pGE->getEstadoAtual() != 2 && pGE->getEstadoAtual() != 3)
            return;
        
        if(tecla == sf::Keyboard::Escape)
        {
            pGE->setEstadoAtual(4);
        }
    }
}