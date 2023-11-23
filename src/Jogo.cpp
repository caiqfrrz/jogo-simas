#include "../Jogo.h"
#include <iostream>

Jogo::Jogo():
pGrafico(Gerenciadores::Gerenciador_Grafico::get_instancia()),
pEventos(Gerenciadores::Gerenciador_Eventos::get_instancia()),
pEstados(Gerenciadores::Gerenciador_Estados::get_instancia())
{
    Estados::Menus::MenuPrincipal* menu_principal = new Estados::Menus::MenuPrincipal();
    Estados::Menus::MenuJogadores* menu_jogadores = new Estados::Menus::MenuJogadores();
    Estados::Menus::MenuFases* menu_fases = new Estados::Menus::MenuFases();
    Estados::Fases::FasePrimeira* fase1 = new Estados::Fases::FasePrimeira();
    Estados::Fases::FaseSegunda* fase2 = new Estados::Fases::FaseSegunda();
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
