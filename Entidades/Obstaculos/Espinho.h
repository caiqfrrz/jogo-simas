#pragma once 

#include "Obstaculo.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho: public Obstaculo
        {
        private:
            static int dano;
        public:
            Espinho(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Espinho();
            void executar();
            int getDano();
            void colidir(Entidade* pE, bool b);
        };
    }
}