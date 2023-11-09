#pragma once

#include "../Entidades/Personagens/Personagem.h"
#include "../Listas/ListaEntidades.h"

namespace Gerenciadores
{
    class Gerenciador_Personagens
    {
    private:
        Entidades::Personagens::Personagem* Personagem;
        Listas::ListaEntidades* jogadores;
        Listas::ListaEntidades* inimigos;

        Gerenciador_Personagens();

    public:
        ~Gerenciador_Personagens();
        void morreu();
        void checarPersonagem();

    };
}