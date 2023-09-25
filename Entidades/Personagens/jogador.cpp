#include "jogador.hpp"

#include <cmath>

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, Identidade::IDs::jogador), noChao(false)
{
    vida = 10;
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaJ.png", "ANDA", 3, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoJ.png", "PARADO", 10, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/PulaJ.png", "PULA", 8, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/CaiJ.png", "CAI", 1, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AtacaJ.png", "ATACA", 4, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/HitJ.png", "HIT", 3, 0.15f, sf::Vector2f(3, 1.5));
    Imagem.setOrigin(sf::Vector2f(Imagem.getTextureRect().width / 2.0f, Imagem.getTextureRect().height / 5.8f));
}

void Jogador::atualizar()
{
    atualizarPos();
    animar();
    pGrafico->atualizarCamera(Imagem.getPosition());
}

void Jogador::animar()
{
    if (!noChao && velFinal.y > 0.0f)
    {
        animacao.atualizar(paraEsquerda, "CAI");
    }
    else if (!noChao)
    {
        animacao.atualizar(paraEsquerda, "PULA");
    }
    else if (atacando)
    {
        animacao.atualizar(paraEsquerda, "ATACA");
    }
    else if (podeMover)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

void Jogador::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    switch (outraEntidade->getID())
    {
    case (Identidade::IDs::Uraniano):
    {
        cout << "AI" << endl;
        vida -= outraEntidade->getDano();
        if (vida <= 0)
        {
            cout << "MORTE POR URANIANO" << endl;
            //delete this;
            cout << "GAME OVER" << endl;
            //exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(Imagem.getPosition().x, Imagem.getPosition().y - 25.0f));
            noChao = false;
        }
    }
    break;
    case (Identidade::IDs::Venusiano):
    {
        cout << "AI" << endl;
        vida -= outraEntidade->getDano();
        if (vida <= 0)
        {
            cout << "MORTE POR VENUSIANO" << endl;
            //delete this;
            cout << "GAME OVER" << endl;
            //exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            noChao = false;
            setPos(sf::Vector2f(Imagem.getPosition().x, Imagem.getPosition().y - 25.0f)); // Aqui está empurrando pra baixo
        }
    }
    break;
    case (Identidade::IDs::Verme):
    {
        cout << "AI" << endl;
        vida -= outraEntidade->getDano();
        if (vida <= 0)
        {
            cout << "MORTE POR VERME" << endl;
            //delete this;
            cout << "GAME OVER" << endl;
            // exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(Imagem.getPosition().x, Imagem.getPosition().y - 25.0f));
            noChao = false;
        }
    }
    case (Identidade::IDs::plataforma):
    {
    }
    }
}

void Jogador::pular()
{
    if (noChao)
    {
        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

void Jogador::podePular()
{
    noChao = true;
}