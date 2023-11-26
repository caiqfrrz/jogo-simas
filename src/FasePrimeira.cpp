#include "../Estados/Fases/FasePrimeira.h"


namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, bool dois_jgd, bool crg):
        Fase(id, dois_jgd, crg)
        {
            criarCenario(ARQUIVO_CENARIO_1);
            if(!carregamento)
                criarInimigos(ARQUIVO_CENARIO_1);
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
                pGE->setEstadoAtual(4);
            }
        }
    }    
}
