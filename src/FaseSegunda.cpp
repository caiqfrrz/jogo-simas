#include "../Estados/Fases/FaseSegunda.h"

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda(int id, bool dois_jgd,Estados::Menus::Ranking* pR):
        Fase(id, dois_jgd, pR)
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
            if(checarVivos())
            {
                getName();
                salvar_pontuacao(ARQUIVO_COLOCACAO_1);
                usarfuncaoCriarTextos(pRanking);
                std::cout << "estado 6";
                pGE->setEstadoAtual(6);
            }
        }
    }
}