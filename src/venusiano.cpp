#include "../include/Entidades/venusiano.hpp"

Venusiano::Venusiano(const sf::Vector2f pos, Jogador *joga) : Inimigo(pos, joga, Identidade::IDs::Venusiano)
{
    vida = 3;
    dano = 3;
    inicializa();
}

Venusiano::~Venusiano(){
    jogador = nullptr;
}

void Venusiano::inicializa()
{
    animacao.addAnimacao("ANDA", sf::Vector2f(3, 1.5));
    animacao.addAnimacao("PARADO", sf::Vector2f(3, 1.5));
    sprite.setOrigin(sprite.getTexture()->getSize().x / 3.0f, sprite.getTexture()->getSize().y / 5.7f);
}

void Venusiano::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    switch (outraEnt->getID())
    {
    case (Identidade::IDs::jogador):
    {
        outraEnt->operator-(this);
        outraEnt->setPos(sf::Vector2f(outraEnt->getPos().x, outraEnt->getPos().y - 25.0f));
    }
    break;
    }

   
}

void Venusiano::executar(){
}