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
            bool lento;
            bool morte;
            bool pulando;
            bool projetil;
            bool escudo;
            float pulo;
            int vida; 
            clock_t timer;
        public:
            Personagem(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), bool pro = false, bool esp = false);
            ~Personagem();
            virtual void executar() = 0;
            virtual int getVida();
            virtual void setVida(int v);
            virtual void TomarDano(int d);
            virtual void morreu();
            virtual void ResetColor();
            virtual bool usaArma(); 
            virtual bool usaEscudo();
            virtual bool getMorte();
            bool getDamaged();
            void lentidao(bool l);
            bool getLento();
            void setLento(bool b);
        };
    }
}
