#pragma once

#include "Obstaculo.h"
#include "../Listas/ListaEntidades.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Coracao : public Obstaculo
        {
        private:
            int cura;
            Listas::ListaEntidades* jogadores;
        public:
            Coracao(Listas::ListaEntidades* jog = nullptr, sf::Vector2f pos = {0,0});
            ~Coracao();
            void executar();
            void colidir(Entidades::Entidade* pE, bool b);
            void salvar(std::ostringstream* entrada) {}
        };
    }
}