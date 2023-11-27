#pragma once

#include "json.hpp"

#define ARQUIVO_JOGADOR "Saves/jogadores.json"
#define ARQUIVO_INIMIGO "Saves/inimigos.json"

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../Estados/Menus/Ranking.h"
#include "../../Entidades/Personagens/Fantasma.h"
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
            Estados::Menus::Ranking* pRanking;
            std::string playerName;
            Observers::ObserverTecla* pObs;
            Gerenciadores::Gerenciador_Colisoes gC;
            std::ostringstream buffer;
            sf::RectangleShape fundo;
            sf::Texture text_fundo;
            sf::Font* fonte;
            bool dois_jogadores;
            bool carregamento;
            static int points;
        public:
            Fase(int i = - 1, bool dois_jgd = false, bool crg = false, Estados::Menus::Ranking* pR = nullptr);
            virtual ~Fase();
            virtual void executar() = 0;
            void gerenciar_colisoes();
            void salvar();
            int checarVivos();
            void centraliza_camera();
            void criarJogadores();
            void criarInimigos(std::string caminho);
            void criarCenario(std::string caminho);
            void carregarJogadores();
            void carregarInimigos();
            void salvar_pontuacao(std::string caminho);
            void getName();
            void usarfuncaoCriarTextos(Estados::Menus::Ranking* objRanking, std::string caminho);
            void usarfuncaoreSize(Estados::Menus::Ranking* objRanking, std::string caminho);
            void setpoints(const int p);
            int getpoints();
        };
    }    
}
