#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo: public Personagem
        {
        protected:
            int nivel_maldade;
            bool fantasma;
            bool atirador;
        public:
            Inimigo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), bool fant = false, bool at = false);
            ~Inimigo();
            virtual void executar();
            virtual bool ehFantasma();
            virtual bool ehAtirador();
        };
    }
}