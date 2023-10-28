#include "ente.hpp"

Ente::Ente(const Identidade::IDs id):identificador(id),sprite(),textura(){
    sprite.setTextureRect(sf::IntRect(250,250,30,30)); // padrão para objetos inicializados mal
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

sf::Sprite* Ente::getSprite(){
    return &sprite;
}

const sf::Texture* Ente::getTexture() const{
    return &textura;
}

void Ente::SetSprite(){
    sf::IntRect tamanho;
    textura.loadFromImage(pGrafico->CarregaTextura(identificador));
    tamanho.height = textura.getSize().y;
    tamanho.width = textura.getSize().x / 3;
    sprite.setTexture(textura);
    sprite.setTextureRect(tamanho);
    sprite.setScale(0.5,0.5);
}

void Ente::inicializar(){
    SetSprite();
}

GerenciadorGrafico* SpaceHunt::Ente::pGrafico = nullptr;
