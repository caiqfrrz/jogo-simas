#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Gerenciadores/Sujeito.h"
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
    class Gerenciador_Eventos : public Sujeito
    {
    private:
        Gerenciador_Grafico *pGrafico;
        static Gerenciador_Eventos* instancia;
        Gerenciador_Eventos();
    public:
        ~Gerenciador_Eventos();
        void executar();     
        static Gerenciador_Eventos* get_instancia();
    };
}
