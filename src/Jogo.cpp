#include "../Jogo.h"
#include <iostream>

Jogo::Jogo() : pGrafico(Gerenciadores::Gerenciador_Grafico::get_instancia()),
               pEventos(Gerenciadores::Gerenciador_Eventos::get_instancia()),
               pEstados(Gerenciadores::Gerenciador_Estados::get_instancia())
{
    Estados::Menus::MenuPrincipal* menu_principal = new Estados::Menus::MenuPrincipal();
    Estados::Menus::MenuFases* menu_fases = new Estados::Menus::MenuFases();
    Estados::Menus::MenuPausa* menu_pausa = new Estados::Menus::MenuPausa();

    //Estados::Menus::Ranking* rankings = new Estados::Menus::Ranking(6, true);
    executar();
}

Jogo::~Jogo()
{
    delete pGrafico;
    delete pEventos;
    delete pEstados;
}

void Jogo::executar()
{
    while (pGrafico->get_JanelaAberta())
    {
        pGrafico->limpar();
        pEventos->executar();
        pEstados->executar();
        pGrafico->mostrar();
    }
}
