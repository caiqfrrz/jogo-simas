#pragma once

#include "../Entidade.h"
#include "../../Design/HUD.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem: public Entidade
        {
        protected:
            bool damaged;
            bool lento;
            bool pulando;
            float pulo;
            int vida; 
            Design::HUD grafico;
            clock_t timer;
        public:
            Personagem(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Personagem();
            virtual void executar() = 0;
            virtual void salvar(std::ostringstream* entrada) = 0;
            virtual int getVida();
            virtual void setVida(int v);
            virtual void TomarDano(int d, bool b);
            void morreu();
            bool getMorte();
            void reviver();
            virtual void ResetColor();
            virtual bool getMorte();
            bool getDamaged();
            bool getLento();
            void setLento(bool b);
        };
    }
}
