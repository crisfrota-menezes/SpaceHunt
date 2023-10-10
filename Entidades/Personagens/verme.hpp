#pragma once

#include "inimigo.hpp"

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
                Verme(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , Jogador *joga = nullptr);
                ~Verme();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;