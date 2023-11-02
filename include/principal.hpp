#pragma once

#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"

#include "Fases/Marte.hpp"
#include "Fases/Venus.hpp"
#include "Menus/menu.hpp"

namespace SpaceHunt
{
    class Jogo
    {
    private:
        GerenciadorGrafico *pGrafico;
        GerenciadorEvento *pEvento;
        Marte Fase_Marte;
        Jogador Teste;
        Menu testando;

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;