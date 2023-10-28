#include "uraniano.hpp"

Uraniano::Uraniano(const sf::Vector2f pos, Jogador *joga) : Inimigo(pos, joga, Identidade::IDs::Uraniano){
    vida = 2;
    dano = 2;
    inicializa();
}

Uraniano::~Uraniano(){
    jogador = nullptr;
}

void Uraniano::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaA1.png", "ANDA", 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoA1.png", "PARADO", 6, 0.15f, sf::Vector2f(3, 1.5));
    sprite.setOrigin(sprite.getTexture()->getSize().x / 3.0f, sprite.getTexture()->getSize().y / 5.0f);
}

void Uraniano::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    switch (outraEnt->getID())
    {
    case (IDs::IDs::jogador):
    {
        outraEnt->operator-(this);
        outraEnt->setPos(sf::Vector2f(outraEnt->getPos().x, outraEnt->getPos().y - 25.0f));
    }
    break;
    }
}


void Uraniano::executar(){
}