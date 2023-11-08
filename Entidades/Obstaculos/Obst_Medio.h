#pragma once 

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obst_Medio: public Obstaculo
        {
        private:
            static int dano;
        public:
            Obst_Medio(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Obst_Medio();
            void executar();
            int getDano();
        };
    }
}