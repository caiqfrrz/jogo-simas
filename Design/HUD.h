#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem;
    }
}

namespace Design
{
    class HUD
    {
    private:
        float var;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        Entidades::Personagens::Personagem* pPersonagem;
        Entidades::Personagens::Personagem* pJogador;
        Entidades::Personagens::Personagem* pJogador2;
        sf::RectangleShape barra_verde;
        sf::RectangleShape barra_vermelha;
        
    public:
        HUD();
        ~HUD();
        void executar();
        void setPers(Entidades::Personagens::Personagem* pPers);
        void desenhar();
        void setPosicao();
        void setJg1(Entidades::Personagens::Personagem* pPers);
        void setJg2(Entidades::Personagens::Personagem* pPers);

    };
}