#include "../Estados/Fases/FasePrimeira.h"
#include "../Estados/Fases/Fase.h"

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, bool dois_jgd, Estados::Menus::Ranking *pR) : Fase(id, dois_jgd, pR)
        {
            criarCenario(ARQUIVO_CENARIO_1);
            setpoints(0);
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
            if (checarVivos() == 1)
            {
                if (dois_jogadores)
                    pGE->setEstadoAtual(5);
                else
                    pGE->setEstadoAtual(4);
            }
            else if (checarVivos() == 2)
            {
                getName();
                salvar_pontuacao(ARQUIVO_COLOCACAO_1);
                usarfuncaoreSize(pRanking, ARQUIVO_COLOCACAO_1);
                usarfuncaoCriarTextos(pRanking, ARQUIVO_COLOCACAO_1);
                setpoints(0);
                std::cout << getpoints() << " ";

                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
                Entidades::Personagens::Jogador *jogador = static_cast<Entidades::Personagens::Jogador *>(*jgd);
                (*jogador).setpoints(0);

                pGE->setEstadoAtual(6);
            }
        }
    }
}
