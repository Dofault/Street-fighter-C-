#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "iostream"
#include "SFML/Graphics.hpp"

using namespace std;

class ResourceManager {

private:
    /*
     * assetsPath: Contient le chemin vers notre dossiers assets
     * mapTextures: contient toutes nos textures chargées
     */
    static map<string, sf::Texture*> mapTextures;

public:

    ResourceManager();
    ~ResourceManager();

    static void loadAllRessources();
    static void loadTexture(string key, string filename);

    static sf::Texture * getTexture(string key);
};

#endif // RESOURCEMANAGER_H
