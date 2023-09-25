#include "projetil.hpp"

Projetil::Projetil(const sf::Vector2f pos, Jogador *jogador)
    : Entidade(pos, Identidade::IDs::Projetil),
      velocidade(5.0f),
      jogador(jogador),
      dano(4)
{
   Imagem.setColor(sf::Color::Yellow);
}

void Projetil::atualizar()
{
    Imagem.move(velocidade, 0.0f);

    desenhar();

    if (Imagem.getPosition().x > 1920.0f)
    {
        cout << "sai da tela" << endl;
        velocidade = 0.0f;
        Imagem.setColor(sf::Color::Transparent);
    }
}

void Projetil::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    switch (outraEnt->getID())
    {
    case (Identidade::IDs::jogador):
    {
        cout << "Jogador atingido" << endl;
        outraEnt->vida -= dano;
        outraEnt->setPos(sf::Vector2f(posOutro.x - 75.0f, posOutro.y - 25.0f));
        delete this;
    }
    break;
    }
}