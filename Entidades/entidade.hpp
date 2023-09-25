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
        public:
            int vida;
            Entidade(const sf::Vector2f pos, const Identidade::IDs id);
            Entidade();
            ~Entidade();
            void setPos(sf::Vector2f pos);
            sf::Vector2f getPos();
            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            int getDano();
        };
    }
    using namespace Entidades;
}
using namespace SpaceHunt;