#pragma once
#include <string>
#include <map>
#include "SFML/Graphics.hpp"

namespace SpaceHunt {
    namespace Animador {
        class Animacao {
        private:
            std::map<std::string, sf::IntRect*> mapImagem;
            sf::Clock relogio;
            std::string imgAtual;
           const int tam_x,tam_y;

        public:
            Animacao(const sf::Texture* textura = nullptr, int num_col = 1, int num_lin = 1);
            ~Animacao();            
            void atualizar(const bool paraEsquerda, std::string imgAtual);
            void addAnimacao(std::string nomeAnimacao, sf::Vector2f locali);
            
        };
    }
    using namespace Animador;
}
using namespace SpaceHunt;