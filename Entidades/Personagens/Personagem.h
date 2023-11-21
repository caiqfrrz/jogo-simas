#pragma once

#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem: public Entidade
        {
        protected:
            bool damaged;
            int num_vidas;
            bool lento;
            bool morte;
            int vida; 
            clock_t timer;
        public:
            Personagem(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Personagem();
            virtual void executar() = 0;
            virtual int getVida();
            virtual void setVida(int v);
            virtual void TomarDano();
            virtual void morreu();
            virtual void ResetColor();
            bool getDamaged();
            void lentidao(bool l);
            bool getLento();
            void setLento(bool b);
        };
    }
}
