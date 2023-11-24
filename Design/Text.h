#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"

namespace Design
{
    class Text 
    {
    private:
        sf::Text texto;
        static Gerenciadores::Gerenciador_Grafico* pGG;
    public:
        Text(std::string str = "");
        ~Text();

        void executar();
        void setFont(sf::Font* fonte);
        void setTamanho(unsigned int tam);
        void setCor(sf::Color cor);
        void setPos(sf::Vector2f pos);
        
    };
}