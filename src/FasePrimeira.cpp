#include "../Estados/Fases/FasePrimeira.h"


namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira():
        Fase(2)
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
                pGE->setEstadoAtual(3);
            }
        }
    }    
}
