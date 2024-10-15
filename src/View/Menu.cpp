#include "Menu.h"

Menu::Menu(sf::RenderWindow *window):window(window){}

Menu::~Menu() {}

Menu::Menu(const Menu & menu):window(menu.window) {}

Menu &Menu::operator=(const Menu &menu) {

    if (this != &menu){
        window = menu.window;
    }

    return *this;
}

