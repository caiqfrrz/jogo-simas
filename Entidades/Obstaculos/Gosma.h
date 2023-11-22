#pragma once

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Gosma : public Obstaculo
        {
        private:
            const float força;

        public:
            Gosma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Gosma();
            void colidir(Entidade* pE);
            void executar();
            void colidir(Entidade* pE);
        };
    }
}
