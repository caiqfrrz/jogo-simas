#pragma once

#define TEMPO_RECARGABOSS 700

#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Entidades/Projetil.h"
#include "../../Entidades/Personagens/Fantasma.h"
#include <math.h>
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        // Chefao
        class Boss : public Inimigo
        {
        private:
            Listas::ListaEntidades *jogadores;
            Listas::ListaEntidades *inimigos;
            int recarregar;
            sf::Vector2f velocidadeDir;

        public:
            bool firing;
            Boss(Listas::ListaEntidades *jog, Listas::ListaEntidades *inim, sf::Vector2f pos, int dano = 3);
            ~Boss();
            void executar();
            void mover();
            void colidir(Entidade *pE, bool b);
            void atirar();
            void ultrathrust();
            // Entidade* getJogadorProx();
        };
    }
}
