#include "principal.hpp"

#include "Menus/menu.hpp"

int main()
{
    /*Menu ainda não está integrado no gerenciador gráfico por isso essas operações, devido a que fiz o menu antes do resto*/
    bool control = false;
    Menu *menu = new Menu();
    control = menu->run();
    delete menu;
    menu = nullptr;
    if (control)
    {
        Jogo start;
    }
    return 0;
}