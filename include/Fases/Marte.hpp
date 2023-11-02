#pragma once

#include "fase.hpp"
#include "../Entidades/jogador.hpp"
#include "../Entidades/Personagem.hpp"

namespace SpaceHunt
{
    namespace Fases
    {
        class Marte : public Fase
        {
        public:
            Marte();
            ~Marte();
            void criarMapa();
            void criarFundo();

            void executar();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;