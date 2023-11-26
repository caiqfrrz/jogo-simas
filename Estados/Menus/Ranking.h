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
            int power;
            sf::Text titulo;
            // Observers::MenuFasesObserver *pObs;
            static Ranking* instancia;
            Ranking(int i = -1, int nb = 0);
        public:
            ~Ranking();
            void selecionar();
            void desenhar();
            void set_valores();
            void inicializa_valores();
            void loop_evento();
            void executar();
            void CriarTextos(std::string caminho);
            void sortRank(std::string caminho);
            int reSize(std::string caminho);
            static Ranking* get_instancia(int i, int nb);
        };
    }
}