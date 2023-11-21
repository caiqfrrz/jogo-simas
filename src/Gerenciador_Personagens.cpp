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
        std::vector<Entidades::Entidade*> jgdRemove;
        std::vector<Entidades::Entidade*> inimRemove;

        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();

        while(jgd != nullptr)
        {
            Entidades::Personagens::Personagem* jogadores = static_cast<Entidades::Personagens::Personagem*>(*jgd);
            if((jogadores)->getVida() <= 0)
            {
                jgdRemove.push_back((*jgd));
            }
            jgd++;
        }
        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();

        while(inim != nullptr)
        {
            Entidades::Personagens::Personagem* inimigos = static_cast<Entidades::Personagens::Personagem*>(*inim);
            if((inimigos)->getVida() <= 0)
            {
                inimRemove.push_back((*inim));
            }
            inim++;
        }

        for(int i = 0; i<jgdRemove.size(); i++)
        {
            jogadores->remove(jgdRemove[i]);
        }
        for(int i = 0; i<inimRemove.size(); i++)
        {
            inimigos->remove(inimRemove[i]);
        }

    }
}