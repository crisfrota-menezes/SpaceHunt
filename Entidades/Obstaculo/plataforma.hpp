#pragma once

#include "obstaculo.hpp"
#include "../Personagens/Personagem.hpp"

#define CAMINHO_PLATAFORMA "C:/Users/crisn/Desktop/SpaceHunt/Midia/plataforma.png"


namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
            public:
                Plataforma(sf::Vector2f pos = sf::Vector2f(0.0,0.0));
                ~Plataforma();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void executar();
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;