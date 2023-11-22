#pragma once

#include "Entidade.h"

namespace Entidades
{
    class Escudo : public Entidade
    {
    private:
        bool lancando;
        bool desapareceu;
        bool parou;
        short int opacidade;
        short int direcao;
        int contagem;
    public:
        Escudo();
        ~Escudo();

        void executar();
        void setDirecao(short int dir);
        void lancar();
        void getDano();
        void colidir();
        void desaparecer();
        bool getDesapareceu();
    };
}