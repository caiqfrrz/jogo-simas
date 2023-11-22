#pragma once

#include "Entidade.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        bool ativo;
        int dano;
    public:
        Projetil(sf::Vector2f tam);
        ~Projetil();
        void executar();
        void atirar();
        void colidir(Entidade* pE);
        void reset();
        int getDano();
        bool getAtivo();
        void setAtivo(bool b);
    };
}