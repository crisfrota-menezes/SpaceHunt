#include "ente.hpp"

Ente::Ente(const Identidade::IDs id):identificador(id){
}
Ente::~Ente(){
}

const Identidade::IDs Ente::getID() const{
    return identificador;
}

void Ente::setGGrafico(GerenciadorGrafico* Grafico){
    pGrafico = Grafico;
}

void Ente::desenhar(){
    pGrafico->desenhaElemento(Imagem);
}

GerenciadorGrafico* SpaceHunt::Ente::pGrafico = nullptr;
