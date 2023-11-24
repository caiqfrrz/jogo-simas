#pragma once

#include "../Gerenciadores/Gerenciador_Estados.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"

namespace Observers
{
    class Observer
    {
    protected:
        Gerenciadores::Gerenciador_Estados* pGE;
        Gerenciadores::Gerenciador_Eventos* pGEv;
        Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Observer();
        virtual ~Observer();
        virtual void update(sf::Keyboard::Key tecla) = 0;
    };
}