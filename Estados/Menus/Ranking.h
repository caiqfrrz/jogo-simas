#pragma once

#include "Menu.h"
#include <fstream>
#include <iostream>

namespace Estados
{
    namespace Menus
    {
        class Ranking : public Menu
        {
        protected:
            sf::Font *fonte2;
            // Observers::MenuFasesObserver *pObs;

        public:
            Ranking(int i = -1, int nb = 0);
            ~Ranking();
            void selecionar();
            void desenhar();
            void set_valores();
            void inicializa_valores();
            void loop_evento();
            void executar();
            void CriarTextos(std::string caminho);
            void sortRank(std::string caminho);
        };
    }
}