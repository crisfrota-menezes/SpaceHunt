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
                bool noChao;
                bool n_jogador;
                static bool Jogador2;
            public:
                Jogador(const sf::Vector2f pos = sf::Vector2f(300.0,300.0));
                ~Jogador();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void executar();
                void inicializar();
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