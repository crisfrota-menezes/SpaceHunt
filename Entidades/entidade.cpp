#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const Identidade::IDs id):Ente(id), pos(pos)
{
    corpo.setPosition(pos);
}

Entidade::~Entidade()
{
}

const sf::RectangleShape Entidade::getCorpo()
{
    return corpo;
}

void Entidade::setPos(const sf::Vector2f pos)
{
    corpo.setPosition(pos);
    this->pos = pos;
}

sf::Vector2f Entidade::getPos()
{
    return pos;
}


int Entidade::getDano()
{
    return dano;
}