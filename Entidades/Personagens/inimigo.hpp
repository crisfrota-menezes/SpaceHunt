#pragma once

#include <cmath>
#include <time.h>
#include "jogador.hpp"
#include "Personagem.hpp"

#define VELOCIDADE_INIMIGO 60.0f

#define VISAO_INIMIGO_X 200.0f
#define VISAO_INIMIGO_Y 200.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Inimigo : public Personagem
            {
            protected:
                Jogador *jogador;
                float dtAux;
                int moveAleatorio;

            public:
                Inimigo(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , Jogador *jogador = nullptr , Identidade::IDs id = Identidade::IDs::vazio);
                ~Inimigo();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds) = 0;
                virtual void executar() = 0;
                void atualizar();
                void atualizaMoveAleatorio();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;