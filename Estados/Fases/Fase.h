#pragma once

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../../Entidades/Personagens/Jogador2.h"
#include "../../Entidades/Personagens/Inim_Facil.h"
#include "../../Entidades/Personagens/Inim_Medio.h"
#include "../../Entidades/Obstaculos/Obst_Facil.h"
#include "../../Entidades/Obstaculos/Obst_Medio.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
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
