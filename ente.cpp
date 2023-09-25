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

GerenciadorGrafico* SpaceHunt::Ente::pGrafico = nullptr;
