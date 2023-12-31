#pragma once

#include <SFML/Graphics.hpp>

//Adaptado do código base fornecido pelo PETECO

class Ente;

//Dimensões da janela
#define LARGURA_TELA 1024.0
//Dimensões da janela
#define ALTURA_TELA 1024.0


namespace Gerenciadores
{
    // Infraestrutura - SFML
    class Gerenciador_Grafico
    {
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        Gerenciador_Grafico();
        static Gerenciador_Grafico* instancia;
    public:
        ~Gerenciador_Grafico();

        void desenharEnte(Ente* pE);
        void desenhar(sf::RectangleShape* pR);
        void desenhar(sf::Sprite* pT);
        void desenharText(sf::Text* pT);
        void desenharTextura(sf::Texture* pT);
        const bool get_JanelaAberta() const;
        static Gerenciador_Grafico* get_instancia();
        void mostrar();
        void limpar();
        void fecharJanela();
        void resetarCamera();
        void centralizarCamera(sf::Vector2f p);
        sf::Vector2f getCentro();
        sf::RenderWindow* get_Janela() const;
    };
}