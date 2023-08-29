#include "plataforma.hpp"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::plataforma, CAMINHO_PLATAFORMA)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::Uraniano || outraEntidade->getID() == IDs::IDs::Venusiano || outraEntidade->getID() == IDs::IDs::Verme)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEntidade));
    }
}