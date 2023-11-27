#pragma once

#define TEMPO_RECARGA_JOG2 300

#include "JogadorStrategy.h"

namespace Entidades
{
    namespace Personagens
    {
        class JogadorEscudo : public JogadorStrategy
        {
        private:
            std::deque<Escudo> fila_esc;
            int escudos;
        public:
            JogadorEscudo();
            ~JogadorEscudo();
            void atacar();
            void executar();
            void mover();
            void setJog(Jogador* jgd);
            std::vector<Projetil>* getVetProj();
            std::deque<Escudo>* getFilaEsc();
            void salvar(std::ostringstream* entrada);
        };
    }
}