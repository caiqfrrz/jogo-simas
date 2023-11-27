#include "../Observers/Observer.h"
#include <iostream>

namespace Observers
{
    Observer::Observer():
    pGE(Gerenciadores::Gerenciador_Estados::get_instancia()),
    pGEv(Gerenciadores::Gerenciador_Eventos::get_instancia()),
    pGG(Gerenciadores::Gerenciador_Grafico::get_instancia())
    {
    }
    Observer::~Observer()
    {
        pGEv->remove_obs(this);
    }
}