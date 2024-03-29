#include "inimigo.hpp"

Inimigo::Inimigo(const sf::Vector2f pos, Jogador *jogador, Identidade::IDs ID) : Personagem(pos, VELOCIDADE_INIMIGO, ID), jogador(jogador), dtAux(0.0f){

}

Inimigo::~Inimigo()
{
}

void Inimigo::atualizaMoveAleatorio()
{
    if (dtAux > 1.0f)
    {
        moveAleatorio = rand() % 3;
        if (moveAleatorio == 0)
        {
            parar();
        }
        else if (moveAleatorio == 1)
        {
            andar(true);
        }
        else
        {
            andar(false);
        }
        dtAux = 0.0f;
    }
}

void Inimigo::atualizar()
{
    sf::Vector2f posJogador = jogador->getPos();
    sf::Vector2f posInimigo = getPos();
    if (fabs(posJogador.x - posInimigo.x) <= VISAO_INIMIGO_X && fabs(posJogador.y - posInimigo.y) <= VISAO_INIMIGO_Y)
    {
        if (posJogador.x - posInimigo.x > 0.0f)
        {
            andar(false);
        }
        else
        {
            andar(true);
        }
    }
    else
    {
        atualizaMoveAleatorio();
    }
   // movimentar(sf::Vector2f(2.0,10.0)); Aqui vou fazer uma estrategia para pegar velocidades diferentes;
    dtAux += relogio.getElapsedTime().asSeconds() * 100;
    relogio.restart();
    animar();
}

