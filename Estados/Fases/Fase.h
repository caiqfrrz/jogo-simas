#pragma once

#include "json.hpp"

#define ARQUIVO_JOGADOR "Saves/jogadores.json"
#define ARQUIVO_INIMIGO "Saves/inimigos.json"

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../../Entidades/Personagens/Fantasma.h"
#include "../../Entidades/Personagens/Boss.h"
#include "../../Entidades/Obstaculos/Caixa.h"
#include "../../Entidades/Obstaculos/Espinho.h"
#include "../../Entidades/Obstaculos/Gosma.h"
#include "../../Entidades/Obstaculos/Plataforma.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../../Entidades/Personagens/JogadorProjetil.h"
#include "../../Entidades/Personagens/JogadorEscudo.h"
#include "../Estado.h"

namespace Estados
{
    namespace Fases
    {
        // Abstrata - Ente
        class Fase: public Ente, public Estado
        {
        protected:
            Listas::ListaEntidades obstaculos;
            Listas::ListaEntidades jogadores;
            Listas::ListaEntidades inimigos;
            Gerenciadores::Gerenciador_Colisoes gC;
            std::ostringstream buffer;
            bool dois_jogadores;
            bool carregamento;
            int n_atiradores;
            int n_chefoes;
            int n_fantasmas;
            int points;
        public:
            Fase(int i = - 1, bool dois_jgd = false, bool crg = false);
            virtual ~Fase();

            virtual void executar() = 0;
            void gerenciar_colisoes();
            void salvar();
            bool checarVivos();
            void centraliza_camera();
            void criarJogadores();
            void criarInimigos(std::string caminho);
            void criarCenario(std::string caminho);
            void carregarJogadores();
            void carregarInimigos();
        };
    }    
}
