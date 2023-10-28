#pragma once

#include "obstaculo.hpp"

#define CAMINHO_Rochas "C:/Users/crisn/Desktop/SpaceHunt/Midia/Rochas.png"



namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Rochas : public Obstaculo
            {
            public:
                Rochas(sf::Vector2f pos = sf::Vector2f(0.0,0.0));
                ~Rochas();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void executar();
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;