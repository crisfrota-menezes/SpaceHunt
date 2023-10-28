#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IDs.hpp"
using namespace std;

#define LARGURA_TELA 1280.0f
#define ALTURA_TELA 720.0f

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorGrafico
        {
        private:
            sf::RenderWindow *window;
            sf::View camera;
            sf::Image Jogador, Uraniano, Venusiano, Verme, Projetil, Arvore, Plataforma, Rocha;
            static GerenciadorGrafico *pGrafico;
            /*singleton*/
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();
            GerenciadorGrafico *getGerenciadorGrafico(); // nao sei se aqui precisa ser estático visto que é um singleton
            sf::RenderWindow *getWindow();
            void limpar();
            void desenhaElemento(sf::Sprite corpo);
            void mostraElementos();
            void fechaJanela();
            const bool janelaAberta();
            void atualizarCamera(const sf::Vector2f posJogador);
            const sf::View getCamera();
            const sf::Image CarregaTextura(Identidade::IDs iden);
            void CarregarImagens();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;

