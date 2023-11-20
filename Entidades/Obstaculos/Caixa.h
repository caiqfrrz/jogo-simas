#pragma once 

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Caixa: public Obstaculo
        {
        private:

        public:
            Caixa(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Caixa();
            void executar();
        };
    }
}