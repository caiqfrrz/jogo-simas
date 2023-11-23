#include "../Estados/Fases/FasePrimeira.h"


namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira():
        Fase(0)
        {
            criarCenario(ARQUIVO_CENARIO_1);
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::executar()
        { 
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            centraliza_camera();
            jogadores.desenhar();
            if(checarVivos())
            {
                pGE->setEstadoAtual(2);
            }
        }
    }    
}
