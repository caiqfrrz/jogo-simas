#include "../Entidades/Personagens/Inim_Medio.h"   

namespace Entidades
{
    namespace Personagens
    {
        Inim_Medio::Inim_Medio(sf::Vector2f pos):
        Inimigo(pos),
        dano(2),
        recarregar(0),
        num_proj(0),
        novo(sf::Vector2f(10, 5))
        {
            corpo.setFillColor(sf::Color::Yellow);
        }

        Inim_Medio::~Inim_Medio()
        {

        }
        void Inim_Medio::executar()
        {
            mover();
            atirar();
        }
        void Inim_Medio::mover()
        {
            velocidade = sf::Vector2f(1.f, 0);

            corpo.setPosition(corpo.getPosition() + velocidade);
        }
        void Inim_Medio::atirar()
        {
            if(recarregar == 0)
            {
                novo.setPosicao(this->getPosicao());
                novo.executar();
                recarregar = TEMPO_RECARGA;
            }
            else
            {
                recarregar--;
                novo.executar();
            }
        }
    }
}