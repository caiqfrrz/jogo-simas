#pragma once
#define TEMPO_RECARGA_JOG 20

#include "Personagem.h"
#include "../Projetil.h"
#include "../../Design/Text.h"
#include "JogadorStrategy.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        private:
            int pontos;
            int i;
            int recarga;
            short int last_key;
            JogadorStrategy *jogador_type;

        public:
            static int nume;
            Jogador(JogadorStrategy *jgd = nullptr, int id = 0);
            ~Jogador();
            void executar();
            void mover();
            void setPosicao(sf::Vector2f pos);
            void setLento(bool b);
            bool getLento();
            void setpoints(int p);
            int getpoints();
            void setPulando(bool p, float força);
            void setPulando(bool p);
            void salvar(std::ostringstream* entrada);
            std::vector<Projetil> *getVetProj();
            std::deque<Escudo> *getDqEscudo();
        };
    }
}
