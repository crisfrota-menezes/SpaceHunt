#include "menu.hpp"

Menu::Menu() : Ente(Identidade::IDs::Menu)
{
}

Menu::~Menu()
{
}

void Menu::handleMenuSelection(MenuOption option)
{
    switch (option)
    {
    case MenuOption::SELECT_PHASE:
        std::cout << "Select Phase" << std::endl;
        break;
    case MenuOption::RANKING:
        std::cout << "Ranking" << std::endl;
        break;
    case MenuOption::OPTIONS:
        std::cout << "Options" << std::endl;
        break;
    default:
        break;
    }
}

void Menu::executar()
{
    desenhar();
    pGrafico->desenhaTexto(title);
    pGrafico->mostraTextos();
}

void Menu::inicializar()
{
    SetBackground();
    sprite.setPosition(0.0f, 0.0f);
    title.setString("Space Hunt");
    pGrafico->setFonte(title, font);    
}