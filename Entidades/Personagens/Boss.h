#pragma once

#include "Inimigo.h"
#include "../../Estados/Fases/Fase.h"
#include "../../Listas/ListaEntidades.h"
#include <math.h>

namespace Entidades
{
    namespace Personagens
    {
        // Chefao
        class Boss: public Inimigo
        {
        private:
            int vida;
            int dano;
            Listas::ListaEntidades* jogadores;
        public:
            Boss(Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Boss();
            void executar();
            void mover();
            //Entidade* getJogadorProx();
        };
    }
}
