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
#include "../../Entidades/Obstaculos/Coracao.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../../Entidades/Personagens/JogadorProjetil.h"
#include "../../Entidades/Personagens/JogadorEscudo.h"
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Observers/ObserverTecla.h"
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
            Observers::ObserverTecla* pObs;
            Gerenciadores::Gerenciador_Colisoes gC;
            std::ostringstream buffer;
            sf::RectangleShape fundo;
            sf::Texture text_fundo;
            bool dois_jogadores;
            bool carregamento;
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
