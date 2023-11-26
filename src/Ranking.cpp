#include "../Estados/Menus/Ranking.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;

#define ARQUIVO_COLOCACAO_1 "Design/Imagens/ranking.txt"

namespace Estados
{
    namespace Menus
    {
        Ranking::Ranking(int i, int nb) : Menu(i, 7),
                                          power(1)
        {
            set_valores();
        }
        Ranking::~Ranking()
        {
        }
        void Ranking::set_valores()
        {
            imagem->loadFromFile("Design/Imagens/castle.jpeg");

            bg->setTexture(*imagem);

            textos.resize(7);
            coords = {{100, 220}, {100, 300}, {100, 380}, {100, 462}, {100, 549}, {100, 635}, {100, 715}};
            tamanhos = {20, 20, 20, 20, 20, 20, 20};

            for (int i = 0; i < 7; i++)
            {
                textos[i].setFont(*fonte);
                textos[i].setPosition(coords[i]);
                textos[i].setCharacterSize(tamanhos[i]);
                textos[i].setFillColor(sf::Color::White);
                textos[i].setOutlineColor(sf::Color::Black);
            }
        
            titulo.setFont(*fonte);
            titulo.setString("RANKINGS");
            titulo.setOutlineColor(sf::Color(72, 221, 137));
            titulo.setOutlineThickness(5.f);
            titulo.setPosition({150, 40});
            titulo.setCharacterSize(170);
            titulo.setFillColor(sf::Color::White);

            pos = 5;
        }
        void Ranking::selecionar()
        {
        }
        void Ranking::executar()
        {
            desenhar();
            loop_evento();
        }
        void Ranking::desenhar()
        {
            sortRank(ARQUIVO_COLOCACAO_1);
            pGG->limpar();
            pGG->resetarCamera();
            pGG->desenhar(bg);

            for (int i = 0; i < 7; i++)
            {
                pGG->get_Janela()->draw(textos[i]);
            }

            pGG->get_Janela()->draw(titulo);
        }
        void Ranking::loop_evento()
        {
            sf::Event evento;
            while (pGG->get_Janela()->pollEvent(evento))
            {
                if (evento.type == sf::Event::Closed)
                    pGG->fecharJanela();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    pGE->setEstadoAtual(0);
            }
        }
        void Ranking::sortRank(std::string caminho)
        {
            std::ifstream txt(ARQUIVO_COLOCACAO_1);
            std::string linha1;
            std::string linha11;
            std::string linha2;
            std::string linha22;
            int i = 0;
            bool trocou = false;

            if (power == 1)
            {
                if (!txt)
                {
                    std::cout << "Error ao abrir o arquivo." << std::endl;
                }
                else
                {
                    try
                    {
                        if (getline(txt, linha1, ','))
                        {
                            getline(txt, linha11);

                            while (getline(txt, linha2, ','))
                            {
                                getline(txt, linha22);

                                int value1 = std::stoi(linha11);
                                int value2 = std::stoi(linha22);

                                if (value1 < value2)
                                {
                                    trocou = true;
                                    textos[i].setString(linha2 + "," + linha22);
                                    textos[i + 1].setString(linha1 + "," + linha11);
                                }
                                else
                                {
                                    linha1 = linha2;
                                    linha11 = linha22;
                                }
                                
                                i++;
                            }

                            std::cout << "hehe ";
                        }
                    }
                    catch (const std::invalid_argument &e)
                    {
                        std::cerr << "Invalid argument during numeric conversion: " << e.what() << std::endl;
                        // Handle the error or add more detailed error reporting.
                    }

                    txt.close();

                    std::ofstream outputFile(ARQUIVO_COLOCACAO_1, std::ios::trunc);

                    if (!outputFile)
                    {
                        std::cout << "Error ao abrir o arquivo para escrita." << std::endl;
                    }
                    else
                    {
                        for (int j = 0; j <= i; j++)
                        {
                            const sf::String sfmlString = textos[j].getString();
                            std::basic_string<unsigned char> utf8String = sfmlString.toUtf8();
                            std::string stdString(utf8String.begin(), utf8String.end());
                            outputFile << stdString << std::endl;
                        }
                        outputFile.close();
                    }
                }
                if (trocou == false)
                {
                    power = 0;
                }
            }
        }
        void Ranking::CriarTextos(std::string caminho)
        {
            std::ifstream txt(caminho);
            std::string linha;
            std::string espaco = "  ";
            int i = 0;
            if (!txt)
            {
                std::cout << "error ao abrir";
            }
            else
            {
                while (getline(txt, linha) && i < textos.size())
                {
                    textos[i].setString(linha);
                    textos[i].setFont(*fonte);
                    i++;
                }
                txt.close();
            }
        }
        int Ranking::reSize(std::string caminho)
        {
            std::ifstream txt(caminho);
            std::string linha;
            std::string espaco = "  ";
            int i = 0;
            if (!txt)
            {
                std::cout << "error ao abrir";
            }
            else
            {
                while (getline(txt, linha))
                {
                    i++;
                }
                txt.close();
            }
            textos.resize(i);
            return i;
        }
        
    }
}