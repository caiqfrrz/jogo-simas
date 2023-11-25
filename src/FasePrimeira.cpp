#include "../Estados/Fases/FasePrimeira.h"
#include "../Estados/Menus/Ranking.h"

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, bool dois_jgd, Estados::Menus::Ranking* pR):
        Fase(id, dois_jgd, pR)
        {
            criarCenario(ARQUIVO_CENARIO_1);
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::executar()
        { 
            centraliza_camera();
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            jogadores.desenhar();
            if(checarVivos())
            {
                if(dois_jogadores)
                    pGE->setEstadoAtual(5);
                else
                    pGE->setEstadoAtual(4);
            }
        }
    }    
}
