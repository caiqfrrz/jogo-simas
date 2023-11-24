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
        for (it = lista_observers.begin(); it != lista_observers.end(); it++)
        {
            delete(*it);
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
            std::cout << "oi";
            (*it)->update((tecla));
        } 
    }
}