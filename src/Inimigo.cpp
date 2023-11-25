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
        std::vector<Projetil>* Inimigo::getVetProj()
        {
            return nullptr;
        }
        void Inimigo::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{ \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"] }" << std::endl;
        }
    }
}