#include "../Estados/Fases/Fase.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

int Estados::Fases::Fase::points(0);

namespace Estados
{
    namespace Fases
    {
        Fase::Fase(int i, bool dois_jgd, bool crg) : carregamento(crg),
                                                     dois_jogadores(dois_jgd),
                                                     jogadores(),
                                                     obstaculos(),
                                                     inimigos(),
                                                     Estado(i)
        {
            pRanking = Estados::Menus::Ranking::get_instancia(5);
            fundo.setSize(sf::Vector2f(6000, 1600));

            setpoints(0);
            fonte = new sf::Font();
            fonte->loadFromFile("Design/Fontes/Pixel-Digivolve.otf");
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);

            pObs = new Observers::ObserverTecla();

            if (!carregamento)
            {
                criarJogadores();
            }
            else
            {
                carregarJogadores();
                carregarInimigos();
                carregarObstaculos();
            }
        }
        Fase::~Fase()
        {
            salvar();
            delete fonte;
            pRanking = nullptr;
            pObs = nullptr;
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao();
        }
        void Fase::salvar()
        {
            // Salvando Jogadores:
            std::ofstream arquivo_obst(ARQUIVO_OBSTACULO);
            if (!arquivo_obst)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador o = obstaculos.get_primeiro();

            buffer.str("");
            buffer << "{ \"jogo\": \"jogo\" ,\"obstaculos\": [";

            if (o != nullptr)
            {
                ((*o))->salvar(&buffer);
                o++;
            }
            while (o != nullptr)
            {
                buffer << ",";
                ((*o))->salvar(&buffer);
                o++;
            }
            buffer << "]}";

            arquivo_obst << buffer.str();

            buffer.str("");

            arquivo_obst.close();

            // Salvando Jogadores:
            std::ofstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);
            }

            Listas::Lista<Entidades::Entidade>::Iterador j = jogadores.get_primeiro();

            buffer.str("");
            buffer << "{ \"jogo\": \"jogo\" ,\"fase\":";

            if (pGE->getEstadoAtual() == 4)
            {
                if (pGE->getEstadoAnterior() == 2)
                    buffer << " 1, ";
                else if (pGE->getEstadoAnterior() == 3)
                    buffer << " 2, ";
            }
            else if (pGE->getEstadoAtual() == 2)
            {
                buffer << " 1, ";
            }
            else if (pGE->getEstadoAtual() == 3)
            {
                buffer << " 2, ";
            }

            if (dois_jogadores)
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

            buffer.str("");

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
            buffer << "{\"membros\": [ ";
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

            buffer.str("");

            arquivo_inimigo.close();
        }
        int Fase::checarVivos()
        {
            Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
            int acabou = 0;

            while (jgd != nullptr)
            {
                Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                {
                    if ((jogador)->getVida() <= 0)
                    {
                        jogador->morreu();
                    }
                }
                jgd++;
            }
            jgd = jogadores.get_primeiro();
            bool todos_jgd_mortos = true;
            
            while (jgd != nullptr)
            {
                Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                if ((jogador)->getVida() > 0)
                {
                    todos_jgd_mortos = false;
                }
                jgd++;
            }
            
            Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos.get_primeiro();
            jgd = jogadores.get_primeiro();
            Entidades::Personagens::Jogador *jogador = static_cast<Entidades::Personagens::Jogador *>(*jgd);
            bool vivos = false;

            while (inim != nullptr)
            {
                Entidades::Personagens::Personagem *inimigos = static_cast<Entidades::Personagens::Personagem *>(*inim);
                if ((inimigos)->getVida() <= 0)
                {
                    if (inimigos->getMorte() == false)
                    {
                        inimigos->morreu();
                        points += 11;
                        (*jogador).setpoints(points);
                    }
                }
                else
                {
                    vivos = true;
                }

                inim++;
            }
            if (acabou == 0 && vivos == false)
            {
                acabou = 1;
            }
            if(todos_jgd_mortos)
                acabou = 2;

            return acabou;
        }
        void Fase::usarfuncaoreSize(Estados::Menus::Ranking *objRanking, std::string caminho)
        {
            objRanking->reSize(caminho);
        }

        void Fase::centraliza_camera()
        {
            if (dois_jogadores)
            {
                Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores.get_primeiro();
                Listas::Lista<Entidades::Entidade>::Iterador jgd2 = jogadores.get_primeiro()++;

                Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                Entidades::Personagens::Personagem *jogador2 = static_cast<Entidades::Personagens::Personagem *>(*jgd2);

                if (jogador->getMorte() && !jogador2->getMorte())
                {
                    pGG->centralizarCamera((jogador2)->getPosicao());
                }
                else if (!jogador->getMorte() && jogador2->getMorte())
                {
                    pGG->centralizarCamera((jogador)->getPosicao());
                }
                else if (!jogador->getMorte() && !jogador2->getMorte())
                {
                    pGG->centralizarCamera((((*(jogadores.get_primeiro()))->getPosicao()) + ((*(jogadores.get_primeiro()++))->getPosicao())) / (float)2);
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
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd2, 2, sf::Vector2f(120, 300))));
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd1, 1, sf::Vector2f(180, 300))));
                jgd1->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro())));
                jgd2->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro()++)));
            }
            else
            {
                Entidades::Personagens::JogadorProjetil *jgd1 = new Entidades::Personagens::JogadorProjetil();
                jogadores.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Jogador(jgd1, 1, sf::Vector2f(120, 300))));
                jgd1->setJog(static_cast<Entidades::Personagens::Jogador *>(*(jogadores.get_primeiro())));
            }
        }
        void Fase::criarInimigos(std::string caminho)
        {
            std::srand(time(NULL));

            int cont[3] = {0, 0, 0};
            int num[3];

            for (int i = 0; i < 2; i++)
            {
                num[i] = (int)rand() % 3 + 3;
            }

            std::ifstream arquivo(caminho);

            if (!arquivo)
            {
                std::cout << "Não foi possível acessar o arquivo de cenário." << std::endl;
                exit(1);
            }
            std::string linha;

            Entidades::Entidade *aux = nullptr;

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
                        if(cont[0] < num[0])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Fantasma(2 , &jogadores, sf::Vector2f(j * TAM, i * TAM)));
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
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Atirador(5 , &jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);

                            cont[1]++;
                        }
                        break;
                    }
                    case 'B':
                    {
                        if(cont[2] < num[2])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Boss(10, &jogadores, &inimigos, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);
                        
                            cont[2]++; 
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
        void Fase::criarObstaculos(std::string caminho)
        {
            std::srand(time(NULL));

            int cont[4] = {0, 0, 0, 0};
            int num[4];

            for (int i = 0; i < 3; i++)
            {
                num[i] = (int)rand() % 3 + 3;
            }

            std::ifstream arquivo(caminho);
            if (!arquivo)
            {
                std::cout << "Não foi possível acessar o arquivo de cenário." << std::endl;
                exit(1);
            }
            std::string linha;

            Entidades::Entidade *aux = nullptr;

            int j = 0;
            for (int i = 0; std::getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                        // Plataforma:
                    case 'C':
                        if(cont[0] < num[0])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Caixa(sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                            cont[0]++;
                        }
                        break;
                    
                    case 'X':
                        if(cont[1] < num[1])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Espinho(sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);

                            cont[1]++;
                        }
                        break;
                    case 'G':
                        if(cont[2] < num[2])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Gosma(sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                            cont[2]++;
                        }
                        break;
                    case 'L':
                        if(cont[3] < num[3])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Coracao(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                        }
                    default:
                        break;
                    }
                    j++;
                }
            }
            arquivo.close();
        }
        void Fase::carregarObstaculos()
        {
            std::ifstream arquivo(ARQUIVO_OBSTACULO);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            auto obstaculos_json = json["obstaculos"];

            for(int i = 0; i<obstaculos_json.size(); i++)
            {
                std::string identificador = obstaculos_json[i]["id"];
                float posx = obstaculos_json[i]["posicao"][0];
                float posy = obstaculos_json[i]["posicao"][1];

                sf::Vector2f pos = {posx, posy};

                if(identificador == "espinho")
                {
                    Entidades::Obstaculos::Espinho* esp = new Entidades::Obstaculos::Espinho(pos);
                    obstaculos.incluir(static_cast<Entidades::Entidade*> (esp));
                }
                else if (identificador == "caixa")
                {
                    int ativo = obstaculos_json[i]["ativo"];
                    Entidades::Obstaculos::Caixa* caixa = new Entidades::Obstaculos::Caixa(pos, (bool)ativo);
                    obstaculos.incluir(static_cast<Entidades::Entidade*> (caixa));
                }
                else if(identificador == "gosma")
                {
                    Entidades::Obstaculos::Gosma* gosma = new Entidades::Obstaculos::Gosma(pos);
                    obstaculos.incluir(static_cast<Entidades::Entidade*> (gosma));
                }
                else if(identificador == "coracao")
                {
                    int ativo = obstaculos_json[i]["ativo"];
                    Entidades::Obstaculos::Coracao* coracao = new Entidades::Obstaculos::Coracao(&jogadores, pos, (bool)ativo);
                    obstaculos.incluir(static_cast<Entidades::Entidade*> (coracao));
                }
                else if(identificador == "plataforma")
                {
                    Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(pos);
                    obstaculos.incluir(static_cast<Entidades::Entidade*> (plat));
                }
            }
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
            int morto = jogador["morto"];
            int vida = jogador["vida"];

            if (dois_jogadores)
            {
                auto jogador2 = jogadores_json[1];

                float posx2 = jogador2["posicao"][0];
                float posy2 = jogador2["posicao"][1];
                float velx2 = jogador2["velocidade"][0];
                float vely2 = jogador2["velocidade"][1];
                int morto = jogador2["morto"];
                int vida = jogador2["vida"];

                auto escudos = jogador2["escudos"];

                Entidades::Personagens::JogadorEscudo *jgd2_strategy = new Entidades::Personagens::JogadorEscudo();
                std::deque<Entidades::Escudo> *fila_esc = jgd2_strategy->getFilaEsc();

                for (int i = 0; i < escudos.size(); i++)
                {
                    float posx_esc = escudos[i]["posicao"][0];
                    float posy_esc = escudos[i]["posicao"][1];
                    short int opacidade = escudos[i]["opacidade"];
                    int contagem = escudos[i]["contagem"];
                    int lancando = escudos[i]["lancando"];
                    int parou = escudos[i]["parou"];
                    std::string dir = escudos[i]["direcao"];

                    sf::Vector2f pos_esc = sf::Vector2f(posx_esc, posy_esc);

                    Entidades::Escudo *esc = new Entidades::Escudo(dir, pos_esc, (bool)lancando, contagem, opacidade, (bool)parou);
                    fila_esc->push_back(*esc);
                }

                Entidades::Personagens::Jogador *jgd2 = new Entidades::Personagens::Jogador(jgd2_strategy, 2, sf::Vector2f(posx2, posy2), sf::Vector2f(velx2, vely2), vida);

                jgd2_strategy->setJog(jgd2);

                if (morto)
                    jgd2->morreu();

                jogadores.incluir(static_cast<Entidades::Entidade *>(jgd2));
            }

            Entidades::Personagens::JogadorProjetil *jgd1 = new Entidades::Personagens::JogadorProjetil();
            std::vector<Entidades::Projetil> *vec_proj = jgd1->getVetProj();

            auto projeteis = jogador["projeteis"];

            for (int i = 0; i < projeteis.size(); i++)
            {
                float posx_proj = projeteis[i]["posicao"][0];
                float posy_proj = projeteis[i]["posicao"][1];
                std::string dir = projeteis[i]["direcao"];
                int ativo = projeteis[i]["ativo"];

                sf::Vector2f pos_proj = sf::Vector2f(posx_proj, posy_proj);

                Entidades::Projetil *proj = new Entidades::Projetil(dir, sf::Vector2f(10, 5), pos_proj, (bool)ativo);
                vec_proj->push_back(*proj);
            }


            Entidades::Personagens::Jogador *jgd = new Entidades::Personagens::Jogador(jgd1, 1, sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), vida);


            jgd1->setJog(jgd);


            if (morto)
                jgd->morreu();


            jogadores.incluir(static_cast<Entidades::Entidade*>(jgd));
        }
        void Fase::carregarInimigos()
        {

            std::ifstream arquivo(ARQUIVO_INIMIGO);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe" << std::endl;
                exit(2);
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            auto membros = json["membros"];
            for (int i = 0; i < membros.size(); i++)
            {
                int morto = membros[i]["morto"];

                if (morto == 0)
                {
                    std::string identificador = membros[i]["id"];

                    float posx = membros[i]["posicao"][0];
                    float posy = membros[i]["posicao"][1];
                    float velx = membros[i]["velocidade"][0];
                    float vely = membros[i]["velocidade"][1];
                    int vida = membros[i]["vida"];

                    sf::Vector2f pos = sf::Vector2f(posx, posy);
                    sf::Vector2f vel = sf::Vector2f(velx, vely);

                    if (identificador == "fantasma")
                    {
                        inimigos.incluir(static_cast<Entidades::Entidade *>(new Entidades::Personagens::Fantasma(vida, &jogadores, pos, vel)));
                    }
                    else if (identificador == "atirador")
                    {
                        Entidades::Personagens::Atirador *atir = new Entidades::Personagens::Atirador(vida, &jogadores, pos, vel);
                        std::vector<Entidades::Projetil> *pVec_proj = atir->getVetProj();

                        auto projeteis = membros[i]["projeteis"];

                        for (int j = 0; i < projeteis.size(); i++)
                        {
                            float posx_proj = projeteis[j]["posicao"][0];
                            float posy_proj = projeteis[j]["posicao"][1];
                            std::string dir = projeteis[j]["direcao"];
                            int ativo = projeteis[j]["ativo"];

                            sf::Vector2f pos_proj = sf::Vector2f(posx_proj, posy_proj);

                            Entidades::Projetil *proj = new Entidades::Projetil(dir, sf::Vector2f(10, 5), pos_proj, (bool)ativo);
                            pVec_proj->push_back(*proj);
                        }
                        inimigos.incluir(static_cast<Entidades::Entidade *>(atir));
                    }
                    else if (identificador == "chefao")
                    {
                        Entidades::Personagens::Boss *chef = new Entidades::Personagens::Boss(vida, &jogadores, &inimigos, pos, vel);

                        inimigos.incluir(static_cast<Entidades::Entidade *>(chef));
                    }
                }
            }
        }
        void Fase::getName()
        {
            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::F5)))
            {
                sf::Event event;
                while (pGG->get_Janela()->pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        pGG->get_Janela()->close();
                    }
                    else if (event.type == sf::Event::TextEntered)
                    {
                        // Handle ASCII characters only
                        if (event.text.unicode < 128)
                        {
                            char typedChar = static_cast<char>(event.text.unicode);

                            if (typedChar == '\b' && !playerName.empty())
                            {
                                // Handle backspace to erase the last character
                                playerName.pop_back();
                            }
                            else if (typedChar >= 32)
                            {
                                // Append the character to the player name
                                playerName += typedChar;
                            }
                        }
                    }
                }

                pGG->limpar();
                pGG->resetarCamera();
                // Display the entered string on the screen
                if (1)
                {
                    sf::Text text("Escreva seu nome jogador... \n\nAperte F5 para Continuar...", *fonte, 30);
                    sf::Text tex("\n" + playerName, *fonte, 30);
                    pGG->get_Janela()->draw(text);
                    pGG->get_Janela()->draw(tex);
                }
                else
                {
                    std::cerr << "Error loading font file\n";
                }
                pGG->get_Janela()->display();
            }
        }
        void Fase::usarfuncaoCriarTextos(Estados::Menus::Ranking *objRanking, std::string caminho)
        {
            objRanking->CriarTextos(caminho);
        }

        void Fase::setpoints(const int p)
        {
            points = p;
        }
        int Fase::getpoints()
        {
            return points;
        }
        void Fase::salvar_pontuacao(std::string caminho)
        {
            std::ofstream arquivoOutput(caminho, std::ios::app);
            std::string linha = "";
            std::string bolinhas = ",";
            if (!arquivoOutput)
            {
                std::cout << " erro!";
            }
            else
            {
                linha += playerName + bolinhas;
                arquivoOutput << linha;
                arquivoOutput << points;
            }

            arquivoOutput.close();
        }
        void Fase::criarCenario(std::string caminho)
        {
            srand(time(0));

            int cont[3] = {0, 0, 0};
            int num[3];

            for (int i = 0; i < 3; i++)
            {
                num[i] = (int)rand() % 3 + 3;
            }

            std::ifstream arquivo(caminho);
            if (!arquivo)
            {
                std::cout << "Não foi possível acessar o arquivo de cenário." << std::endl;
                exit(1);
            }
            std::string linha;

            Entidades::Entidade *aux = nullptr;

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
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Plataforma(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
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
