#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#define LARGURA_TELA 1920.0f
#define ALTURA_TELA 1080.0f

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorGrafico
        {
        private:
            sf::RenderWindow *window;
            sf::View camera;
            static GerenciadorGrafico *pGrafico;
            /*singleton*/
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico *getGerenciadorGrafico(); // n]ao sei se aqui precisa ser estático visto que é um singleton
            sf::RenderWindow *getWindow();
            void limpar();
            void desenhaElemento(sf::RectangleShape corpo);
            void mostraElementos();
            void fechaJanela();
            sf::Texture carregarTextura(const char *caminho );
            const bool janelaAberta();
            void atualizarCamera(const sf::Vector2f posJogador);
            const sf::View getCamera();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;