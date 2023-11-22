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
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
            Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores.get_primeiro()++;
        
            Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(*jgd); 
            Entidades::Personagens::Personagem* jogador2 = static_cast<Entidades::Personagens::Personagem*>(*jgd2);

            gP.checarPersonagens();
            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            if((jogadores.get_primeiro()++) != nullptr && jogador2->getMorto() == false && jogador->getMorto() == false)
                pGG->centralizarCamera((((*(jogadores.get_primeiro()))->getPosicao())+((*(jogadores.get_primeiro()++))->getPosicao()))/(float)2);
            else if (jogadores.get_primeiro()++ == nullptr && jogadores.get_primeiro() != nullptr)
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            else if(jogador->getMorto() == true && jogadores.get_primeiro()++ != nullptr)
                pGG->centralizarCamera((*(jogadores.get_primeiro()++))->getPosicao());
            else if(jogador2->getMorto() == true)
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            else 
            {
                pGG->centralizarCamera(sf::Vector2f(0.f , 0.f));
            }
            jogadores.desenhar();
            obstaculos.desenhar();
        }
    }    
}
