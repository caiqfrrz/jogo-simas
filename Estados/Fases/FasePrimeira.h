#pragma once

#include "Fase.h"

#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"

namespace Estados
{
    namespace Fases
    {
        // Fase 1
        class FasePrimeira: public Fase
        {
        private:
        public:
            FasePrimeira(int id = -1,bool dois_jgd = false);
            ~FasePrimeira();
            void executar();
        };
    }    
}
