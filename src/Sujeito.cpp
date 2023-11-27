#include "../Gerenciadores/Sujeito.h"
#include "../Observers/Observer.h"
#include <iostream>

namespace Gerenciadores
{
    Sujeito::Sujeito():
    lista_observers()
    {
        lista_observers.clear();
    }
    Sujeito::~Sujeito()
    {
        Observers::Observer* obs;
        std::list<Observers::Observer*>::iterator it2;
        for (it2 = lista_observers.begin(); it2 != lista_observers.end();) 
        {
            obs = (*it2);
            it2++;
            delete obs; 
        }
        lista_observers.clear();

    }
    void Sujeito::add_obs(Observers::Observer* pObs)
    {
        lista_observers.push_back(pObs);
    }
    void Sujeito::remove_obs(Observers::Observer* pObs)
    {
        lista_observers.remove(pObs);
    }
    void Sujeito::notificar(sf::Keyboard::Key tecla)
    {
        for (it = lista_observers.begin(); it != lista_observers.end(); it++)
        {
            (*it)->update((tecla));
        } 
    }
}