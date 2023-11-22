#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, bool pro, bool esp):
        Entidade(pos),
        damaged((bool)0),
        timer(),
        lento(false),
        morte(false),
        projetil(pro),
        escudo(esp),
        pulando(false),
        pulo(0.f),
        vida(10)
        {

        }
        Personagem::~Personagem()
        {
            vida = 0;
        }
        int Personagem::getVida()
        {
            return vida;
        }
        void Personagem::setVida(int v)
        {
            vida = v;
        }
        void Personagem::TomarDano(int d)
        {
            setVida(getVida() - d);
            /*corpo.setFillColor(sf::Color::Red);
            damaged = true;
            timer = clock();*/
        }
        void Personagem::morreu()
        {
            morte = true;
        }
        bool Personagem::getMorto()
        {
            return morte;
        }
        bool Personagem::usaArma()
        {
            return projetil;
        }
        bool Personagem::usaEscudo()
        {
            return escudo;
        }
        bool Personagem::getMorte()
        {
            return morte;
        }
        void Personagem::ResetColor()
        {
             corpo.setFillColor(sf::Color::Green);
             damaged = false;
        }
        bool Personagem::getDamaged()
        {
            return damaged;
        }
        void Personagem::lentidao(bool l)
        {
            lento = l;
        }

        bool Personagem::getLento()
        {
            return lento;
        }

        void Personagem::setLento(bool b)
        {
            lento = b;
        }
    }
}