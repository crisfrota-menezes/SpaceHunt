#include "verme.hpp"

Verme::Verme(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, jogador, Identidade::IDs::Verme){
    vida = 1;
    dano = 1;
    inicializa();
}

Verme::~Verme()
{
}

void Verme::inicializa()
{
    animacao.addAnimacao("ANDA",sf::Vector2f(3, 1.5));
    animacao.addAnimacao("PARADO",sf::Vector2f(3, 1.5));
    sprite.setOrigin(sprite.getTexture()->getSize().x / 3.0f, sprite.getTexture()->getSize().y / 5.2f);
}
void Verme::colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)){

}

void Verme::executar(){

}