#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo: public Personagem
        {
        protected:
            int nivel_maldade;
        public:
            Inimigo();
            ~Inimigo();
            virtual void executar();
        };
    }
}