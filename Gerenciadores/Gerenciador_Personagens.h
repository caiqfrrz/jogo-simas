#pragma once

#include "../Entidades/Personagens/Personagem.h"
#include "../Entidades/Entidade.h"
#include "../Listas/ListaEntidades.h"
#include <iostream>

namespace Gerenciadores
{
    class Gerenciador_Personagens
    {
    private:
        Listas::ListaEntidades* jogadores;
        Listas::ListaEntidades* inimigos;

    public:
        Gerenciador_Personagens(Listas::ListaEntidades* jog, Listas::ListaEntidades* inim);
        ~Gerenciador_Personagens();
        void checarPersonagens();

    };
}