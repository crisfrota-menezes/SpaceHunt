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
        virtual ~Ente();
        const Identidade::IDs getID() const;
        virtual void desenhar();
        virtual void executar() = 0;
        void setGGrafico(GerenciadorGrafico* pGrafico);
        const sf::Texture* getTexture() const;
        void SetSprite();
        sf::Sprite* getSprite();
        virtual void inicializar();
    };
}
using namespace SpaceHunt;