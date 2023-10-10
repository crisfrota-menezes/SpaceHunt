#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entidade.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador;
            class Venusiano;

            class Projetil : public Entidade
            {
            public:
                Projetil(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , Entidade* don = nullptr);
                void atualizar();
                void colisao(Entidade *outraEnt, sf::Vector2f ds);

            private:
                int dano;
                float velocidade;
                Entidade* dono;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;