#pragma once
#define TEMPO_RECARGA 100


#include "Inimigo.h"
#include "../Projetil.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inim_Medio : public Inimigo
        {
        private:
            int dano;
            Projetil novo;
            int recarregar;
            int num_proj;
        public:
            Inim_Medio(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Inim_Medio();
            void executar();
            void mover();
            void atirar();
        };
    }
}