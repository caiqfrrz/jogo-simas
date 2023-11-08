#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador2 : public Personagem
        {
        private:
            int pontos;
        public:
            Jogador2();
            ~Jogador2();
            void executar();
            void mover();
        };
    }
}