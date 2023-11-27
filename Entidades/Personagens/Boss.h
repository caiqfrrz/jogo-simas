#pragma once

#define TEMPO_RECARGABOSS 700

#include "Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../Entidades/Projetil.h"
#include "../../Entidades/Personagens/Fantasma.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Gerenciadores/Sujeito.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        // Chefao
        class Boss : public Inimigo
        {
        private:
            Listas::ListaEntidades *jogadores;
            Listas::ListaEntidades *inimigos;
            int recarregar;
            sf::Vector2f velocidadeDir;
            Gerenciadores::Gerenciador_Grafico *pGrafico;
            const int numFrames = 10;         // Número de frames no GIF
            const float frameDuration = 0.1f; // Duração de cada frame em segundos
            int currentFrame = 0;
            sf::Texture texture;
            sf::Clock animationClock;

        public:
            bool firing;
            Boss(Listas::ListaEntidades *jog = nullptr, Listas::ListaEntidades *inim = nullptr, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), int dano = -1);
            ~Boss();
            void executar();
            void mover();
            void colidir(Entidade *pE, bool b);
            void atirar();
            void ultrathrust();
            void salvar(std::ostringstream *entrada);
        };
    }
}
