#include "../Gerenciadores/Gerenciador_Personagens.h"

namespace Gerenciadores
{
    Gerenciador_Personagens::Gerenciador_Personagens(Listas::ListaEntidades* jog, Listas::ListaEntidades* inim):
    jogadores(jog),
    inimigos(inim)
    {

    }
    Gerenciador_Personagens::~Gerenciador_Personagens()
    {

    }
    void Gerenciador_Personagens::checarPersonagens()
    {
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();

        while(jgd != nullptr)
        {
            Entidades::Personagens::Personagem* jogadores = static_cast<Entidades::Personagens::Personagem*>(*jgd);
            if((jogadores)->getVida() <= 0)
            {
                jogadores->morreu();
            }
            jgd++;
        }
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();

        while(inim != nullptr)
        {
            Entidades::Personagens::Personagem* inimigos = static_cast<Entidades::Personagens::Personagem*>(*inim);
            if((inimigos)->getVida() <= 0)
            {
                inimigos->morreu();
            }
            inim++;
        }

    }
}