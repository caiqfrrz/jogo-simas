#include "../Estados/Fases/FasePrimeira.h"
#include "../Estados/Fases/FaseSegunda.h"


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
            if(checarVivos())
            {
                if(dois_jogadores)
                    Estados::Fases::FaseSegunda* fase2_2p = new Estados::Fases::FaseSegunda(3, true, false);
                else
                    Estados::Fases::FaseSegunda* fase2_1p = new Estados::Fases::FaseSegunda(3, false, false);

                pGE->setEstadoAtual(3);
            }
        }
    }    
}
