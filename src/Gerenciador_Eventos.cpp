#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Observers/Observer.h"

#include <iostream>

namespace Gerenciadores
{
    Gerenciador_Eventos* Gerenciador_Eventos::instancia(nullptr);

    Gerenciador_Eventos::Gerenciador_Eventos():
    Sujeito(),
    pGrafico(Gerenciador_Grafico::get_instancia())
    {

    }
    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        pGrafico = nullptr;   
    }
    Gerenciador_Eventos* Gerenciador_Eventos::get_instancia()
    {
        if (!instancia)
            instancia = new Gerenciador_Eventos();
        return instancia;
    }
    void Gerenciador_Eventos::executar()
    {
        sf::Event evento;
        while (pGrafico->get_Janela()->pollEvent(evento))
            switch (evento.type)
            {
            case sf::Event::Closed:
                pGrafico->fecharJanela();
                break;
            case sf::Event::KeyPressed:
                notificar((evento.key.code));
                break;
            default:
                break;
            }
    }
}