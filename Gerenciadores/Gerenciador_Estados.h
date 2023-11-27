#pragma once

//Moderadamente adaptado do código base fornecido pelo PETECO

#include <vector>

namespace Estados
{
    class Estado;
}
/*
Estados:
0 - Menu Principal
1 - Fase 1
2 - Fase 2
*/

namespace Gerenciadores
{
    class Gerenciador_Estados
    {
    private:
        int estadoAtual;
        int estadoAnterior;
        std::vector<Estados::Estado*> estados;
        static Gerenciador_Estados* instancia;
        
        Gerenciador_Estados();
    public:
        ~Gerenciador_Estados();
        
        static Gerenciador_Estados* get_instancia();
        void setEstadoAtual (const int i);
        const int getEstadoAtual();
        int getEstadoAnterior();
        void pausePMenu();
        void addEstado (Estados::Estado* pEstado);
        void executar();
    };
}