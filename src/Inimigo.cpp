#include "../Entidades/Personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, bool fant, bool at):
        Personagem(pos),
        fantasma(fant),
        atirador(at),
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
        bool Inimigo::ehAtirador()
        {
            return atirador;
        }

    }
}