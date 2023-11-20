#include "../Entidades/Obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, bool dano, bool l):
        Entidade(pos),
        lento(l),
        danoso(dano)
        {
            
        }
        Obstaculo::~Obstaculo()
        {
            
        }
        bool Obstaculo::ehDanoso()
        {
            return danoso;
        }
        bool Obstaculo::ehGosma()
        {
            return lento;
        }
    }
}