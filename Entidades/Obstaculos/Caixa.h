#pragma once 

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Caixa: public Obstaculo
        {
        private:
            int vida;
        public:
            Caixa(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), bool ativo = true);
            ~Caixa();
            void executar();
            void colidir(Entidade* pE, bool b);
            void salvar(std::ostringstream* entrada);
        };
    }
}