#include "../Observers/MenuFasesObserver.h"
#include "../Estados/Menus/MenuFases.h"
#include <iostream>

namespace Observers
{
    MenuFasesObserver::MenuFasesObserver():
    Observer(),
    pMenuFases(nullptr)
    {
        pGEv->add_obs(this);
    }
    MenuFasesObserver::~MenuFasesObserver()
    {
        std::cout<< "fases";
        pMenuFases = nullptr;
    }
    void MenuFasesObserver::setMenu(Estados::Menus::MenuFases* pM)
    {
        pMenuFases = pM;
    }
    void MenuFasesObserver::update(sf::Keyboard::Key tecla)
    {
        if(!pMenuFases)
            return;

        if(pGE->getEstadoAtual() != 1)
            return;

        if(tecla == sf::Keyboard::Down)
        {
            pMenuFases->baixo();
        }
        else if(tecla == sf::Keyboard::Up)
            pMenuFases->cima();
        else if(tecla == sf::Keyboard::Enter)
            pMenuFases->selecionar();
        else if(tecla == sf::Keyboard::Right || tecla == sf::Keyboard::Left)
            pMenuFases->sel_player();
    }   
    
}