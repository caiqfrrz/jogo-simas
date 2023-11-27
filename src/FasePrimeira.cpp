#include "../Estados/Fases/FasePrimeira.h"
#include "../Estados/Fases/FaseSegunda.h"
#include "../Estados/Fases/Fase.h"

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, bool dois_jgd, bool crg) : Fase(id, dois_jgd, crg)
        {
    
            if(!carregamento)
            {
                criarCenario(ARQUIVO_CENARIO_1);
                criarInimigos(ARQUIVO_CENARIO_1);
                criarObstaculos(ARQUIVO_CENARIO_1);
            }
            setpoints(0);
            text_fundo.loadFromFile("Design/Imagens/bg.jpg");
            fundo.setTexture(&text_fundo);
            fundo.setPosition(sf::Vector2f(-500, -500));
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::executar()
        {
            centraliza_camera();
            pGG->get_Janela()->draw(fundo);
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            jogadores.desenhar();
            if (checarVivos() == 1)
            {
                if (dois_jogadores)
                    Estados::Fases::FaseSegunda* fase2_2p = new Estados::Fases::FaseSegunda(3, true, false);
                else
                    Estados::Fases::FaseSegunda* fase2_1p = new Estados::Fases::FaseSegunda(3, false, false);

                pGE->setEstadoAtual(3);
            }
            else if(checarVivos() == 2)
            {
                getName();
                salvar_pontuacao(ARQUIVO_COLOCACAO_1);
                usarfuncaoreSize(pRanking, ARQUIVO_COLOCACAO_1);
                usarfuncaoCriarTextos(pRanking, ARQUIVO_COLOCACAO_1);
                
                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
                Entidades::Personagens::Jogador *jogador = static_cast<Entidades::Personagens::Jogador *>(*jgd);
                (*jogador).setpoints(0);

                pGE->setEstadoAtual(5);
            }

        }
    }
}
