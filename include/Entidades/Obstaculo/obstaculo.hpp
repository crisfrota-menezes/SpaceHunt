#pragma once

#include "../entidade.hpp"
#include "../Personagens/jogador.hpp"
#include "../Personagens/inimigo.hpp"

#include "../../Animacao/animacao.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo : public Entidade
            {
            protected:

            public:
                Obstaculo(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , const Identidade::IDs ID = Identidade::IDs::vazio);
                ~Obstaculo();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void executar() = 0;
                virtual void colisaoObstaculo(sf::Vector2f ds, Personagem* pPersonagem);
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;