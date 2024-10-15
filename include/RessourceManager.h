#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "Animation.h"

using namespace std;


// use to load assets
class RessourceManager {

private:
    /*
     * assetsPath: Contient le chemin vers notre dossiers assets
     * mapTextures: contient toutes nos textures chargées
     */
    static map<string, sf::Font*> mapFonts;
    static map<string, sf::Texture*> mapTextures;

public:

    ~RessourceManager();

    static void loadAllRessources();
    static void loadFont(string key, string filename);
    static void loadTexture(const string & key, const string & filename);

    static sf::Font * getFont(string key);
    static sf::Texture * getTexture(string key);
};
#endif // RESOURCEMANAGER_H
