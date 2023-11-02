#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../ente.hpp"

namespace SpaceHunt
{
    enum class MenuOption
    {
        SELECT_PHASE,
        RANKING,
        OPTIONS
    };

    class Menu : public Ente
    {
    private:
        sf::Text title;
        sf::Text selectPhase;
        sf::Text ranking;
        sf::Text options;
        sf::Font font;

    public:
        Menu();
        ~Menu();
        void handleMenuSelection(MenuOption option);
        //void desenhar();
        void executar();
        void inicializar();
    };
}
using namespace SpaceHunt;