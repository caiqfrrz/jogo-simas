#include "../Entidades/Personagens/JogadorEscudo.h"
#include "../Entidades/Personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        JogadorEscudo::JogadorEscudo():
        JogadorStrategy(),
        escudos(0)
        {
            last_key = 0;
        }
        JogadorEscudo::~JogadorEscudo()
        {

        }
        void JogadorEscudo::atacar()
        {
            if (recarga == 0)
                {
                    Escudo aux_escudo = Escudo();
                    if(last_key == 0)
                        aux_escudo.setDirecao("esquerda");
                    
                    else if(last_key == 1)
                        aux_escudo.setDirecao("direita");

                    else 
                        aux_escudo.setDirecao("cima");

                    switch (last_key)
                    {
                    case (2):
                    {
                        aux_escudo.setPosicao(sf::Vector2f(pJog->getPosicao().x - 2.5f, pJog->getPosicao().y - 20.f));
                        break;
                    }
                    case (1):
                    {
                        aux_escudo.setPosicao(sf::Vector2f(pJog->getPosicao().x + 70.f, pJog->getPosicao().y - 2.5f));
                        break;
                    }
                    case (0):
                    {
                        aux_escudo.setPosicao(sf::Vector2f(pJog->getPosicao().x - 40.f, pJog->getPosicao().y - 2.5f));
                        break;
                    }
                    }
                    aux_escudo.lancar();
                    fila_esc.push_back(aux_escudo);

                    if (escudos == 2)
                    {
                        recarga = TEMPO_RECARGA_JOG2;
                        escudos = 0;
                    }
                    else
                    {
                        escudos++;
                        recarga = 10;
                    }
                }
        }
        void JogadorEscudo::executar()
        {
            std::deque<Escudo>::iterator it;
            for (it = fila_esc.begin(); it != fila_esc.end(); it++)
            {
                (*it).executar();
                if ((*it).getDesapareceu())
                    fila_esc.pop_front();
            }
        }
        void JogadorEscudo::mover()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if(pJog->getLento())
                {
                    if (!pJog->getNochao())
                    {
                        pJog->setVelocidade(pJog->getVelocidade() + sf::Vector2f(2.f, 0));
                    }
                }
                else
                {
                    if (pJog->getNochao())
                    {
                        pJog->setVelocidade(sf::Vector2f(6.f, 0));
                    }
                    else if (!pJog->getNochao())
                    {
                        pJog->setVelocidade(pJog->getVelocidade() + sf::Vector2f(6.f, 0));
                    }
                }
                last_key = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if(pJog->getLento())
                {
                    if (!pJog->getNochao())
                    {
                        pJog->setVelocidade(pJog->getVelocidade() + sf::Vector2f(-2.f, 0));
                    }
                }
                else
                {
                    if (pJog->getNochao())
                    {
                        pJog->setVelocidade(sf::Vector2f(-6.f, 0));
                    }
                    else if (!pJog->getNochao())
                    {
                        pJog->setVelocidade(pJog->getVelocidade() + sf::Vector2f(-6.f, 0));
                    }
                }
                last_key = 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pJog->getNochao())
            {
                if(pJog->getLento())
                {
                    pJog->setPulando(true, 15.f);
                }
                else
                {
                    pJog->setPulando(true, 21.f);
                    pJog->setNochao(true);
                }
                
            } 
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                last_key = 2;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && recarga == 0) 
            {
                atacar();
                recarga = TEMPO_RECARGA_JOG;
            }
            else if(recarga > 0)
                recarga--;

            pJog->setPosicao(pJog->getPosicao() + pJog->getVelocidade());
            pJog->setNochao(false);
            executar();
        }
        void JogadorEscudo::setJog(Jogador* jgd)
        {
            pJog = jgd;
        }
        std::vector<Projetil>* JogadorEscudo::getVetProj()
        {
            return nullptr;
        }
        std::deque<Escudo>* JogadorEscudo::getFilaEsc()
        {
            return &fila_esc;
        }
        void JogadorEscudo::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"morto\": " << pJog->getMorte() << ", \"vida\": " << pJog->getVida() << ", \"posicao\": [" << pJog->getPosicao().x << ", " << pJog->getPosicao().y << "], \"velocidade\": [" << pJog->getVelocidade().x << ", " << pJog->getVelocidade().y << "], \"escudos\": [";

            std::deque<Escudo>::iterator it;
            it = fila_esc.begin();
            if(fila_esc.size() != 0)
            {
                (*it).salvar(entrada);
                it++;
            }
            while(it != fila_esc.end())
            {
                if((*it).getAtivo() == true)
                {
                    (*entrada << ", ");
                    (*it).salvar(entrada);
                }
                it++;
            }

            (*entrada) << "]}";
        }
    }
}