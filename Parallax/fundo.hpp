#pragma once

#include "../ente.hpp"
#include "../IDs.hpp"

#include "camada.hpp"

namespace SpaceHunt
{
    namespace Parallax
    {
        class Fundo : public Ente
        {
        private:
            sf::Vector2f posAnteriorCamera;
            std::vector<Camada *> camadas;

        public:
            Fundo(const Identidade::IDs ID);
            ~Fundo();
            void desenhar();
            void addCamada(const char *caminhoTextura, const float vel);
            void atualizar();
        };
    }
    using namespace Parallax;
}
using namespace SpaceHunt;