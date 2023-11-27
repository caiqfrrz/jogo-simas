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
        std::string direcao;
        int contagem;
    public:
        Escudo(std::string dir = "direita", sf::Vector2f pos = {0, 0}, bool lanc = false, int cont = CONTAGEM_PARAR, short int opac = 255, bool par = false);
        ~Escudo();

        void executar();
        void setDirecao(std::string dir);
        void ajustarTam();
        void lancar();
        void desaparecer();
        bool getDesapareceu();
        void colidir(Entidade* pE, bool b);
        void salvar(std::ostringstream* entrada);
    };
}