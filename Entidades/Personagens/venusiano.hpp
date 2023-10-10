#pragma once

#include "inimigo.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Venusiano : public Inimigo
            {
            private:
                void inicializa();

            public:
                Venusiano(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , Jogador *joga = nullptr);
                ~Venusiano();
                
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;