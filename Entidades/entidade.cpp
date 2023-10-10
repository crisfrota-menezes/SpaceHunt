#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const Identidade::IDs id):Ente(id),dano(0){
    setPos(pos);
}

Entidade::~Entidade(){
}

void Entidade::setPos(const sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

sf::Vector2f Entidade::getPos(){
    return sprite.getPosition();
}


int Entidade::getDano(){
    return dano;
}