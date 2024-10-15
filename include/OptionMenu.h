#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "MenuManager.h"

using namespace std;
using namespace sf;

const int OPTIONS_NUMBER = 4;

class OptionMenu : public Menu
{
    public:
        OptionMenu(RenderWindow * window);
        virtual ~OptionMenu();

        void moveUp();
        void moveDown();

        void draw() override;
        void updateValues() override;
        void handleEvent(sf::Event event) override;
        Menu * clone() override;

    private:
        int selectedOption;
        Text options[OPTIONS_NUMBER];
};


#endif // OPTIONMENU_H
