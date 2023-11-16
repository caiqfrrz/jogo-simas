#pragma once

#include "Entidade.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
    public:
        Projetil(sf::Vector2f tam);
        ~Projetil();
        void executar();
        void atirar();
    };
}