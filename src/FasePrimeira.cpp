#include "../Estados/Fases/FasePrimeira.h"


namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, bool dois_jgd):
        Fase(id, dois_jgd)
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
