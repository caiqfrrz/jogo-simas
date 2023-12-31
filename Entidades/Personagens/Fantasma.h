#pragma once

#include "Inimigo.h"
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
            Listas::ListaEntidades* jogadores;
        public:
            Fantasma(int vida = 2, Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), int dano = 2);
            ~Fantasma();
            void executar();
            void mover();
            void colidir(Entidade* pE, bool b);
            void salvar(std::ostringstream* entrada);
            std::vector<Projetil>* getVetProj() {return nullptr;}
        };
    }
}
