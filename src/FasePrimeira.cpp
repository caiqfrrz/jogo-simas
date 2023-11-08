#include "../Estados/Fases/FasePrimeira.h"

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira():
        Fase(1)
        {
            criarCenario(ARQUIVO_CENARIO_1);
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::executar()
        {
            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            if((jogadores.get_primeiro()++) != nullptr)
                pGG->centralizarCamera((((*(jogadores.get_primeiro()))->getPosicao())+((*(jogadores.get_primeiro()++))->getPosicao()))/(float)2);
            else
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            jogadores.desenhar();
            inimigos.desenhar();
            obstaculos.desenhar();
        }
    }    
}
