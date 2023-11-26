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
        Fase::Fase(int i, bool dois_jgd, Estados::Menus::Ranking *pR) : dois_jogadores(dois_jgd),
                                                                        jogadores(),
                                                                        obstaculos(),
                                                                        pRanking(pR),
                                                                        inimigos(),
                                                                        Estado(i)
        {
            setpoints(0);
            fonte = new sf::Font();
            fonte->loadFromFile("Design/Fontes/Pixel-Digivolve.otf");
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
            criarJogadores();
            criarInimMedios();
        }
        Fase::~Fase()
        {
            delete fonte;
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao();
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

            while (jgd != nullptr)
            {
                Entidades::Personagens::Personagem *jogador = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                jgd++;
                if (jgd != nullptr)
                {
                    Entidades::Personagens::Personagem *jogador2 = static_cast<Entidades::Personagens::Personagem *>(*jgd);
                    if ((jogador)->getVida() <= 0 && (jogador2)->getVida() <= 0)
                    {
                        acabou = 2;
                    }
                }
                else
                {
                    if ((jogador)->getVida() <= 0)
                    {
                        acabou = 2;
                    }
                }
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
                    if (inimigos->getMorto() == false)
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

            return acabou;
        }
        void Fase::usarfuncaoreSize(Estados::Menus::Ranking* objRanking, std::string caminho)
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

                if (jogador->getMorto() && !jogador2->getMorto())
                {
                    pGG->centralizarCamera((jogador2)->getPosicao());
                }
                else if (!jogador->getMorto() && jogador2->getMorto())
                {
                    pGG->centralizarCamera((jogador)->getPosicao());
                }
                else if (!jogador->getMorto() && !jogador2->getMorto())
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
        void Fase::criarInimMedios()
        {
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
                    sf::Text text("\n Enter your name... \n Type F5 to continue...", *fonte, 30);
                    sf::Text tex(playerName, *fonte, 30);
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

            int cont[2] = {0, 0};
            int num[2];

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
                        // Plataforma:
                    case '0':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Plataforma(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'C':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Caixa(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'X':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Espinho(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;

                    case 'G':
                        aux = static_cast<Entidades::Entidade *>(new Entidades::Obstaculos::Gosma(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        break;
                    case 'F':
                    {
                        if (cont[0] < num[0])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Fantasma(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);
                            cont[0]++;
                        }
                        break;
                    }

                    case 'I':
                    {
                        if (cont[1] < num[1])
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Atirador(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);
                            cont[1]++;
                        }
                        break;
                    }

                    case 'B':
                    {
                        if (1)
                        {
                            aux = static_cast<Entidades::Entidade *>(new Entidades::Personagens::Boss(&jogadores, sf::Vector2f(j * TAM, i * TAM)));
                            if (aux)
                                inimigos.incluir(aux);
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
