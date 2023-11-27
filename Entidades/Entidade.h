#pragma once

#include "../Ente.h"
#include <sstream>

// Largura e Altura padrão para as entidades
#define TAM 50.f

namespace Entidades
{
    class Entidade: public Ente
    {
    protected:
        sf::Vector2f posicao;
        sf::Texture textura;
        bool nochao;
        bool morte;
        bool ativo;
        sf::Vector2f velocidade;
    public:
        Entidade(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
        ~Entidade();

        virtual void executar() = 0;
        virtual void salvar(std::ostringstream* entrada) = 0;
        virtual void colidir(Entidade* pE, bool b);
        virtual void colidir();
        virtual bool getAtivo();
        virtual void setAtivo(bool b);
        virtual void morreu();
        virtual bool getMorte();
        const sf::Vector2f getPosicao() const { return corpo.getPosition(); }
        const sf::Vector2f getTamanho() const { return corpo.getSize(); }
        const sf::Vector2f getVelocidade () const { return velocidade; }
        void setPosicao(sf::Vector2f p);
        void setNochao(bool n) { nochao = n; }
        bool getNochao() {return nochao;}
        void setVelocidade(sf::Vector2f v);
    };
}
