#pragma once

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
        public:
            Plataforma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Plataforma();
            void colidir(Entidade* pE);
            void executar();
        };
    }
}