#include "../include/Gerenciadores/gerenciadorEvento.hpp"

GerenciadorEvento *GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento() : pGrafico(pGrafico->getGerenciadorGrafico())
{
}

GerenciadorEvento::~GerenciadorEvento()
{
}

GerenciadorEvento *GerenciadorEvento::getGerenciadorEvento()
{
    if (pEvento == nullptr)
    {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}

void GerenciadorEvento::setJogador(Jogador *pJogador)
{
    this->pJogador = pJogador;
}

Jogador *GerenciadorEvento::getJogador()
{
    return pJogador;
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case sf::Keyboard::A:
        pJogador->andar(true);
        break;
    case sf::Keyboard::D:
        pJogador->andar(false);
        break;
    case sf::Keyboard::W:
        pJogador->pular();
        break;
    case sf::Keyboard::Left:
        pJogador->andar(true);
        break;
    case sf::Keyboard::Right:
        pJogador->andar(false);
        break;
    case sf::Keyboard::Up:
        pJogador->pular();
        break;
    case sf::Keyboard::Escape:
        pGrafico->fechaJanela();
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D || tecla == sf::Keyboard::Left || tecla == sf::Keyboard::Right)
    {
        pJogador->parar();
    }
}

void GerenciadorEvento::executar()
{
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento))
    {
        switch (evento.type)
        {
        case sf::Event::Closed:
            pGrafico->fechaJanela();
            break;
        case sf::Event::KeyPressed:
            verificaTeclaPressionada(evento.key.code);
            break;
        case sf::Event::KeyReleased:
            verificaTeclaSolta(evento.key.code);
            break;
        }
    }
}