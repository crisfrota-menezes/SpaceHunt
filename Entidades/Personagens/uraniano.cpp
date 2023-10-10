#include "uraniano.hpp"

Uraniano::Uraniano(const sf::Vector2f pos, Jogador *joga) : Inimigo(pos, joga, Identidade::IDs::Uraniano){
    vida = 2;
    dano = 1;
    inicializa();
}

Uraniano::~Uraniano(){
    jogador = nullptr;
}

void Uraniano::inicializa()
{
    animacao.addAnimacao("ANDA", sf::Vector2f(3, 1.5));
    animacao.addAnimacao("PARADO", sf::Vector2f(3, 1.5));
    sprite.setOrigin(sprite.getTexture()->getSize().x / 3.0f, sprite.getTexture()->getSize().y / 5.0f);
}

void Uraniano::colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)){

}

void Uraniano::executar(){

}