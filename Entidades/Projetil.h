#pragma once

#include "Entidade.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        bool ativo;
    public:
        Projetil(sf::Vector2f tam);
        ~Projetil();
        void executar();
        void atirar();
        void colidir();
        void reset();
        bool getAtivo();
        void setAtivo(bool b);
    };
}