#pragma once

#define TEMPO_RECARGA 100

#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Entidades/Projetil.h"
#include <math.h>
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        class Atirador : public Inimigo
        {
        private:
            Listas::ListaEntidades *jogadores;
            std::vector<Projetil> vec_proj;
            int recarregar;
            std::string dir;

        public:
            bool firing;
            Atirador(int vida = 5, Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), int dano = 1);
            ~Atirador();
            void executar();
            void mover();
            void atirar();
            void colidir(Entidade* pE, bool b);
            void salvar(std::ostringstream* entrada);
            std::vector<Projetil>* getVetProj();
        };
    }
}