#pragma once
#define TEMPO_RECARGA_JOG 20

#include "Personagem.h"
#include "../Projetil.h"
#include "../../Design/Text.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador: public Personagem
        {
        private:
            int pontos;
            int recarga;
            short int last_key;
            std::vector<Projetil> vet_proj;
            std::vector<sf::Vector2f> vet_pos;
        public:
            Jogador();
            ~Jogador();
            void executar();
            void mover();
            void atirar();
            std::vector<Projetil>* getVetProj();
        };
    }
}