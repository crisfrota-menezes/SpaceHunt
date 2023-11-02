#include "../include/Animacao/animacao.hpp"

Animacao::Animacao(const sf::Texture* textur,int col, int lin):mapImagem(), imgAtual(""), relogio(),
tam_x(textur->getSize().x /col), tam_y(textur->getSize().y / lin){
    mapImagem.clear(); 
}

Animacao::~Animacao()
{
    std::map<std::string, sf::IntRect*>::iterator it = mapImagem.begin();
    while (it != mapImagem.end())
    {
        if (it->second)
        {
            delete (it->second);
        }
        it++;
    }
    mapImagem.clear();
}

void Animacao::atualizar(const bool paraEsquerda, std::string imgAt)
{ /*
    if (imgAtual != imgAt)
    {
        if (imgAtual != "")
        {
            mapImagem[imgAtual]->resetar();
        }
        imgAtual = imgAt;
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();

    Imagem *img = mapImagem[imgAtual];
    sf::Vector2f escala = img->getEscala();

    img->atualizar(paraEsquerda, dt);
   */
}

void Animacao::addAnimacao(std::string nomeAnimacao, sf::Vector2f posi){
    sf::IntRect* rect = new sf::IntRect(posi.x,posi.y,tam_x,tam_y);
    mapImagem.insert(std::pair<std::string, sf::IntRect*>(nomeAnimacao, rect));
}