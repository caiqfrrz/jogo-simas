#include "../Jogo.h"
#include <iostream>

Jogo::Jogo():
pGrafico(Gerenciadores::Gerenciador_Grafico::get_instancia()),
pEventos(Gerenciadores::Gerenciador_Eventos::get_instancia()),
pEstados(Gerenciadores::Gerenciador_Estados::get_instancia())
{
    Estados::Menus::MenuPrincipal* menu_principal = new Estados::Menus::MenuPrincipal();
    Estados::Menus::MenuFases* menu_fases = new Estados::Menus::MenuFases();

    Estados::Fases::FasePrimeira* fase1_1p = new Estados::Fases::FasePrimeira(2, false);
    Estados::Fases::FasePrimeira* fase1_2p = new Estados::Fases::FasePrimeira(3, true);

    Estados::Fases::FaseSegunda* fase2_1p = new Estados::Fases::FaseSegunda(4, false);
    Estados::Fases::FaseSegunda* fase2_2p = new Estados::Fases::FaseSegunda(5, true);
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
