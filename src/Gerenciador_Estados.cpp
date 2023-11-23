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
    estadoAtual(0)
    {
        estados.resize(4);
    }

    Gerenciador_Estados::~Gerenciador_Estados()
    {
        for (int i = 0; i < estados.size(); i++)
            delete estados[i];  
    }

    void Gerenciador_Estados::setEstadoAtual(int i)
    {
        estadoAtual = i;
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

    void Gerenciador_Estados::executar()
    {
        estados[estadoAtual]->executar();
    }
}
