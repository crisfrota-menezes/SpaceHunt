#include "obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f pos, const Identidade::IDs ID):
    Entidade(pos, ID){
}

Obstaculo::~Obstaculo(){

}

void Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagem* pPersonagem){
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2i tamOutro = pPersonagem->getSprite()->getTextureRect().getSize();
    sf::Vector2f velFinal = pPersonagem->getVelocidade();
    if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
        if(ds.x > ds.y){
            if(posOutro.x < sprite.getPosition().x){ //colisão em x
                posOutro.x += ds.x;
            } else {
                posOutro.x -= ds.x;
            }
            velFinal.x = 0.0f;
        } else {
            if(posOutro.y < sprite.getPosition().y){ //colisão em y
                posOutro.y += ds.y;
                if(pPersonagem->getID() == Identidade::IDs::jogador){
                    Jogador* pJogador = static_cast<Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            } else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelocidade(velFinal);
}