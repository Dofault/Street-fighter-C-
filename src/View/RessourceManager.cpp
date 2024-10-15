#include "RessourceManager.h"

// Important de déclarer la map ici pour pouvoir l'utiliser de manière statique
map<string, sf::Font *> RessourceManager::mapFonts;
map<string, sf::Texture *> RessourceManager::mapTextures;

RessourceManager::~RessourceManager() {

    // Création d'un iterateur pour parcourir la map
    map<string, sf::Font *>::iterator itTexture;
    // On libère la mémoire alouée pour chaque élément de la map
    for (itTexture = mapFonts.begin(); itTexture != mapFonts.end(); itTexture++) {
        delete itTexture->second;
    }

}

void RessourceManager::loadFont(const string key, const string filename) {
    // Chargement de la texture grâce a une fichier
    sf::Font *font = new sf::Font();
    if (font->loadFromFile(filename)) {
        // Ajout de l'objet texture créé à la map
        mapFonts[key] = new sf::Font(*font);
    }

    delete font;
}

void RessourceManager::loadAllRessources() {

    /* ---------------------- PALERMO TEXTURES ---------------------- */
    loadTexture("PalermoIdle", "./assets/PalermoIdle.png"); //PalermoIdle
    loadTexture("PalermoPunch", "./assets/PalermoPunch.png"); // PalermoPunch
    loadTexture("PalermoHit", "./assets/PalermoHit.png");
    loadTexture("PalermoHitCollapse", "./assets/PalermoHitCollapse.png");
    loadTexture("PalermoWalk", "./assets/PalermoWalk.png");

    /* ---------------------- CRESPIN TEXTURES ---------------------- */
    loadTexture("CrespinIdle", "./assets/CrespinIdle.png");
    loadTexture("CrespinPunch", "./assets/CrespinPunch.png");
    loadTexture("CrespinHit", "./assets/CrespinHit.png");
    loadTexture("CrespinHitCollapse", "./assets/CrespinHitCollapse.png");
    loadTexture("CrespinWalk", "./assets/CrespinWalk.png");


    loadTexture("AltaresIdle", "./assets/AltaresIdle.png");
    loadTexture("AltaresPunch", "./assets/AltaresPunch.png");
    loadTexture("AltaresHit", "./assets/AltaresHit.png");
    loadTexture("AltaresHitCollapse", "./assets/AltaresHitCollapse.png");
    loadTexture("AltaresWalk", "./assets/AltaresWalk.png");

    loadTexture("ColmantIdle", "./assets/ColmantIdle.png");
    loadTexture("ColmantPunch", "./assets/ColmantPunch.png");
    loadTexture("ColmantHit", "./assets/ColmantHit.png");
    loadTexture("ColmantHitCollapse", "./assets/ColmantHitCollapse.png");
    loadTexture("ColmantWalk", "./assets/ColmantWalk.png");

    loadTexture("GodefroidIdle", "./assets/GodefroidIdle.png");
    loadTexture("GodefroidPunch", "./assets/GodefroidPunch.png");
    loadTexture("GodefroidHit", "./assets/GodefroidHit.png");
    loadTexture("GodefroidHitCollapse", "./assets/GodefroidHitCollapse.png");
    loadTexture("GodefroidWalk", "./assets/GodefroidWalk.png");

    loadFont("MainFont", "./Act_Of_Rejection.ttf");
    loadTexture("Arena", "./arena3.jpg");

    loadTexture("VersusLogo", "./versus_logo.png");
    loadTexture("MainMenuBackground", "./MainMenuBackground.png");
    loadTexture("AboutBackground", "./AboutBackground.png");

}

sf::Font *RessourceManager::getFont(const string key) {
    return mapFonts[key];
}



void RessourceManager::loadTexture(const string &key, const string &filename) {
    // Chargement de la texture grâce a une fichier
    sf::Texture *txt = new sf::Texture();

    if (txt->loadFromFile(filename)) {
        mapTextures[key] = new sf::Texture(*txt);
    }

    delete txt;
}

sf::Texture * RessourceManager::getTexture(string key) {
    return mapTextures[key];
}



