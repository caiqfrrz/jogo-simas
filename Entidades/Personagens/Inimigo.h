#pragma once

#include "Personagem.h"
#include "../Projetil.h"


namespace Entidades
{
    namespace Personagens
    {
        class Inimigo: public Personagem
        {
        protected:
            int nivel_maldade;
            bool fantasma;
            int dano;
        public:
            Inimigo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), bool fant = false);
            ~Inimigo();
            virtual void executar();
            virtual bool ehFantasma();
            virtual std::vector<Projetil>* getVetProj();
            void salvar(std::ostringstream* entrada);
        };
    }
}