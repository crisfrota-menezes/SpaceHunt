#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

#include "IDs.hpp"
#include "Gerenciadores/gerenciadorGrafico.hpp"

namespace SpaceHunt
{
    class Ente
    {
    protected:
       static GerenciadorGrafico* pGrafico;
        const Identidade::IDs identificador;
        sf::Sprite sprite;
        sf::Texture textura;

    public:
        Ente(const Identidade::IDs id = Identidade::IDs::vazio);
        Ente();
        virtual ~Ente();
        const Identidade::IDs getID() const;
        virtual void desenhar();
        virtual void atulizar() = 0;
        void setGGrafico(GerenciadorGrafico* pGrafico);
        const sf::Texture* getTexture() const;
        sf::Sprite* getSprite();
    };
}
using namespace SpaceHunt;