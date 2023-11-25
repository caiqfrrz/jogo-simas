#include "../Entidades/Personagens/Jogador.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(JogadorStrategy* jgd, int id):
        Personagem(sf::Vector2f(0, 0),true, false),
        jogador_type(jgd),
        i(id),
        recarga(0),
        last_key(1),
        pontos(0)
        {
            if(i == 1)
                grafico.setJg1(static_cast<Personagem*>(this));
            else if(i == 2)
                grafico.setJg2(static_cast<Personagem*>(this));

            corpo.setFillColor(sf::Color::Green);
            grafico.setPers(static_cast<Personagem*>(this));
        }
        Jogador::~Jogador()
        {

        }
        void Jogador::executar()
        {
            if(!morte)
            {
                grafico.executar();
                mover();

                if(damaged)
                    if(clock() - 1500 > timer)
                    {
                        ResetColor();
                        damaged = false;
                    }
            
            }
            else
            {
                corpo.setFillColor(sf::Color(92, 20, 2));
            }

        }
        void Jogador::mover()
        {
            velocidade = sf::Vector2f(0, 0);
            
            if (pulando)
            {
                velocidade += sf::Vector2f(0, -pulo);

                pulo -= 0.8f;
                nochao = false;
                if(pulo <= 0)
                {
                    pulando = false;
                }
            }
            if (!nochao)
                velocidade += sf::Vector2f(0, 7.f);

            jogador_type->mover();
        }
         /*void Jogador::salvar_tempo(string caminho)
        {
            fstream arquivoOutput(caminho, ios::app);
            std::string linha =  "";
            std::string bolinhas = ".....";
            if(!arquivoOutput)
            {
                std::cout  << " erro!";
            }
            else
            {  

                linha += this->get_nome() + bolinhas;
                arquivoOutput << linha;
                arquivoOutput << this->get_tempo();
                arquivoOutput << "s" << endl;
               

            }
        }*/
        void Jogador::setPosicao(sf::Vector2f pos)
        {
            corpo.setPosition(pos);
        }
        void Jogador::setPulando(bool p, float força)
        {
            pulando = p;
            pulo = força;
        }
        void Jogador::setPulando(bool p)
        {
            pulando = p;
        }
        void Jogador::setLento(bool b)
        {
            lento = b;
        }
        bool Jogador::getLento()
        {
            return lento;
        }

        std::vector<Projetil>* Jogador::getVetProj()
        {
            return jogador_type->getVetProj();
        }
        std::deque<Escudo>* Jogador::getDqEscudo()
        {
            return jogador_type->getFilaEsc();
        }
        void Jogador::salvar(std::ostringstream* entrada)
        {
            
        }

    }
}
