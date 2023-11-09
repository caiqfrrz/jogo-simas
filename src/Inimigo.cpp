#include "../Entidades/Personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos):
        Personagem(pos),
        nivel_maldade(10)
        {

        }
        Inimigo::~Inimigo()
        {

        }
        void Inimigo::executar()
        {
            
        }

    }
}