#include "uraniano.hpp"

Uraniano::Uraniano(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Uraniano_X, TAMANHO_Uraniano_Y), jogador, IDs::IDs::Uraniano)
{
    vida = 2;
    dano = 1;
    inicializa();
}

Uraniano::~Uraniano()
{
}

void Uraniano::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaA1.png", "ANDA", 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoA1.png", "PARADO", 6, 0.15f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 5.0f);
}

void Uraniano::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    switch (outraEnt->getID())
    {
    case (IDs::IDs::jogador):
    {
        outraEnt->operator--();
        outraEnt->setPos(sf::Vector2f(outraEnt->getPos().x, outraEnt->getPos().y - 25.0f));
    }
    break;
    }
}