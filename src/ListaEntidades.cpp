#include "../Listas/ListaEntidades.h"
#include <iostream>
 
namespace Listas
{
    ListaEntidades::ListaEntidades():
    LEs()
    {

    }
    ListaEntidades::~ListaEntidades()
    {

    }
    void ListaEntidades::incluir(Entidades::Entidade* pE)
    {
        LEs.incluir(pE);
    }
    void ListaEntidades::remove(Entidades::Entidade* pE)
    {
        LEs.remove(pE);
    }
    const int ListaEntidades::get_tamanho() const
    {
        return LEs.get_tamanho();
    }
    void ListaEntidades::desenhar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->desenhar();
            aux++;
        }
    }
    void ListaEntidades::executar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();

        while (aux != nullptr)
        {
            (*aux)->executar();
            aux++;
        }    

    }
    Lista<Entidades::Entidade>::Iterador ListaEntidades::get_primeiro()
    {
        return LEs.get_primeiro();
    }
}
