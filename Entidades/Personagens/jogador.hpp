#pragma once

#include "Personagem.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.8f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador : public Personagem
            {
            private:
                void inicializa();
                bool noChao;

            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Jogador();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
                void pular();
                void podePular();
                void animar();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;