#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "RessourceManager.h"

class Menu {

protected:
/* ---------------- ATTRIBUTS -----------------
 * window: Fenêtre de l'application principale, c'est dans cette fenetre qu'on affichera nos menus
 */
sf::RenderWindow * window;

public:
    /* FORME CANONIQUE */
    Menu(sf::RenderWindow * window);
    virtual ~Menu();
    Menu(const Menu & menu);
    Menu & operator=(const Menu & menu);

    // Ces méthodes seront à redéfinir dans les sous-classe
    virtual void draw() = 0; // Permettra de dessiner notre menu dans la fenetre
    virtual void handleEvent(sf::Event event) = 0; // Permettra de gérer les évenements liés au menu choisi
    virtual void updateValues() = 0; // Permettra de mettre a jour certaines informations a chaque tour de boucle
    virtual Menu * clone() = 0; // Permet de cloner le menu

};

#endif // MENU_H
