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

    public:
        Ente(const Identidade::IDs id);
        ~Ente();
        const Identidade::IDs getID() const;
        virtual void desenhar() = 0;
        virtual void atulizar() = 0;
        void setGGrafico(GerenciadorGrafico* pGrafico);
    };
}
using namespace SpaceHunt;