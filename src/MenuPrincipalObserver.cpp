#include "../Observers/MenuPrincipalObserver.h"
#include "../Estados/Menus/MenuPrincipal.h"
#include <iostream>

namespace Observers
{
    MenuPrincipalObserver::MenuPrincipalObserver()
    {
        pGEv->add_obs(this);
    }
    MenuPrincipalObserver::~MenuPrincipalObserver()
    {
        pMenu = nullptr;
    }
    void MenuPrincipalObserver::setMenu(Estados::Menus::MenuPrincipal* pM)
    {
        pMenu = pM;
    }
    void MenuPrincipalObserver::update(sf::Keyboard::Key tecla)
    {
        if(!pMenu)
            return;

        if(pGE->getEstadoAtual() != 0)
            return;
        if(tecla == sf::Keyboard::Down)
        {
            pMenu->baixo();
        }
        else if(tecla == sf::Keyboard::Up)
            pMenu->cima();
        else if(tecla == sf::Keyboard::Enter)
            pMenu->selecionar();
        else if(tecla == sf::Keyboard::Right || tecla == sf::Keyboard::Left)
            pMenu->sel_player();
    }
}