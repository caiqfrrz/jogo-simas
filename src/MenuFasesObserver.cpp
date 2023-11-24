#include "../Observers/MenuFasesObserver.h"
#include "../Estados/Menus/MenuFases.h"

namespace Observers
{
    MenuFasesObserver::MenuFasesObserver():
    Observer(),
    pMenu(nullptr)
    {
        pGEv->add_obs(this);
    }
    MenuFasesObserver::~MenuFasesObserver()
    {

    }
    void MenuFasesObserver::setMenu(Estados::Menus::MenuFases* pM)
    {
        pMenu = pM;
    }
    void MenuFasesObserver::update(sf::Keyboard::Key tecla)
    {
        if(!pMenu)
            return;

        if(pGE->getEstadoAtual() != 1)
            return;

        if(tecla == sf::Keyboard::Down)
        {
            pMenu->baixo();
        }
        else if(tecla == sf::Keyboard::Up)
            pMenu->cima();
        else if(tecla == sf::Keyboard::Enter)
            pMenu->selecionar();
    }   
    
}