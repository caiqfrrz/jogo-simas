#include "../Entidades/Obstaculos/Caixa.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos, bool ativo):
        Obstaculo(pos, false)
        {
            setAtivo(ativo);
            textura.loadFromFile("Design/Imagens/caixa.png");
            corpo.setTexture(&textura);
            corpo.setFillColor(sf::Color(82, 16, 16));

            morreu();
        }
        Caixa::~Caixa()
        {

        }
        void Caixa::executar()
        {
            
        }
        void Caixa::colidir(Entidade* pE, bool b)
        {
            Entidades::Personagens::Personagem* aux = static_cast<Entidades::Personagens::Personagem*>(pE);

            aux->setLento(false);
            vida -=1;
            if(vida <= 0)
                setAtivo(false);
        }
        void Caixa::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"id\": \"caixa\", \"ativo\": " << ativo << ", \"posicao\": [" << getPosicao().x << ", " << getPosicao().y << "]}";
        }
    }
}