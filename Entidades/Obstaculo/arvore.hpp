#pragma once

#include "obstaculo.hpp"

#define CAMINHO_TEXTURA_Arvore "C:/Users/crisn/Desktop/SpaceHunt/Midia/arvore.png"


namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Arvore : public Obstaculo
            {
            private:
                const float flexibilidade;

            public:
                Arvore(sf::Vector2f pos = sf::Vector2f(0.0,0.0));
                ~Arvore();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void colisaoObstaculo(sf::Vector2f ds, Personagem* pPersonagem);
                void executar();
            };

        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;