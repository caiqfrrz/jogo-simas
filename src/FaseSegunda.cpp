#include "../Estados/Fases/FaseSegunda.h"
#include "../Estados/Fases/Fase.h"

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda(int id, bool dois_jgd, bool crg) : Fase(id, dois_jgd, crg)
        {   
            if(!carregamento)
            {
                criarCenario(ARQUIVO_CENARIO_2);
                criarInimigos(ARQUIVO_CENARIO_2);
                criarObstaculos(ARQUIVO_CENARIO_2);
            }
            setpoints(0);
            pGG->limpar();
            pGG->resetarCamera();
            if(!text_fundo.loadFromFile("Design/Imagens/bg.jpg"))
                std::cout <<"ruim";
            fundo.setTexture(&text_fundo);
            fundo.setPosition(sf::Vector2f(-500, -500));
        }
        FaseSegunda::~FaseSegunda()
        {

        }
        void FaseSegunda::executar()
        {
            centraliza_camera();
            pGG->get_Janela()->draw(fundo);
            obstaculos.desenhar();
            inimigos.executar();
            jogadores.executar();
            gerenciar_colisoes();
            jogadores.desenhar();
            checarVivos();
            if (checarVivos() > 0)
            {
                std::cout << "be";
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