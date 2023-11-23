#pragma once

#include "Fase.h"

#define ARQUIVO_CENARIO_2 "Design/Fase2/Cenario/cenario2.txt"

namespace Estados
{
    namespace Fases
    {
        class FaseSegunda: public Fase
        {
        private:
        public:
            FaseSegunda();
            ~FaseSegunda();
            void executar();
        };
    }    
}
