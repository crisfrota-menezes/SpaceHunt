#include "rochas.hpp"

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
    sf::Vector2i tamOutro = outraEnt->getSprite()->getTextureRect().getSize();

    if (outraEnt->getID() == Identidade::IDs::jogador)
    {
        cout << "AI" << endl;
        outraEnt->vida -= dano;
        outraEnt->setPos(sf::Vector2f(posOutro.x, posOutro.y - 50.0f));
        if(outraEnt->vida <= 0)
        {
            delete outraEnt;
            cout << "MORTE POR ROCHA" << endl;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
    else if (outraEnt->getID() == Identidade::IDs::Uraniano || outraEnt->getID() == Identidade::IDs::Verme || outraEnt->getID() == Identidade::IDs::Venusiano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}

void Rochas::executar(){

}