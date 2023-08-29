#pragma once

#include "fase.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/Personagem.hpp"

namespace SpaceHunt
{
    namespace Fases
    {
        class Venus : public Fase
        {
        public:
            Venus();
            ~Venus();
            void criarMapa();
            void criarFundo();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;