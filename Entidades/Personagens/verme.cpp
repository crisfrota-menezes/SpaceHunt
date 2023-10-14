#include "verme.hpp"

Verme::Verme(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Verme_X, TAMANHO_Verme_Y), jogador, IDs::IDs::Verme)
{
    vida = 1;
    dano = 1;
    inicializa();
}

Verme::~Verme()
{
}

void Verme::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaA2.png", "ANDA", 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoA2.png", "PARADO", 4, 0.20f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 5.2f);
}

void Verme::colisao(Entidade *outraEnt, sf::Vector2f ds)
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