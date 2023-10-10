#pragma once

#include "inimigo.hpp"

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
                Uraniano(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , Jogador *joga = nullptr);
                ~Uraniano();
                void executar();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;