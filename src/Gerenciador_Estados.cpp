#include "../Gerenciadores/Gerenciador_Estados.h"
#include "../Estados/Estado.h"
#include <iostream>

namespace Gerenciadores
{
    Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

    Gerenciador_Estados* Gerenciador_Estados::get_instancia()
    {
        if (!instancia)
            instancia = new Gerenciador_Estados;
        
        return instancia;
    }

    Gerenciador_Estados::Gerenciador_Estados():
    estadoAtual(0),
    estadoAnterior(-1)
    {
        estados.resize(6);
    }

    Gerenciador_Estados::~Gerenciador_Estados()
    {
        std::cout <<"teste";
        for (int i = 0; i < estados.size(); i++)
        {
            delete estados[i];  
        }
    }

    void Gerenciador_Estados::setEstadoAtual(const int i)
    {
            
        estadoAnterior = estadoAtual;
        estadoAtual = i;
    }
    const int Gerenciador_Estados::getEstadoAtual()
    {
        return estadoAtual;
    }
    int Gerenciador_Estados::getEstadoAnterior()
    {
        return estadoAnterior;
    }
    void Gerenciador_Estados::addEstado (Estados::Estado* pEstado)
    {
        if (pEstado)
            if (!estados.at(pEstado->get_id()))
                estados.at(pEstado->get_id()) = pEstado;
            else
            {
                delete estados.at(pEstado->get_id());
                estados.at(pEstado->get_id()) = pEstado;
            }
    }
    void Gerenciador_Estados::pausePMenu()
    {
        if(estados[2])
        {
            delete estados[2];
            estados[2] = nullptr;
        }
        if(estados[3])
        {
            delete estados[3];
            estados[3] = nullptr;
        }
        setEstadoAtual(0);
    }
    void Gerenciador_Estados::executar()
    {
        estados[estadoAtual]->executar();
    }
}
