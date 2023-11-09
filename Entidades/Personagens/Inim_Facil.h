#pragma once

#include "Inimigo.h"
#include "../../Estados/Fases/Fase.h"
#include "../../Listas/ListaEntidades.h"
#include <math.h>

namespace Entidades
{
    namespace Personagens
    {
        // Inimigo 2
        class Inim_Facil: public Inimigo
        {
        private:
            int vida;
            int dano;
            Listas::ListaEntidades* jogadores;
        public:
            Inim_Facil(Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Inim_Facil();
            void executar();
            void mover();
            Entidade* getJogadorProx();
        };
    }
}
