#include "../Observers/MenuPausaObserver.h"
#include "../Estados/Menus/MenuPausa.h"

namespace Observers
{
    MenuPausaObserver::MenuPausaObserver():
    Observer()
    {
        pGEv->add_obs(this);
    }
    MenuPausaObserver::~MenuPausaObserver()
    {
        pMenu = nullptr;
    }
    void MenuPausaObserver::setMenu(Estados::Menus::MenuPausa* pM)
    {
        pMenu = pM;
    }
    void MenuPausaObserver::update(sf::Keyboard::Key tecla)
    {
        if(pGE->getEstadoAtual() != 4)
            return;

        if(!pMenu)
            return;

        if(tecla == sf::Keyboard::Down)
            pMenu->baixo();
        else if(tecla == sf::Keyboard::Up)
            pMenu->cima();
        else if(tecla == sf::Keyboard::Enter)
            pMenu->selecionar();
    }
}