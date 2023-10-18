#include "rochas.hpp"

Rochas::Rochas(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, sf::Vector2f(TAMANHO_Rochas_X, TAMANHO_Rochas_Y), IDs::IDs::Rochas, CAMINHO_Rochas)
{
    dano = 4;
}

Rochas::~Rochas()
{
}

void Rochas::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador)
    {
        outraEnt->operator-(this);
        outraEnt->setPos(sf::Vector2f(posOutro.x - 50.0f, posOutro.y - 50.0f));
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
    else if (outraEnt->getID() == IDs::IDs::Uraniano || outraEnt->getID() == IDs::IDs::Verme || outraEnt->getID() == IDs::IDs::Venusiano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}