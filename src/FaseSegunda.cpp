#include "../Estados/Fases/FaseSegunda.h"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda():
        Fase(4)
        {
            criarCenario(ARQUIVO_CENARIO_2);
        }
        FaseSegunda::~FaseSegunda()
        {

        }
        void FaseSegunda::executar()
        {
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            centraliza_camera();
            jogadores.desenhar();
            checarVivos();
        }
    }
}