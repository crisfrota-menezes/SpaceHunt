#include "ente.hpp"

Ente::Ente(const Identidade::IDs id):identificador(id),sprite(),textura(){
    sprite.setTextureRect(sf::IntRect(250,250,30,30)); // padrão para objetos inicializados mal
    sprite.setColor(sf::Color::Blue);
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
    pGrafico->desenhaElemento(sprite);
}

GerenciadorGrafico* SpaceHunt::Ente::pGrafico = nullptr;
