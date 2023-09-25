#pragma once

#include <../SFML/include/SFML/Graphics.hpp>
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
        sf::Sprite Imagem;

    public:
        Ente(const Identidade::IDs id);
        Ente();
        virtual ~Ente();
        const Identidade::IDs getID() const;
        virtual void desenhar();
        virtual void atulizar() = 0;
        void setGGrafico(GerenciadorGrafico* pGrafico);
    };
}
using namespace SpaceHunt;