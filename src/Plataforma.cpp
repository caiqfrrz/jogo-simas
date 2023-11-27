#include "../Entidades/Obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos):
        Obstaculo(pos)
        {
            textura.loadFromFile("Design/Imagens/plataforma.jpg");
            corpo.setTexture(&textura);
            morreu();
        }
        Plataforma::~Plataforma()
        {

        }
        void Plataforma::executar()
        {

        }
        void Plataforma::colidir(Entidade* pE, bool b)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            aux->setLento(false);
        }
        void Plataforma::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"id\": \"plataforma\", \"posicao\": [" << getPosicao().x << ", " << getPosicao().y << "]}";
        }
    }
}