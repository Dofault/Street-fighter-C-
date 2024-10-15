#ifndef OPTION_H
#define OPTION_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Option.h"

#define Max_option_menu 4
using namespace std;
using namespace sf;

class Option
{
    public:
        Option();
        Option(float width, float height);
        virtual ~Option();

        void draw(RenderWindow& window);
        void MoveUp();
        void MoveDown();

        Text option[Max_option_menu];
        int const OptionPressed() {
            return OptionSelected;
        }
    protected:

    private:

        int OptionSelected;
        Font font;
};

#endif // OPTION_H
