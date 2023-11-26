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
        class Boss : public Inimigo
        {
        private:
            int vida;
            int dano;
            Listas::ListaEntidades *jogadores;
            std::vector<Projetil> vec_proj;
            int recarregar;
            sf::Vector2f velocidadeDir;
            static int n_boss_salvos;
        public:
            bool firing;
            Boss(Listas::ListaEntidades *jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Boss();
            void executar();
            void mover();
            void colidir(Entidade *pE, bool b);
            void atirar();
            void ultrathrust();
            void bolasdefogo();
            void salvar(std::ostringstream* entrada);
            std::vector<Projetil> *getVetProj();
            // Entidade* getJogadorProx();
        };
    }
}
