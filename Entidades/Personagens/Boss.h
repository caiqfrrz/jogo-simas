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
            Boss(int vida = 10, Listas::ListaEntidades *jog = nullptr, Listas::ListaEntidades *inim = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), int dano = -1);
            ~Boss();
            void executar();
            void mover();
            void colidir(Entidade *pE, bool b);
            void atirar();
            void ultrathrust();
            void salvar(std::ostringstream* entrada);
        };
    }
}
