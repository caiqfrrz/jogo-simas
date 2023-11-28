#pragma once 

#include "../Entidade.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo: public Entidade
        {
        protected:
            bool danoso;
            bool lento;
        public:
            Obstaculo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), bool dano = false, bool l = false);
            ~Obstaculo();
            virtual void executar() = 0;
        };
    }
}