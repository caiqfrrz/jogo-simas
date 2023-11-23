#pragma once

#include "Personagem.h"
#include "../Escudo.h"
#include <iostream>
#include <deque>

namespace Entidades
{
    namespace Personagens
    {
        class Jogador2 : public Personagem
        {
        private:
            int pontos;
            int escudos;
            int recarregar;
            short int direcao;
            std::deque<Escudo> fila_escudo;
        public:
            Jogador2();
            ~Jogador2();
            void executar();
            void mover();
            void lancar_escudos();
        };
    }
}