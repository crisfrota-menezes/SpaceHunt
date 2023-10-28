#include "Personagem.hpp"
#include <cmath>


Personagem::Personagem(const sf::Vector2f pos, const float vel, const Identidade::IDs id) : Entidade(pos,id), podeMover(false), paraEsquerda(false), relogio(),
dt(0.0f), velocidade(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),animacao(this->getTexture(),3,1){
}

Personagem::~Personagem()
{
}

void Personagem::andar(const bool paraEsquerda)
{
    atacando = false;
    podeMover = true;
    this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
    podeMover = false;
}

void Personagem::atualizarPos(sf::Vector2f ds){

    setPos(sf::Vector2f(sprite.getPosition().x + ds.x, sprite.getPosition().y + ds.y));
}

sf::Vector2f Personagem::calculaVel(sf::Vector2f vel){

    // atualiza velocidade na horizontal
    velocidade.x = vel.x;

    dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    if(vel.y > velocidade.y ){
        vel.y = velocidade.y;
    }
    // move na horizontal
    if (podeMover){
        ds.x = vel.x * dt;
        if (paraEsquerda)
        {
            ds.x *= -1;
        }
    }
    // sofre o efeito da gravidade
    vel.y += GRAVIDADE * dt; // Aplicando Gravidade na Velocidade
    ds.y = vel.y * GRAVIDADE + vel.y; // Aplicando Gravidade na  movimentação.

    return ds;
}

void Personagem::setVelocidade(sf::Vector2f velFl){
    velocidade = velFl;
}

void Personagem::animar()
{
    if (podeMover)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}


void Personagem::pular()

const sf::Vector2f Personagem::getVelocidade(){
    return velocidade;
}

/*bool Personagem::getAtacando()
{
    if (podepular)
    {
        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
        podepular = false;
        pulou = true;
    }
}

void Personagem::podePular()
{
    if(noChao)
        podepular = true;
}

void Personagem::estaNoChao()
{
    noChao = true;
}