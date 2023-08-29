#pragma once

#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"

#include "Fases/Marte.hpp"
#include "Fases/Venus.hpp"

namespace SpaceHunt
{
    class Jogo
    {
    private:
        GerenciadorGrafico *pGrafico;
        GerenciadorEvento *pEvento;
        Fase *fase;
        void criarFase();

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;