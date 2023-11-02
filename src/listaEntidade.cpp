#include "../include/Listas/listaEntidade.hpp"

ListaEntidades::ListaEntidades() : lista(){
    limpar();
}

ListaEntidades::~ListaEntidades(){
    limpar();
}

void ListaEntidades::inserir(Entidade *ent)
{
    lista.InserirElemento(ent);
}

void ListaEntidades::remover(int pos)
{
    lista.RemoverElemento(pos);
}

void ListaEntidades::remover(Entidade *ent)
{
    lista.RemoverElemento(ent);
}

Entidade* ListaEntidades::operator[](int pos){
    return lista.operator[](pos);
}

void ListaEntidades::executar(){
    int tam = lista.getTamanho();
    Entidade *aux = nullptr;
    for (int i = 0; i < tam; i++)
    {
        aux = lista.operator[](i);
        aux->executar();
    }
}

void ListaEntidades::limpar(){
    lista.LimpaLista();
}

const int ListaEntidades::getTamanho() const{
    return lista.getTamanho();
}

void ListaEntidades::inicializar(){
    Entidade* aux = nullptr;

    for(int i = 0; i < lista.getTamanho();i++){
        aux = lista.operator[](i);
        aux->inicializar();
    }
}