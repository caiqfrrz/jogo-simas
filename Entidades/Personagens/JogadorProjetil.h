#pragma once

#define TEMPO_RECARGA_JOG 20

#include "JogadorStrategy.h"
#include "math.h"
#include <vector>
#include <deque>

namespace Entidades
{
    namespace Personagens
    {
        class JogadorProjetil : public JogadorStrategy
        {
        private:
            std::vector<Projetil> vet_proj;
        public:
            JogadorProjetil();
            ~JogadorProjetil();
            void atacar();
            void executar();
            void mover();
            void setJog(Jogador* jgd);
            std::vector<Projetil>* getVetProj();
            std::deque<Escudo>* getFilaEsc();
        };
    }
}