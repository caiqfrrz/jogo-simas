#pragma once

#include <SFML/Graphics.hpp>

#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Estados/Fases/FasePrimeira.h"
#include "Estados/Fases/FaseSegunda.h"
#include "Estados/Menus/MenuPrincipal.h"
#include "Estados/Menus/MenuFases.h"
#include "Estados/Menus/Ranking.h"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    Gerenciadores::Gerenciador_Eventos* pEventos;
    Gerenciadores::Gerenciador_Estados* pEstados;
    Estados::Menus::Ranking* pRank;

public:
    Jogo();
    ~Jogo();
    void executar();
};