#pragma once

#include "./ente.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        class Entidade : public Ente
        {
        protected:
            int dano;
            int vida;
        public:
            Entidade(const sf::Vector2f pos = sf::Vector2f(0.0,0.0) , const Identidade::IDs id = Identidade::IDs::vazio);
            ~Entidade();

            int getDano();
            sf::Vector2f getPos();
            void setPos(sf::Vector2f pos);

            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void executar() = 0;
            
        };
    }
    using namespace Entidades;
}
using namespace SpaceHunt;