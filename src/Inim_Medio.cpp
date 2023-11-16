#include "../Entidades/Personagens/Inim_Medio.h"   

namespace Entidades
{
    namespace Personagens
    {
        Inim_Medio::Inim_Medio(sf::Vector2f pos):
        Inimigo(pos),
        dano(2),
        recarregar(0),
        num_proj(0)
        {
            corpo.setFillColor(sf::Color::Yellow);

            Projetil* novo = new Projetil(sf::Vector2f(10, 5));
        }

        Inim_Medio::~Inim_Medio()
        {

        }
        void Inim_Medio::executar()
        {
            if(recarregar == 0)
            {
                if(num_proj < projetil_vec.size())
                {
                    novo->executar();
                    recarregar = 100;
                }
            }
            else
                recarregar--;
        }
        void Inim_Medio::mover()
        {
            velocidade = sf::Vector2f(1.f, 0);

            corpo.setPosition(corpo.getPosition() + velocidade);
        }
        void Inim_Medio::atirar()
        {
            
        }
    }
}