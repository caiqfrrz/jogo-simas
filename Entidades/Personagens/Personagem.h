#pragma once

#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem: public Entidade
        {
        protected:
            int num_vidas;
            int vida;
        public:
            Personagem();
            ~Personagem();
            virtual void executar() = 0;
            virtual int getVida();
            virtual void setVida(int v);
            virtual void TomarDano();
        };
    }
}
