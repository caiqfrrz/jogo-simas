#pragma once

#define TEMPO_RECARGA 100

#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Entidades/Projetil.h"
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
            int vida;
            int dano;
            Listas::ListaEntidades *jogadores;
            std::vector<Projetil> vec_proj;
            int recarregar;
            sf::Vector2f velocidadeDir;

        public:
            bool firing;
            Boss(Listas::ListaEntidades *jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Boss();
            void executar();
            void mover();
            void colidir(Entidade *pE, bool b);
            void atirar();
            void ultrathrust();
            void bolasdefogo();
            std::vector<Projetil> *getVetProj();
            // Entidade* getJogadorProx();
        };
    }
}
