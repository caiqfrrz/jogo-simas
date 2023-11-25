#pragma once

#include "Fase.h"
#include "../Estados/Menus/Ranking.h"
#define ARQUIVO_CENARIO_2 "Design/Fase2/Cenario/cenario2.txt"

namespace Estados
{
    namespace Fases
    {
        class FaseSegunda: public Fase
        {
        private:
        public:
            FaseSegunda(int id = -1, bool dois_jgd = false, Estados::Menus::Ranking* pR = nullptr);
            ~FaseSegunda();
            void executar();
        };
    }    
}
