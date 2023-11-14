#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inim_Medio : public Inimigo
        {
        private:
            int dano;

        public:
            Inim_Medio(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Inim_Medio();
            void executar();
            void mover();
        };
    }
}