#pragma once

#include <C:\Users\crisn\Downloads\jogo_cristiano_frota_S73\SpaceHunt\SFML\include\SFML\Graphics.hpp>
#include <iostream>

#include "IDs.hpp"
#include "Gerenciadores/gerenciadorGrafico.hpp"

namespace SpaceHunt
{
    class Ente
    {
    protected:
        GerenciadorGrafico *pGrafico;
        const IDs::IDs ID;

    public:
        Ente(const IDs::IDs ID);
        ~Ente();
        const IDs::IDs getID() const;
        virtual void desenhar() = 0;
        virtual void atualizar() = 0;
    };
}
using namespace SpaceHunt;