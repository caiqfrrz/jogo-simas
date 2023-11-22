#pragma once

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../../Entidades/Personagens/Jogador2.h"
#include "../../Entidades/Personagens/Fantasma.h"
#include "../../Entidades/Obstaculos/Caixa.h"
#include "../../Entidades/Obstaculos/Espinho.h"
#include "../../Entidades/Obstaculos/Gosma.h"
#include "../../Entidades/Obstaculos/Plataforma.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../../Gerenciadores/Gerenciador_Personagens.h"
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
            Gerenciadores::Gerenciador_Personagens gP;

        public:
            Fase(int i = - 1);
            ~Fase();

            virtual void executar() = 0;
            void gerenciar_colisoes();
            void criarJogadores();
            void criarInimMedios();
            void criarCenario(std::string caminho);
        };
    }    
}
