#pragma once

#define TEMPO_RECARGA 100

#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Projetil.h"
#include <math.h>
#include<iostream>

namespace Entidades
{
    namespace Personagens
    {
        class Atirador : public Inimigo
        {
        private:
            Listas::ListaEntidades* jogadores;
            int vida;
            int dano;
            std::vector<Projetil> vec_proj;
            int recarregar;
            std::string dir;
        public:
            bool firing;
            Atirador(Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Atirador();
            void executar();
            void mover();
            void atirar();
            void colidir();
            std::vector<Projetil>* getVetProj();
        };
    }
}