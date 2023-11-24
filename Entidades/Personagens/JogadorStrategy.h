#pragma once

#include "../Escudo.h"
#include "../Projetil.h"
#include <deque>


namespace Entidades
{
    namespace Personagens
    {
        class Jogador;

        class JogadorStrategy
        {
        protected:
            Jogador* pJog;
            int last_key;
            int recarga;
        public:
            JogadorStrategy():last_key(1),recarga(0) {};
            virtual ~JogadorStrategy() {};
            virtual void atacar() = 0;
            virtual void executar() = 0;
            virtual void mover() = 0;
            virtual std::vector<Projetil>* getVetProj() = 0;
            virtual std::deque<Escudo>* getFilaEsc() = 0;
        };
    }
}