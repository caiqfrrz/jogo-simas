#pragma once

#include "Inimigo.h"
#include "../../Estados/Fases/Fase.h"
#include "../../Listas/ListaEntidades.h"
#include <math.h>

namespace Entidades
{
    namespace Personagens
    {
        // Inimigo 2
        class Fantasma: public Inimigo
        {
        private:
            int vida;
            int dano;
            static int n_fantasmas_salvos;
            Listas::ListaEntidades* jogadores;
        public:
            Fantasma(Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Fantasma();
            void executar();
            void mover();
            void colidir(Entidade* pE, bool b);
            void salvar(std::ostringstream* entrada);
            //Entidade* getJogadorProx();
        };
    }
}
