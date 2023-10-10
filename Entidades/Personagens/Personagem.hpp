#pragma once

#include "../entidade.hpp"
#include "../../Animacao/animacao.hpp"

#define GRAVIDADE 1.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
            protected:
                sf::Vector2f velFinal;
                const float velMax;
                bool podeMover;
                bool paraEsquerda;
                bool atacando;
                sf::Clock relogio;
                float dt;
                Animacao animacao;

            public:
                Personagem(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , const float vel = 2.0 , const Identidade::IDs ID = Identidade::IDs::vazio);
                ~Personagem();
                void setVelFinal(sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal() const;
                void andar(const bool paraEsquerda);
                void parar();
                void atualizarPos();
                virtual void animar();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void executar() = 0;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;