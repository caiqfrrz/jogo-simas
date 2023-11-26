#include "../Estados/Fases/FaseSegunda.h"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda(int id, bool dois_jgd, bool crg):
        Fase(id, dois_jgd, crg)
        {
            criarCenario(ARQUIVO_CENARIO_2);
            if(!carregamento)
                criarInimigos(ARQUIVO_CENARIO_2);
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
            if(checarVivos())
            {
                pGE->setEstadoAtual(6);
            }
        }
    }
}