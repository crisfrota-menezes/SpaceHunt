#pragma once

#include "inimigo.hpp"

#define TAMANHO_Uraniano_X 50.0f
#define TAMANHO_Uraniano_Y 90.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Uraniano : public Inimigo
            {
            private:
                void inicializa();

            public:
                Uraniano(const sf::Vector2f pos, Jogador *jogador);
                ~Uraniano();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;