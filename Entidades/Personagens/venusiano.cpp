#include "venusiano.hpp"

Venusiano::Venusiano(const sf::Vector2f pos, Jogador *joga) : Inimigo(pos, joga, Identidade::IDs::Venusiano)
{
    vida = 4;
    dano = 2;
    inicializa();
}

Venusiano::~Venusiano(){
    jogador = nullptr;
}

void Venusiano::inicializa()
{
    animacao.addAnimacao("ANDA",sf::Vector2f(3, 1.5));
    animacao.addAnimacao("PARADO", sf::Vector2f(3, 1.5));
    sprite.setOrigin(sprite.getTexture()->getSize().x / 3.0f, sprite.getTexture()->getSize().y / 5.7f);
}

void Venusiano::colisao(Entidade *outraEnt, sf::Vector2f ds){

}

void Venusiano::executar(){

}