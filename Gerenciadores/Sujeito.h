#pragma once
#include <list>
#include "../Gerenciadores/Gerenciador_Grafico.h"

namespace Observers
{
    class Observer;
}

namespace Gerenciadores
{
    class Sujeito
    {
    protected:
        std::list<Observers::Observer*> lista_observers;
        std::list<Observers::Observer*>::iterator it;

    public:
        Sujeito();
        virtual ~Sujeito();
        virtual void add_obs(Observers::Observer* pObs);
        virtual void remove_obs(Observers::Observer* pObs);
        virtual void notificar(sf::Keyboard::Key tecla);
    };
}