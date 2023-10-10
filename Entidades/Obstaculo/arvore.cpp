#include "arvore.hpp"

Arvore::Arvore(sf::Vector2f pos): Obstaculo(pos, Identidade::IDs::Arvore), flexibilidade(0.25f){
}

Arvore::~Arvore()
{
}

void Arvore::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2i tamOutro = outraEntidade->getSprite()->getTextureRect().getSize();

    if (outraEntidade->getID() == Identidade::IDs::jogador || outraEntidade->getID() == Identidade::IDs::Uraniano || outraEntidade->getID() == Identidade::IDs::Venusiano || outraEntidade->getID() == Identidade::IDs::Verme)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEntidade));
    }
}

void Arvore::colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2i tamOutro = pPersonagem->getSprite()->getTextureRect().getSize();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f)
    { // houve colisao
        if (ds.x > ds.y)
        {
            if (pPersonagem->getID() == Identidade::IDs::jogador)
            {
                velFinal.x *= flexibilidade;
                if (posOutro.x < sprite.getPosition().x)
                { // colisão em x
                    //sprite.getPosition().x -= ds.x;
                }
                else
                {
                    //pos.x += ds.x;
                }
              //  setPos(pos);
            }
            else
            {
                if (posOutro.x < sprite.getPosition().x)
                { // colisão em x
                    posOutro.x += ds.x;
                }
                else
                {
                    posOutro.x -= ds.x;
                }
            }
        }
        else
        {
            if (posOutro.y < sprite.getPosition().y)
            { // colisão em y
                posOutro.y += ds.y;
                if (pPersonagem->getID() == Identidade::IDs::jogador)
                {
                    Jogador *pJogador = static_cast<Jogador *>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else
            {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}

void Arvore::executar(){
    
}