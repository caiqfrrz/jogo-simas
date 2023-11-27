#include "../Entidades/Obstaculos/Coracao.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Coracao::Coracao(Listas::ListaEntidades* jog, sf::Vector2f pos):
        Obstaculo(pos),
        jogadores(jog)
        {
            textura.loadFromFile("Design/Imagens/coracao.png");
            corpo.setTexture(&textura);
            corpo.setFillColor(sf::Color::Magenta);
        }
        Coracao::~Coracao()
        {

        }
        void Coracao::executar()
        {

        }
        void Coracao::colidir(Entidades::Entidade* pE, bool b)
        {
            std::cout << "ble2";
            if(ativo)
            {
                bool morto = false;
                std::cout << "1";
                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
                std::cout << "2";
                if(pE)
                {
                    while(jgd != nullptr)
                    {
                        std::cout << "3";
                        if(static_cast<Entidades::Personagens::Personagem*>(*jgd)->getMorte() == true)
                        {
                            std::cout << "4";
                            (static_cast<Entidades::Personagens::Personagem*>(*jgd))->reviver();
                            std::cout << "5";
                            morto = true;
                        }
                        jgd++;
                    }
                    if(morto == false)
                    {

                        Entidades::Personagens::Personagem* jgd_aux = static_cast<Entidades::Personagens::Personagem*>(pE);
                        if(jgd_aux->getVida() >= 7)
                        {
                            jgd_aux->setVida(10);
                        }
                        else
                            jgd_aux->setVida(jgd_aux->getVida() + 3);

                    }
                }
                ativo = false;
            }
        }
    }
}