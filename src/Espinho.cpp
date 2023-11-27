#include "../Entidades/Obstaculos/Espinho.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos):
        Obstaculo(pos, true)
        {
            textura.loadFromFile("Design/Imagens/espinhos.png");
            corpo.setTexture(&textura);

            corpo.setFillColor(sf::Color::Red);
            morreu();
        }
        Espinho::~Espinho()
        {

        }
        void Espinho::executar()
        {
            
        }
        int Espinho::getDano()
        {
            return dano;
        }
        void Espinho::colidir(Entidade* pE, bool b)
        {
            static_cast<Personagens::Personagem*>(pE)->TomarDano(dano, b);
        }
        int Espinho::dano = 1;
    }
}