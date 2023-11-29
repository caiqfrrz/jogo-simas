#include "../Entidades/Personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos,sf::Vector2f vel, bool fant, int dan):
        Personagem(pos, vel),
        dano(dan),
        fantasma(fant),
        nivel_maldade(10)
        {
            
        }
        Inimigo::~Inimigo()
        {

        }
        void Inimigo::executar()
        {
            
        }
        bool Inimigo::ehFantasma()
        {
            return fantasma;
        }
        std::vector<Projetil>* Inimigo::getVetProj()
        {
            return nullptr;
        }

    }
}