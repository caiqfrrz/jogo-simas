#include "../Estados/Fases/FaseSegunda.h"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda():
        Fase(3)
        {
            criarCenario(ARQUIVO_CENARIO_2);
        }
        FaseSegunda::~FaseSegunda()
        {

        }
        void FaseSegunda::executar()
        {
            centraliza_camera();
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            jogadores.desenhar();
            checarVivos();
        }
    }
}