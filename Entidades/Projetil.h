#pragma once

#include "Entidade.h"
#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        int dano;
        std::string direcao;
    public:
        Projetil(std::string dir = "", sf::Vector2f tam = {0,0}, sf::Vector2f pos = {0,0}, bool at = true);
        Projetil(sf::Vector2f tam = {0,0}, sf::Vector2f pos = {0,0}, sf::Vector2f vel = {0,0});
        ~Projetil();
        void executar();
        void atirar();
        void colidir(Entidade* pE, bool b);
        void colidir();
        void reset();
        int getDano();
        void setVelocidade(sf::Vector2f v);
        void salvar(std::ostringstream* entrada);
        void salvar(std::ostringstream* entrada, bool chefao);
    };
}