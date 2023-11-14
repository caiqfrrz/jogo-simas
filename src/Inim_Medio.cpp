#include "../Entidades/Personagens/Inim_Medio.h"   

namespace Entidades
{
    namespace Personagens
    {
        Inim_Medio::Inim_Medio(sf::Vector2f pos):
        Inimigo(pos),
        dano(2),
        recarregar(0)
        {
            corpo.setFillColor(sf::Color::Yellow);

            for(int i = 0; i< 50 ; i++)
            {
                Projetil novo = Projetil(sf::Vector2f(20, 5));
                novo.setPos(this->getPosicao());
                projetil_vec.push_back(novo);
            }
        }

        Inim_Medio::~Inim_Medio()
        {

        }
        void Inim_Medio::executar()
        {
            //mover();
            atirar();
        }
        void Inim_Medio::mover()
        {
            velocidade = sf::Vector2f(1.f, 0);

            corpo.setPosition(corpo.getPosition() + velocidade);
        }
        void Inim_Medio::atirar()
        {
            for(int i = 0; i< projetil_vec.size(); i++)
            {
                projetil_vec[i].desenhar();
                projetil_vec[i].atirar(12);
            }
        }
    }
}