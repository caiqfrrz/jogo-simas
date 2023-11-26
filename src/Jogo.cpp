#include "../Jogo.h"
#include <iostream>

Jogo::Jogo() : pGrafico(Gerenciadores::Gerenciador_Grafico::get_instancia()),
               pEventos(Gerenciadores::Gerenciador_Eventos::get_instancia()),
               pEstados(Gerenciadores::Gerenciador_Estados::get_instancia()),
               pRank(Estados::Menus::Ranking::get_instancia(6,2))
{
    Estados::Menus::MenuPrincipal *menu_principal = new Estados::Menus::MenuPrincipal(pRank);
    Estados::Menus::MenuFases *menu_fases = new Estados::Menus::MenuFases();

    Estados::Fases::FasePrimeira *fase1_1p = new Estados::Fases::FasePrimeira(2, false, pRank);
    Estados::Fases::FasePrimeira *fase1_2p = new Estados::Fases::FasePrimeira(3, true, pRank);

    Estados::Fases::FaseSegunda *fase2_1p = new Estados::Fases::FaseSegunda(4, false, pRank);
    Estados::Fases::FaseSegunda *fase2_2p = new Estados::Fases::FaseSegunda(5, true, pRank);

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
