#include "../include/Entidades/rochas.hpp"

Rochas::Rochas(sf::Vector2f pos) : Obstaculo(pos, Identidade::IDs::Rochas)
{
    dano = 4;
}

Rochas::~Rochas()
{
}

void Rochas::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    //sf::Vector2i tamOutro = outraEnt->getSprite()->getTextureRect().getSize();

    if (outraEnt->getID() == Identidade::IDs::jogador)
    {
        outraEnt->operator-(this);
        outraEnt->setPos(sf::Vector2f(posOutro.x, posOutro.y - 50.0f));
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
    else if (outraEnt->getID() == Identidade::IDs::Uraniano || outraEnt->getID() == Identidade::IDs::Verme || outraEnt->getID() == Identidade::IDs::Venusiano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}

void Rochas::executar(){

}