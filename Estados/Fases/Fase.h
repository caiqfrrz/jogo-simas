#pragma once

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../Estados/Menus/Ranking.h"
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
            Estados::Menus::Ranking* pRanking;
            std::string playerName;
            Gerenciadores::Gerenciador_Colisoes gC;
            sf::Font* fonte;
            bool dois_jogadores;
            static int points;
        public:
            Fase(int i = - 1, bool dois_jgd = false,Estados::Menus::Ranking* pR = nullptr);
            ~Fase();

            virtual void executar() = 0;
            void gerenciar_colisoes();
            int checarVivos();
            void centraliza_camera();
            void criarJogadores();
            void criarInimMedios();
            void criarCenario(std::string caminho);
            void salvar_pontuacao(std::string caminho);
            void getName();
            void usarfuncaoCriarTextos(Estados::Menus::Ranking* objRanking, std::string caminho);
            void usarfuncaoreSize(Estados::Menus::Ranking* objRanking, std::string caminho);
            void setpoints(const int p);
            int getpoints();
        };
    }    
}
