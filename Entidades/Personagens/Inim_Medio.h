#pragma once
#define TEMPO_RECARGA 100


#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Projetil.h"
#include <math.h>

namespace Entidades
{
    namespace Personagens
    {
        class Inim_Medio : public Inimigo
        {
        private:
            Listas::ListaEntidades* jogadores;
            int vida;
            int dano;
            Projetil novo;
            int recarregar;
        public:
            bool firing;
            Inim_Medio(Listas::ListaEntidades*jog = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Inim_Medio();
            void executar();
            void mover();
            void atirar();
            Projetil* getProjetil();
        };
    }
}