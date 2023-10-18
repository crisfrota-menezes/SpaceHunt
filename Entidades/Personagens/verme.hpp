#pragma once

#include "inimigo.hpp"

#define TAMANHO_Verme_X 50.0f
#define TAMANHO_Verme_Y 90.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Verme : public Inimigo
            {
            private:
                void inicializa();

            public:
                Verme(const sf::Vector2f pos, Jogador *jogador);
                ~Verme();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;