#pragma once

#include "Entidade.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        int dano;
        std::string direcao;
    public:
        Projetil(sf::Vector2f tam = {0,0}, std::string dir = "");
        ~Projetil();
        void executar();
        void atirar();
        void colidir(Entidade* pE, bool b);
        void reset();
        int getDano();
    };
}