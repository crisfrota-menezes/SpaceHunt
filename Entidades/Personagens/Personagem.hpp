#pragma once

#include "../entidade.hpp"
#include "../../Animacao/animacao.hpp"

#define GRAVIDADE 1.0f
#define TAMANHO_PULO 0.8f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
            protected:
                sf::Vector2f velocidade;
                const float velMax;
                bool podeMover;
                bool paraEsquerda;
                bool atacando;
                sf::Clock relogio;
                float dt;
                Animacao animacao;
                bool noChao;
                bool podepular;
                bool pulou;

            public:
                Personagem(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , const float vel = 2.0 , const Identidade::IDs ID = Identidade::IDs::vazio);
                ~Personagem();
                
                void parar();

                void pular();
                void podePular();         

                void atualizarPos(sf::Vector2f dis);

                void andar(const bool paraEsquerda);
                sf::Vector2f calculaVel(sf::Vector2f vel);
                void setVelocidade(sf::Vector2f velFinal);
                const sf::Vector2f getVelocidade();
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