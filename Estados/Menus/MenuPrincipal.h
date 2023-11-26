#pragma once
#include "Menu.h"
#include "../Observers/MenuPrincipalObserver.h"
#include "../Estados/Menus/Ranking.h"


namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
        private:
            Observers::MenuPrincipalObserver* pObs;
            Estados::Menus::Ranking* pRanking;
        public:
            MenuPrincipal(Estados::Menus::Ranking* pR = nullptr);
            ~MenuPrincipal();
            void set_valores();
            void desenhar();
            void selecionar();
            void usarfuncaoCriarTextos(Estados::Menus::Ranking* objRanking, std::string caminho);
            void usarfuncaoreSize(Estados::Menus::Ranking* objRanking, std::string caminho);
        };
    }
}