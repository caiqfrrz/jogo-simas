#include "../Estados/Fases/Fase.h"

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace Estados
{
    namespace Fases
    {
        Fase::Fase(int i):
        jogadores(),
        obstaculos(),
        inimigos(),
        Estado(i)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
            criarJogadores();
            criarInimMedios();
        }
        Fase::~Fase()
        {

        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao();
        }
        bool Fase::checarVivos()
        {
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
            bool acabou = true;

            while(jgd != nullptr)
            {
                Entidades::Personagens::Personagem* jogadores = static_cast<Entidades::Personagens::Personagem*>(*jgd);
                if((jogadores)->getVida() <= 0)
                {
                    jogadores->morreu();
                }
                jgd++;
            }
            Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos.get_primeiro();

            while(inim != nullptr)
            {
                Entidades::Personagens::Personagem* inimigos = static_cast<Entidades::Personagens::Personagem*>(*inim);
                if((inimigos)->getVida() <= 0)
                {
                    inimigos->morreu();
                }
                else
                    acabou = false;
                inim++;
            }
            return acabou;
        }
        void Fase::centraliza_camera()
        {
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
            Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores.get_primeiro()++;
        
            Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(*jgd); 
            Entidades::Personagens::Personagem* jogador2 = static_cast<Entidades::Personagens::Personagem*>(*jgd2);
            
            if((jogadores.get_primeiro()++) != nullptr && jogador2->getMorto() == false && jogador->getMorto() == false)
                pGG->centralizarCamera((((*(jogadores.get_primeiro()))->getPosicao())+((*(jogadores.get_primeiro()++))->getPosicao()))/(float)2);
            else if (jogadores.get_primeiro()++ == nullptr && jogadores.get_primeiro() != nullptr)
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            else if(jogador->getMorto() == true && jogadores.get_primeiro()++ != nullptr)
                pGG->centralizarCamera((*(jogadores.get_primeiro()++))->getPosicao());
            else if(jogador2->getMorto() == true)
                pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            else 
            {
                pGG->centralizarCamera(sf::Vector2f(0.f , 0.f));
            }
        }
        void Fase::criarJogadores()
        {
            jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador2()));
            jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador()));
        }
        void Fase::criarInimMedios()
        {
        }
        void Fase::criarCenario(std::string caminho)
        {
            srand(time(0));

            int cont[2] = {0,0};
            int num[2];

            for(int i = 0; i < 2; i++)
            {
                num[i] = (int)rand() % 3 + 3;
            }

            std::ifstream arquivo(caminho);
            if (!arquivo)
            {
                std::cout<<"Não foi possível acessar o arquivo de cenário."<<std::endl;
                exit(1);
            }
            std::string linha;
            
            Entidades::Entidade* aux = nullptr;

            int j = 0;
            for (int i = 0; std::getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                        // Plataforma:
                    case '0':
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Plataforma(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'C':
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Caixa(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'X':
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Espinho(sf::Vector2f(j * TAM, i * TAM)));
                        if(aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'G':
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Gosma(sf::Vector2f(j * TAM, i * TAM)));
                        if(aux)
                            obstaculos.incluir(aux);
                        break;
                    case 'F':
                    {
                        if(cont[0] < num[0])
                        {
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Fantasma(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);
                            cont[0]++;
                        }
                        break;
                    }
                    
                    case 'I':
                    {
                        if(cont[1] < num[1])
                        {
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Atirador(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if(aux)
                                inimigos.incluir(aux);
                            cont[1]++;
                        }
                        break;
                    }
                    
                    default:
                        break;
                    }
                    j++;
                }
            }
            arquivo.close();
        }
    }
}
