#include "../Entidades/Personagens/Inim_Medio.h"   

namespace Entidades
{
    namespace Personagens
    {
        Inim_Medio::Inim_Medio(sf::Vector2f pos):
        Inimigo(pos),
        dano(2)
        {
            corpo.setFillColor(sf::Color::Yellow);
        }

        Inim_Medio::~Inim_Medio()
        {

        }
        void Inim_Medio::executar()
        {
            //mover();
        }
        void Inim_Medio::mover()
        {
            velocidade = sf::Vector2f(1.f, 0);

            corpo.setPosition(corpo.getPosition() + velocidade);
        }
    }
}