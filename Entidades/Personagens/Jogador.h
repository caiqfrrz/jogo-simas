#pragma once
#define TEMPO_RECARGA_JOG 20

#include "Personagem.h"
#include "../Projetil.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador: public Personagem
        {
        private:
            int pontos;
            int recarga;
            float pulo;
            bool pulando;
            std::vector<Projetil> vet_proj;
            std::vector<sf::Vector2f> vet_pos;
            std::vector<bool> vet_dir;
        public:
            Jogador();
            ~Jogador();
            void executar();
            void mover();
            void atirar();
        };
    }
}