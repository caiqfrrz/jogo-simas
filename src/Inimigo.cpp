#include "../Entidades/Personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, bool fant):
        Personagem(pos),
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
    }
}