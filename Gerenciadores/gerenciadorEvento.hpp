#pragma once

#include "GerenciadorGrafico.hpp"
#include "../Entidades/Personagens/jogador.hpp"

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorEvento
        {
        private:
            GerenciadorGrafico *pGrafico;
            Jogador *pJogador; //adicionar mais um jogador
            // singleton
            static GerenciadorEvento *pEvento;
            GerenciadorEvento();

        public:
            ~GerenciadorEvento();
            static GerenciadorEvento *getGerenciadorEvento();
            void setJogador(Jogador *pJogador);
            Jogador* getJogador(); //Acho que não precisa de um getJogador
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;