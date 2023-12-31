#pragma once

#include "../Listas/ListaEntidades.h"
#include "../Listas/Lista.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Obstaculos/Espinho.h"
#include "../Entidades/Obstaculos/Gosma.h"
#include "../Entidades/Projetil.h"
#include "../Entidades/Escudo.h"
#include "../Entidades/Personagens/Personagem.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Personagens/Boss.h"
#include "../Entidades/Personagens/Atirador.h"
#include "../Entidades/Personagens/Jogador.h"

#include <deque>

//Fortemente adaptado do código base fornecido pelo PETECO

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
    private:
        Listas::ListaEntidades *obstaculos;
        Listas::ListaEntidades *inimigos;
        Listas::ListaEntidades *jogadores;
    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();

        void set_obstaculos(Listas::ListaEntidades *o) { if (o) { obstaculos = o; }}
        void set_jogadores(Listas::ListaEntidades *j) { if (j) { jogadores = j; }}
        void set_inimigos(Listas::ListaEntidades *i) { if (i) { inimigos = i; }}
        void colisao();
        // Tipos de colisão em relação à e1: 0 - sem colisão, 1 - pela esquerda, 2 - por cima, 3 - pela direita, 4 - por baixo.
        int colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2);
        bool colisao_projetil(Entidades::Entidade* e1, Entidades::Entidade* e2);
        void colInimJogador();
        void colJogadorObs();
        void colbalaInim();
        void colInimObs();
        void colbalaObs();
        void colEscInim();
        void colbalaInimObs();
        void colEscJgd();
        void colEscbalaInim();
        void colbalaJgd();
        void chamarColBalas();
        void chamarColEscudo();
        void chamarColCorpos();

    };
}