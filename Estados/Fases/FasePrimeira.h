#pragma once

#include "Fase.h"
#include "../Estados/Menus/Ranking.h"
#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"

namespace Estados
{
    namespace Fases
    {
        // Fase 1
        class FasePrimeira: public Fase
        {
        private:
            //int points;
        public:
            FasePrimeira(int id = -1, bool dois_jgd = false, bool crg = false);
            ~FasePrimeira();
            void executar();
        };
    }    
}
