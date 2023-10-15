#include "jogador.hpp"

#include <cmath>

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador)
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
    corpo.setOrigin(sf::Vector2f(tam.x / 2.0f, tam.y / 5.8f));
}

void Jogador::atualizar()
{
    atualizarPos();
    animar();
    pGrafico->atualizarCamera(pos);
}

void Jogador::animar()
{
    if (!noChao && !podepular && velFinal.y > 0.0f)
    {
        animacao.atualizar(paraEsquerda, "CAI");
    }
    else if (pulou)
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
    case (IDs::IDs::Uraniano):
    {
        if (vida <= 0)
        {
            cout << "MORTE POR URANIANO" << endl;
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            cout << "AI" << endl;
            noChao = false;
        }
    }
    break;
    case (IDs::IDs::Venusiano):
    {
        if (vida <= 0)
        {
            cout << "MORTE POR VENUSIANO" << endl;
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            cout << "AI" << endl;
            noChao = false;
        }
    }
    break;
    case (IDs::IDs::Verme):
    {
        if (vida <= 0)
        {
            cout << "MORTE POR VERME" << endl;
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            cout << "AI" << endl;
            noChao = false;
        }
    }
    break;
    case (IDs::IDs::plataforma):
    {
        if (ds.y <= 0.0f)
        {
            estaNoChao();
            podePular();
            pulou = false;
            velFinal.y = 0.0f;
        }
    }
    break;
    case (IDs::IDs::Rochas):
    {
        if (vida <= 0)
        {
            cout << "MORTE POR ROCHA" << endl;
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            cout << "AI" << endl;
            noChao = false;
        }
    }
    break;
    }
}