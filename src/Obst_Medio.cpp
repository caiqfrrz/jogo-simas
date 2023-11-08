#include "../Entidades/Obstaculos/Obst_Medio.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Obst_Medio::Obst_Medio(sf::Vector2f pos):
        Obstaculo(pos, true)
        {
            corpo.setFillColor(sf::Color::Red);
        }
        Obst_Medio::~Obst_Medio()
        {

        }
        void Obst_Medio::executar()
        {
            
        }
        int Obst_Medio::getDano()
        {
            return dano;
        }
        int Obst_Medio::dano = 1;
    }
}