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
        Fase::Fase(int i, bool dois_jgd, bool crg):
        carregamento(crg),
        dois_jogadores(dois_jgd),
        n_atiradores(0),
        n_chefoes(0),
        n_fantasmas(0),
        jogadores(),
        obstaculos(),
        points(0),
        inimigos(),
        Estado(i)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);

            if(!carregamento)
            {
                criarJogadores();
            }
            else
            {
                carregarJogadores();
                carregarInimigos();
            }
        }
        Fase::~Fase()
        {
            if(pGE->getEstadoAtual() == Estado::id)
                salvar();
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao();
        }
        void Fase::salvar()
        {
            // Salvando Jogadores:
            std::ofstream arquivo(ARQUIVO_JOGADOR);  
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            arquivo << "";

            Listas::Lista<Entidades::Entidade>::Iterador j = jogadores.get_primeiro();

            buffer.str("");
            buffer << "{ \"jogo\": \"jogo\" ,\"fase\":";

            if(pGE->getEstadoAtual() == 2)
            {
                buffer << " 1, ";
            }
            else if(pGE->getEstadoAtual() == 4)
            {
                buffer << " 2, ";
            }
            if(dois_jogadores)
            {
                buffer << "\"n_jogadores\": 2, \"jogadores\": [";
            }
            else
            {
                buffer << "\"n_jogadores\": 1, \"jogadores\": [";
            }
            if (j != nullptr)
            {
                ((*j))->salvar(&buffer);
                j++;
            }
            while (j != nullptr)
            {
                buffer << ",";
                ((*j))->salvar(&buffer);
                j++;
            }
            buffer << "]}";

            arquivo << buffer.str();

            arquivo.close();
            // Salvando inimigos: 

            
            std::ofstream arquivo_inimigo(ARQUIVO_INIMIGO);  
            if (!arquivo_inimigo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador i = inimigos.get_primeiro();
            buffer.str("");
            buffer << "{ \"n_fantasmas\": " << n_fantasmas << ", \"n_atiradores\": " << n_atiradores << ", \"n_chefoes\": " << n_chefoes << ", \"membros\": [ " ;
            if (i != nullptr)
            {
                (*i)->salvar(&buffer);
                i++;
            }
            while (i != nullptr)
            {
                buffer << ",";
                (*i)->salvar(&buffer);
                i++;
            }
            buffer << "]}";

            arquivo_inimigo << buffer.str();

            arquivo_inimigo.close();
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
                    points += 23;
                }
                else
                    acabou = false;
                inim++;
            }
            return acabou;
        }
        void Fase::centraliza_camera()
        {
            if(dois_jogadores)
            {
                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
                Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores.get_primeiro()++;
        
                Entidades::Personagens::Personagem* jogador = static_cast<Entidades::Personagens::Personagem*>(*jgd); 
                Entidades::Personagens::Personagem* jogador2 = static_cast<Entidades::Personagens::Personagem*>(*jgd2);

                if(jogador->getMorto() && !jogador2->getMorto())
                {
                    pGG->centralizarCamera((jogador2)->getPosicao());
                }
                else if (!jogador->getMorto() && jogador2->getMorto())
                {
                    pGG->centralizarCamera((jogador)->getPosicao());
                }
                else if(!jogador->getMorto() && !jogador2->getMorto())
                {
                    pGG->centralizarCamera((((*(jogadores.get_primeiro()))->getPosicao())+((*(jogadores.get_primeiro()++))->getPosicao()))/(float)2);
                }
            }
            else
            {
                pGG->centralizarCamera((*jogadores.get_primeiro())->getPosicao());
            }
        }
        void Fase::criarJogadores()
        {
            if (dois_jogadores)
            {
                Entidades::Personagens::JogadorProjetil *jgd1 = new Entidades::Personagens::JogadorProjetil();
                Entidades::Personagens::JogadorEscudo *jgd2 = new Entidades::Personagens::JogadorEscudo();
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd2, 2)));
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd1, 1)));
                jgd1->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro())));
                jgd2->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro()++)));
            }
            else
            {
                Entidades::Personagens::JogadorProjetil *jgd1 = new Entidades::Personagens::JogadorProjetil();
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd1, 1)));
                jgd1->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro())));
            }
        }
        void Fase::criarInimigos(std::string caminho)
        {
            std::cout <<"inimteste";
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
                    case 'F':
                    {
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Fantasma(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            inimigos.incluir(aux);
                        cont[0]++;
                        n_fantasmas++;
                        
                        break;
                    }
                    
                    case 'I':
                    {
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Atirador(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                        if(aux)
                            inimigos.incluir(aux);
                        cont[1]++;
                        n_atiradores++;
                        
                        break;
                    }
                    case 'B':
                    {
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Personagens::Boss(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                        if(aux)
                            inimigos.incluir(aux);
                        n_chefoes++;
                        
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
        void Fase::carregarJogadores()
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;   
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            auto jogadores_json = json["jogadores"];

            auto jogador = jogadores_json[0];

            float posx = jogador["posicao"][0];
            float posy = jogador["posicao"][1];
            float velx = jogador["velocidade"][0];
            float vely = jogador["velocidade"][1];

            if(dois_jogadores)
            {
                auto jogador = jogadores_json[1];

                float posx = jogador["posicao"][0];
                float posy = jogador["posicao"][1];
                float velx = jogador["velocidade"][0];
                float vely = jogador["velocidade"][1];

                Entidades::Personagens::JogadorEscudo* jgd2_strategy = new Entidades::Personagens::JogadorEscudo();

                Entidades::Personagens::Jogador* jgd2 = new Entidades::Personagens::Jogador(jgd2_strategy, 2,
                                                        sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));

                jgd2_strategy->setJog(jgd2);

                jogadores.incluir(static_cast<Entidades::Entidade*>(jgd2));
            }           
            
            Entidades::Personagens::JogadorProjetil* jgd1 = new Entidades::Personagens::JogadorProjetil();

            Entidades::Personagens::Jogador* jgd = new Entidades::Personagens::Jogador(jgd1, 1,
                                                        sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));
            jgd1->setJog(jgd);

            jogadores.incluir(static_cast<Entidades::Entidade*>(jgd));       
        }
        void Fase::carregarInimigos()
        {
            std::cout << inimigos.get_tamanho();

            std::ifstream arquivo(ARQUIVO_INIMIGO);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;   
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            n_atiradores = json["n_atiradores"];
            n_fantasmas = json["n_fantasmas"];
            n_chefoes = json["n_chefoes"];

            auto membros = json["membros"];
            for(int i = 0; i < membros.size(); i++)
            {
                std::string identificador = membros[i]["id"];
                float posx = membros[i]["posicao"][0];
                float posy = membros[i]["posicao"][1];
                float velx = membros[i]["velocidade"][0];
                float vely = membros[i]["velocidade"][1];

                sf::Vector2f pos = sf::Vector2f(posx, posy);
                sf::Vector2f vel = sf::Vector2f(velx, vely);

                if(identificador == "fantasma")
                {
                    inimigos.incluir(static_cast<Entidades::Entidade*> (new Entidades::Personagens::Fantasma(&jogadores, pos, vel)));
                }
                else if(identificador == "atirador")
                {
                    Entidades::Personagens::Atirador* atir = new Entidades::Personagens::Atirador(&jogadores, pos, vel);
                    std::vector<Entidades::Projetil>* pVec_proj = atir->getVetProj();

                    auto projeteis = membros[i]["projeteis"];

                    for(int j = 0; i < projeteis.size(); i++)
                    {
                        float posx_proj = projeteis[j]["posicao"][0];
                        float posy_proj = projeteis[j]["posicao"][1];
                        std::string dir = projeteis[j]["direcao"];

                        sf::Vector2f pos_proj = sf::Vector2f(posx_proj, posy_proj);

                        Entidades::Projetil* proj = new Entidades::Projetil(dir, sf::Vector2f(10, 5), pos_proj);
                        pVec_proj->push_back(*proj);
                    }
                    inimigos.incluir(static_cast<Entidades::Entidade*>(atir));
                }
                else if (identificador == "chefao")
                {
                    Entidades::Personagens::Boss* chef = new Entidades::Personagens::Boss(&jogadores, pos, vel);
                    std::vector<Entidades::Projetil>* pVec_proj = chef->getVetProj();

                    auto projeteis = membros[i]["projeteis"];

                    for(int j = 0; j < projeteis.size(); j++)
                    {
                        float posx_proj = projeteis[j]["posicao"][0];
                        float posy_proj = projeteis[j]["posicao"][1];
                        float velx_proj = projeteis[j]["velocidade"][0];
                        float vely_proj = projeteis[j]["velocidade"][1];

                        sf::Vector2f pos_proj = sf::Vector2f(posx_proj, posy_proj);
                        sf::Vector2f vel_proj = sf::Vector2f(velx_proj, vely_proj);

                        Entidades::Projetil* proj = new Entidades::Projetil(sf::Vector2f(50, 25), pos_proj, vel_proj);
                        pVec_proj->push_back(*proj);
                    }
                    inimigos.incluir(static_cast<Entidades::Entidade*>(chef));
                }
            }
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
