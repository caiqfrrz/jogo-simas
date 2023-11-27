#include "../Entidades/Personagens/JogadorProjetil.h"
#include "../Entidades/Personagens/Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        JogadorProjetil::JogadorProjetil() : JogadorStrategy()
        {
        }
        JogadorProjetil::~JogadorProjetil()
        {
        }
        void JogadorProjetil::mover()
        {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if (pJog->getLento())
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (pJog->getLento())
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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pJog->getNochao())
            {
                if (pJog->getLento())
                {
                    pJog->setPulando(true, 15.f);
                }
                else
                {
                    pJog->setPulando(true, 21.f);
                    pJog->setNochao(true);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                last_key = 3;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && recarga == 0)
            {
                atacar();
                recarga = TEMPO_RECARGA_JOG;
            }

            if (recarga > 0)
                recarga--;

            pJog->setPosicao(pJog->getPosicao() + pJog->getVelocidade());
            pJog->setNochao(false);
            executar();
        }
        void JogadorProjetil::atacar()
        {
            std::string s = "";

            if (last_key == 0)
            {
                s = "esquerda";
            }
            else if (last_key == 1)
                s = "direita";
            else
            {
                s = "cima";
            }

            Projetil novoProj(s, sf::Vector2f(10, 5));

            novoProj.setPosicao(sf::Vector2f(pJog->getPosicao().x + 20.f, pJog->getPosicao().y + 15.f));
            vet_proj.push_back(novoProj);
        }
        void JogadorProjetil::executar()
        {
            for (int i = 0; i < vet_proj.size(); i++)
            {
                vet_proj[i].executar();
            }

            for (int i = 0; i < vet_proj.size(); i++)
            {
                if (fabs(vet_proj[i].getPosicao().x) - fabs(pJog->getPosicao().x) > 800 || fabs(vet_proj[i].getPosicao().y) - fabs(pJog->getPosicao().y) > 600)
                {
                    vet_proj.erase(vet_proj.begin() + i);
                }
            }
        }
        void JogadorProjetil::setJog(Jogador *jgd)
        {
            pJog = jgd;
        }
        std::vector<Projetil> *JogadorProjetil::getVetProj()
        {
            return &vet_proj;
        }
        std::deque<Escudo> *JogadorProjetil::getFilaEsc()
        {
            return nullptr;
        }
        void JogadorProjetil::salvar(std::ostringstream* entrada)
        {
            (*entrada) << "{\"morto\": " << pJog->getMorte() << ", \"posicao\": [" << pJog->getPosicao().x << ", " << pJog->getPosicao().y << "], \"velocidade\": [" << pJog->getVelocidade().x << ", " << pJog->getVelocidade().y << "], \"projeteis\": [";

            std::vector<Projetil>::iterator it;
            for(it = vet_proj.begin(); it != vet_proj.end(); it++)
            {
                (*it).salvar(entrada);
                if(it != vet_proj.end() - 1 && (*it).getAtivo() == true)
                {
                    if(it != vet_proj.end() - 1) 
                    {
                        if(vet_proj.size() != 1)
                            (*entrada << ", ");
                    }
                }
            }

            (*entrada) << "]}";
        }
    }
}