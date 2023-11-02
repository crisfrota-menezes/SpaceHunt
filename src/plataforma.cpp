#include "plataforma.hpp"

Plataforma::Plataforma(sf::Vector2f pos) : Obstaculo(pos, Identidade::IDs::plataforma)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEntidade->getPos();
    //sf::Vector2i tamOutro = outraEntidade->getSprite()->getTextureRect().getSize();

    if (outraEntidade->getID() == Identidade::IDs::jogador || outraEntidade->getID() == Identidade::IDs::Uraniano || outraEntidade->getID() == Identidade::IDs::Venusiano || outraEntidade->getID() == Identidade::IDs::Verme)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEntidade));
    }
}

void Plataforma::executar(){

}