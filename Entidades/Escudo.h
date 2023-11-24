#pragma once

#define CONTAGEM_PARAR 12
#define COMPRIMENTO_ESCUDO 85
#define LARGURA_ESCUDO 15
#define VEL_ESCUDO 5.f

#include "Entidade.h"

namespace Entidades
{
    class Escudo : public Entidade
    {
    private:
        bool lancando;
        bool desapareceu;
        bool parou;
        float opacidade;
        short int direcao;
        int contagem;
    public:
        Escudo();
        ~Escudo();

        void executar();
        void setDirecao(short int dir);
        void lancar();
        void desaparecer();
        bool getDesapareceu();
        void colidir(Entidade* pE);
    };
}