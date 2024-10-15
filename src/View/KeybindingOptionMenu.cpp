#include "KeybindingOptionMenu.h"
#include <fstream>
#include <iostream>
#include <sstream>

KeybindingOptionMenu::KeybindingOptionMenu(sf::RenderWindow *window) : Menu(window) {
    currentKeybindingIndex = 0;
    selectedOption = 0;
    maxKeybindingIndex = 8;

    loadDefaultKeybindings();  //load key bind in config.txt

    titleText.setFont(*RessourceManager::getFont("MainFont"));
    titleText.setCharacterSize(60);
    titleText.setString("Keybindings");
    titleText.setPosition(window->getSize().x / 2, 50);
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);

    //Personnage 1
    titleText1.setFont(*RessourceManager::getFont("MainFont"));
    titleText1.setCharacterSize(30);
    titleText1.setString("Personnage 1");
    titleText1.setPosition(window->getSize().x / 4, 200);
    titleText1.setOrigin(titleText1.getLocalBounds().width / 2, titleText1.getLocalBounds().height / 2);

    keybindingOption1Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption1Text.setString("Gauche: " + keyToString(keybindings["Gauche1"]));
    keybindingOption1Text.setFillColor(sf::Color::Blue);
    keybindingOption1Text.setCharacterSize(24);
    keybindingOption1Text.setPosition(window->getSize().x / 4, 300);
    keybindingOption1Text.setOrigin(keybindingOption1Text.getLocalBounds().width / 2,
                                    keybindingOption1Text.getLocalBounds().height / 2);

    keybindingOption2Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption2Text.setString("Droite: " + keyToString(keybindings["Droite1"]));
    keybindingOption2Text.setCharacterSize(24);
    keybindingOption2Text.setPosition(window->getSize().x / 4, 400);
    keybindingOption2Text.setOrigin(keybindingOption2Text.getLocalBounds().width / 2,
                                    keybindingOption2Text.getLocalBounds().height / 2);

    keybindingOption3Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption3Text.setString("Attaquer: " + keyToString(keybindings["Attaquer1"]));
    keybindingOption3Text.setCharacterSize(24);
    keybindingOption3Text.setPosition(window->getSize().x / 4, 500);
    keybindingOption3Text.setOrigin(keybindingOption3Text.getLocalBounds().width / 2,
                                    keybindingOption3Text.getLocalBounds().height / 2);

    keybindingOption4Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption4Text.setString("Defendre: " + keyToString(keybindings["Defendre1"]));
    keybindingOption4Text.setCharacterSize(24);
    keybindingOption4Text.setPosition(window->getSize().x / 4, 600);
    keybindingOption4Text.setOrigin(keybindingOption4Text.getLocalBounds().width / 2,
                                    keybindingOption4Text.getLocalBounds().height / 2);

    //Personnage 2
    titleText2.setFont(*RessourceManager::getFont("MainFont"));
    titleText2.setCharacterSize(30);
    titleText2.setString("Personnage 2");
    titleText2.setPosition(window->getSize().x * 0.75, 200);
    titleText2.setOrigin(titleText2.getLocalBounds().width / 2, titleText2.getLocalBounds().height / 2);

    keybindingOption5Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption5Text.setString("Gauche: " + keyToString(keybindings["Gauche2"]));
    keybindingOption5Text.setCharacterSize(24);
    keybindingOption5Text.setPosition(window->getSize().x * 0.75, 300);
    keybindingOption5Text.setOrigin(keybindingOption5Text.getLocalBounds().width / 2,
                                    keybindingOption5Text.getLocalBounds().height / 2);

    keybindingOption6Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption6Text.setString("Droite: " + keyToString(keybindings["Droite2"]));
    keybindingOption6Text.setCharacterSize(24);
    keybindingOption6Text.setPosition(window->getSize().x * 0.75, 400);
    keybindingOption6Text.setOrigin(keybindingOption6Text.getLocalBounds().width / 2,
                                    keybindingOption6Text.getLocalBounds().height / 2);

    keybindingOption7Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption7Text.setString("Attaquer: " + keyToString(keybindings["Attaquer2"]));
    keybindingOption7Text.setCharacterSize(24);
    keybindingOption7Text.setPosition(window->getSize().x * 0.75, 500);
    keybindingOption7Text.setOrigin(keybindingOption7Text.getLocalBounds().width / 2,
                                    keybindingOption7Text.getLocalBounds().height / 2);

    keybindingOption8Text.setFont(*RessourceManager::getFont("MainFont"));
    keybindingOption8Text.setString("Defendre: " + keyToString(keybindings["Defendre2"]));
    keybindingOption8Text.setCharacterSize(24);
    keybindingOption8Text.setPosition(window->getSize().x * 0.75, 600);
    keybindingOption8Text.setOrigin(keybindingOption8Text.getLocalBounds().width / 2,
                                    keybindingOption8Text.getLocalBounds().height / 2);

    selectedOption = 0;
}

void KeybindingOptionMenu::draw() {

    window->draw(titleText);
    window->draw(titleText1);
    window->draw(titleText2);

    //perso 1
    window->draw(keybindingOption1Text);
    window->draw(keybindingOption2Text);
    window->draw(keybindingOption3Text);
    window->draw(keybindingOption4Text);

    //perso 2
    window->draw(keybindingOption5Text);
    window->draw(keybindingOption6Text);
    window->draw(keybindingOption7Text);
    window->draw(keybindingOption8Text);
}

void KeybindingOptionMenu::MoveUp() {
    handleMovement(-1);
}

void KeybindingOptionMenu::MoveDown() {
    handleMovement(1);
}

void KeybindingOptionMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            MoveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            MoveDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            changeKey();
        } else if (event.key.code == sf::Keyboard::Escape) {
            applyOptions();
            MenuManager::setSelectedMenu("OptionMenu");
        }
    }
}

void KeybindingOptionMenu::applyOptions() {
    // Sauvegardez les options (touches configurées) dans le fichier config.txt
    std::ofstream configFile("config.txt");
    if (configFile.is_open()) {
        // Parcourez le tableau keybindings et écrivez chaque touche dans le fichier
        for (const auto &pair: keybindings) {
            configFile << pair.first << " " << keyToString(pair.second) << std::endl;
        }
        configFile.close();
    } else {
        // Gérez l'erreur d'ouverture du fichier (par exemple, affichez un avertissement)
        std::cerr << "Impossible d'ouvrir le fichier config.txt pour sauvegarder les touches." << std::endl;
    }
}

void KeybindingOptionMenu::handleMovement(int direction) {
    // Mettez en blanc la sélection actuelle
    switch (selectedOption) {
        case 0:
            keybindingOption1Text.setFillColor(sf::Color::White);
            break;
        case 1:
            keybindingOption2Text.setFillColor(sf::Color::White);
            break;
        case 2:
            keybindingOption3Text.setFillColor(sf::Color::White);
            break;
        case 3:
            keybindingOption4Text.setFillColor(sf::Color::White);
            break;
            //perso 2
        case 4:
            keybindingOption5Text.setFillColor(sf::Color::White);
            break;
        case 5:
            keybindingOption6Text.setFillColor(sf::Color::White);
            break;
        case 6:
            keybindingOption7Text.setFillColor(sf::Color::White);
            break;
        case 7:
            keybindingOption8Text.setFillColor(sf::Color::White);
            break;
        default:
            break;
    }

    // Déplacement de la sélection et vérification pour ne pas dépasser la plage
    selectedOption += direction;
    if (selectedOption < 0) {
        selectedOption = maxKeybindingIndex - 1;
    } else if (selectedOption >= maxKeybindingIndex) {
        selectedOption = 0;
    }

    // Définissez la nouvelle sélection en bleu
    switch (selectedOption) {
        case 0:
            keybindingOption1Text.setFillColor(sf::Color::Blue);
            break;
        case 1:
            keybindingOption2Text.setFillColor(sf::Color::Blue);
            break;
        case 2:
            keybindingOption3Text.setFillColor(sf::Color::Blue);
            break;
        case 3:
            keybindingOption4Text.setFillColor(sf::Color::Blue);
            break;
            //perso 2
        case 4:
            keybindingOption5Text.setFillColor(sf::Color::Blue);
            break;
        case 5:
            keybindingOption6Text.setFillColor(sf::Color::Blue);
            break;
        case 6:
            keybindingOption7Text.setFillColor(sf::Color::Blue);
            break;
        case 7:
            keybindingOption8Text.setFillColor(sf::Color::Blue);
            break;
        default:
            break;
    }
}

void KeybindingOptionMenu::changeKey() {
    std::string action;
    switch (selectedOption) {
        case 0:
            action = "Gauche1";
            break;
        case 1:
            action = "Droite1";
            break;
        case 2:
            action = "Attaquer1";
            break;
        case 3:
            action = "Defendre1";
            break;
            //perso2
        case 4:
            action = "Gauche2";
            break;
        case 5:
            action = "Droite2";
            break;
        case 6:
            action = "Attaquer2";
            break;
        case 7:
            action = "Defendre2";
            break;
        default:
            break;
    }


    sf::Event event;
    window->waitEvent(event);

    // Changer la touche pour l'action spécifiée
    while (event.type != sf::Event::KeyPressed) {
        window->waitEvent(event);
    }

    keybindings[action] = event.key.code;

    keybindingOption1Text.setString("Gauche: " + keyToString(keybindings["Gauche1"]));
    keybindingOption2Text.setString("Droite: " + keyToString(keybindings["Droite1"]));
    keybindingOption3Text.setString("Attaquer: " + keyToString(keybindings["Attaquer1"]));
    keybindingOption4Text.setString("Defendre: " + keyToString(keybindings["Defendre1"]));
    keybindingOption5Text.setString("Gauche: " + keyToString(keybindings["Gauche2"]));
    keybindingOption6Text.setString("Droite: " + keyToString(keybindings["Droite2"]));
    keybindingOption7Text.setString("Attaquer: " + keyToString(keybindings["Attaquer2"]));
    keybindingOption8Text.setString("Defendre: " + keyToString(keybindings["Defendre2"]));
}

void KeybindingOptionMenu::loadDefaultKeybindings() {
    // Chargez les valeurs par défaut depuis le fichier config.txt
    std::ifstream configFile("config.txt");
    if (configFile.is_open()) {
        std::string line;
        while (std::getline(configFile, line)) {
            // Utilisez un flux pour séparer la ligne en deux parties (clé et valeur)
            std::istringstream iss(line);
            std::string key, value;
            if (iss >> key >> value) {
                // Essayez de convertir la valeur en code de touche
                try {
                    sf::Keyboard::Key keyCode = stringToKey(value);
                    // Stockez le code de touche associé à la clé dans le tableau
                    keybindings[key] = keyCode;
                } catch (const std::invalid_argument &e) {
                    // Gérez l'erreur de conversion ici (par exemple, affichez un avertissement)
                    std::cerr << "Erreur de conversion pour la clé '" << key << "': " << e.what() << std::endl;
                }
            }
        }
        configFile.close();
    } else {
        // Gérez l'erreur d'ouverture du fichier (par exemple, affichez un avertissement)
        std::cerr << "Impossible d'ouvrir le fichier config.txt" << std::endl;
    }
}

sf::Keyboard::Key KeybindingOptionMenu::stringToKey(const std::string &str) {
    if (str == "A") return sf::Keyboard::A;
    else if (str == "B") return sf::Keyboard::B;
    else if (str == "C") return sf::Keyboard::C;
    else if (str == "D") return sf::Keyboard::D;
    else if (str == "E") return sf::Keyboard::E;
    else if (str == "F") return sf::Keyboard::F;
    else if (str == "G") return sf::Keyboard::G;
    else if (str == "H") return sf::Keyboard::H;
    else if (str == "I") return sf::Keyboard::I;
    else if (str == "J") return sf::Keyboard::J;
    else if (str == "K") return sf::Keyboard::K;
    else if (str == "L") return sf::Keyboard::L;
    else if (str == "M") return sf::Keyboard::M;
    else if (str == "N") return sf::Keyboard::N;
    else if (str == "O") return sf::Keyboard::O;
    else if (str == "P") return sf::Keyboard::P;
    else if (str == "Q") return sf::Keyboard::Q;
    else if (str == "R") return sf::Keyboard::R;
    else if (str == "S") return sf::Keyboard::S;
    else if (str == "T") return sf::Keyboard::T;
    else if (str == "U") return sf::Keyboard::U;
    else if (str == "V") return sf::Keyboard::V;
    else if (str == "W") return sf::Keyboard::W;
    else if (str == "X") return sf::Keyboard::X;
    else if (str == "Y") return sf::Keyboard::Y;
    else if (str == "Z") return sf::Keyboard::Z;
    else if (str == "Num0") return sf::Keyboard::Num0;
    else if (str == "Num1") return sf::Keyboard::Num1;
    else if (str == "Num2") return sf::Keyboard::Num2;
    else if (str == "Num3") return sf::Keyboard::Num3;
    else if (str == "Num4") return sf::Keyboard::Num4;
    else if (str == "Num5") return sf::Keyboard::Num5;
    else if (str == "Num6") return sf::Keyboard::Num6;
    else if (str == "Num7") return sf::Keyboard::Num7;
    else if (str == "Num8") return sf::Keyboard::Num8;
    else if (str == "Num9") return sf::Keyboard::Num9;
    else if (str == "Escape") return sf::Keyboard::Escape;
    else if (str == "LControl") return sf::Keyboard::LControl;
    else if (str == "LShift") return sf::Keyboard::LShift;
    else if (str == "LAlt") return sf::Keyboard::LAlt;
    else if (str == "LSystem") return sf::Keyboard::LSystem;
    else if (str == "RControl") return sf::Keyboard::RControl;
    else if (str == "RShift") return sf::Keyboard::RShift;
    else if (str == "RAlt") return sf::Keyboard::RAlt;
    else if (str == "RSystem") return sf::Keyboard::RSystem;
    else if (str == "Menu") return sf::Keyboard::Menu;
    else if (str == "LBracket") return sf::Keyboard::LBracket;
    else if (str == "RBracket") return sf::Keyboard::RBracket;
    else if (str == "SemiColon") return sf::Keyboard::SemiColon;
    else if (str == "Comma") return sf::Keyboard::Comma;
    else if (str == "Period") return sf::Keyboard::Period;
    else if (str == "Quote") return sf::Keyboard::Quote;
    else if (str == "Slash") return sf::Keyboard::Slash;
    else if (str == "BackSlash") return sf::Keyboard::BackSlash;
    else if (str == "Tilde") return sf::Keyboard::Tilde;
    else if (str == "Equal") return sf::Keyboard::Equal;
    else if (str == "Dash") return sf::Keyboard::Dash;
    else if (str == "Space") return sf::Keyboard::Space;
    else if (str == "Return") return sf::Keyboard::Return;
    else if (str == "BackSpace") return sf::Keyboard::BackSpace;
    else if (str == "Tab") return sf::Keyboard::Tab;
    else if (str == "PageUp") return sf::Keyboard::PageUp;
    else if (str == "PageDown") return sf::Keyboard::PageDown;
    else if (str == "End") return sf::Keyboard::End;
    else if (str == "Home") return sf::Keyboard::Home;
    else if (str == "Insert") return sf::Keyboard::Insert;
    else if (str == "Delete") return sf::Keyboard::Delete;
    else if (str == "Add") return sf::Keyboard::Add;
    else if (str == "Subtract") return sf::Keyboard::Subtract;
    else if (str == "Multiply") return sf::Keyboard::Multiply;
    else if (str == "Divide") return sf::Keyboard::Divide;
    else if (str == "Left") return sf::Keyboard::Left;
    else if (str == "Right") return sf::Keyboard::Right;
    else if (str == "Up") return sf::Keyboard::Up;
    else if (str == "Down") return sf::Keyboard::Down;
    else if (str == "Numpad0") return sf::Keyboard::Numpad0;
    else if (str == "Numpad1") return sf::Keyboard::Numpad1;
    else if (str == "Numpad2") return sf::Keyboard::Numpad2;
    else if (str == "Numpad3") return sf::Keyboard::Numpad3;
    else if (str == "Numpad4") return sf::Keyboard::Numpad4;
    else if (str == "Numpad5") return sf::Keyboard::Numpad5;
    else if (str == "Numpad6") return sf::Keyboard::Numpad6;
    else if (str == "Numpad7") return sf::Keyboard::Numpad7;
    else if (str == "Numpad8") return sf::Keyboard::Numpad8;
    else if (str == "Numpad9") return sf::Keyboard::Numpad9;
    else if (str == "F1") return sf::Keyboard::F1;
    else if (str == "F2") return sf::Keyboard::F2;
    else if (str == "F3") return sf::Keyboard::F3;
    else if (str == "F4") return sf::Keyboard::F4;
    else if (str == "F5") return sf::Keyboard::F5;
    else if (str == "F6") return sf::Keyboard::F6;
    else if (str == "F7") return sf::Keyboard::F7;
    else if (str == "F8") return sf::Keyboard::F8;
    else if (str == "F9") return sf::Keyboard::F9;
    else if (str == "F10") return sf::Keyboard::F10;
    else if (str == "F11") return sf::Keyboard::F11;
    else if (str == "F12") return sf::Keyboard::F12;
    else if (str == "F13") return sf::Keyboard::F13;
    else if (str == "F14") return sf::Keyboard::F14;
    else if (str == "F15") return sf::Keyboard::F15;
    else if (str == "Pause") return sf::Keyboard::Pause;
    else {
        throw std::invalid_argument("Touche non reconnue");
    }
}

std::string KeybindingOptionMenu::keyToString(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::A:
            return "A";
        case sf::Keyboard::B:
            return "B";
        case sf::Keyboard::C:
            return "C";
        case sf::Keyboard::D:
            return "D";
        case sf::Keyboard::E:
            return "E";
        case sf::Keyboard::F:
            return "F";
        case sf::Keyboard::G:
            return "G";
        case sf::Keyboard::H:
            return "H";
        case sf::Keyboard::I:
            return "I";
        case sf::Keyboard::J:
            return "J";
        case sf::Keyboard::K:
            return "K";
        case sf::Keyboard::L:
            return "L";
        case sf::Keyboard::M:
            return "M";
        case sf::Keyboard::N:
            return "N";
        case sf::Keyboard::O:
            return "O";
        case sf::Keyboard::P:
            return "P";
        case sf::Keyboard::Q:
            return "Q";
        case sf::Keyboard::R:
            return "R";
        case sf::Keyboard::S:
            return "S";
        case sf::Keyboard::T:
            return "T";
        case sf::Keyboard::U:
            return "U";
        case sf::Keyboard::V:
            return "V";
        case sf::Keyboard::W:
            return "W";
        case sf::Keyboard::X:
            return "X";
        case sf::Keyboard::Y:
            return "Y";
        case sf::Keyboard::Z:
            return "Z";
        case sf::Keyboard::Num0:
            return "Num0";
        case sf::Keyboard::Num1:
            return "Num1";
        case sf::Keyboard::Num2:
            return "Num2";
        case sf::Keyboard::Num3:
            return "Num3";
        case sf::Keyboard::Num4:
            return "Num4";
        case sf::Keyboard::Num5:
            return "Num5";
        case sf::Keyboard::Num6:
            return "Num6";
        case sf::Keyboard::Num7:
            return "Num7";
        case sf::Keyboard::Num8:
            return "Num8";
        case sf::Keyboard::Num9:
            return "Num9";
        case sf::Keyboard::Escape:
            return "Escape";
        case sf::Keyboard::LControl:
            return "LControl";
        case sf::Keyboard::LShift:
            return "LShift";
        case sf::Keyboard::LAlt:
            return "LAlt";
        case sf::Keyboard::LSystem:
            return "LSystem";
        case sf::Keyboard::RControl:
            return "RControl";
        case sf::Keyboard::RShift:
            return "RShift";
        case sf::Keyboard::RAlt:
            return "RAlt";
        case sf::Keyboard::RSystem:
            return "RSystem";
        case sf::Keyboard::Menu:
            return "Menu";
        case sf::Keyboard::LBracket:
            return "LBracket";
        case sf::Keyboard::RBracket:
            return "RBracket";
        case sf::Keyboard::SemiColon:
            return "SemiColon";
        case sf::Keyboard::Comma:
            return "Comma";
        case sf::Keyboard::Period:
            return "Period";
        case sf::Keyboard::Quote:
            return "Quote";
        case sf::Keyboard::Slash:
            return "Slash";
        case sf::Keyboard::BackSlash:
            return "BackSlash";
        case sf::Keyboard::Tilde:
            return "Tilde";
        case sf::Keyboard::Equal:
            return "Equal";
        case sf::Keyboard::Dash:
            return "Dash";
        case sf::Keyboard::Space:
            return "Space";
        case sf::Keyboard::Return:
            return "Return";
        case sf::Keyboard::BackSpace:
            return "BackSpace";
        case sf::Keyboard::Tab:
            return "Tab";
        case sf::Keyboard::PageUp:
            return "PageUp";
        case sf::Keyboard::PageDown:
            return "PageDown";
        case sf::Keyboard::End:
            return "End";
        case sf::Keyboard::Home:
            return "Home";
        case sf::Keyboard::Insert:
            return "Insert";
        case sf::Keyboard::Delete:
            return "Delete";
        case sf::Keyboard::Add:
            return "Add";
        case sf::Keyboard::Subtract:
            return "Subtract";
        case sf::Keyboard::Multiply:
            return "Multiply";
        case sf::Keyboard::Divide:
            return "Divide";
        case sf::Keyboard::Left:
            return "Left";
        case sf::Keyboard::Right:
            return "Right";
        case sf::Keyboard::Up:
            return "Up";
        case sf::Keyboard::Down:
            return "Down";
        case sf::Keyboard::Numpad0:
            return "Numpad0";
        case sf::Keyboard::Numpad1:
            return "Numpad1";
        case sf::Keyboard::Numpad2:
            return "Numpad2";
        case sf::Keyboard::Numpad3:
            return "Numpad3";
        case sf::Keyboard::Numpad4:
            return "Numpad4";
        case sf::Keyboard::Numpad5:
            return "Numpad5";
        case sf::Keyboard::Numpad6:
            return "Numpad6";
        case sf::Keyboard::Numpad7:
            return "Numpad7";
        case sf::Keyboard::Numpad8:
            return "Numpad8";
        case sf::Keyboard::Numpad9:
            return "Numpad9";
        case sf::Keyboard::F1:
            return "F1";
        case sf::Keyboard::F2:
            return "F2";
        case sf::Keyboard::F3:
            return "F3";
        case sf::Keyboard::F4:
            return "F4";
        case sf::Keyboard::F5:
            return "F5";
        case sf::Keyboard::F6:
            return "F6";
        case sf::Keyboard::F7:
            return "F7";
        case sf::Keyboard::F8:
            return "F8";
        case sf::Keyboard::F9:
            return "F9";
        case sf::Keyboard::F10:
            return "F10";
        case sf::Keyboard::F11:
            return "F11";
        case sf::Keyboard::F12:
            return "F12";
        case sf::Keyboard::F13:
            return "F13";
        case sf::Keyboard::F14:
            return "F14";
        case sf::Keyboard::F15:
            return "F15";
        case sf::Keyboard::Pause:
            return "Pause";
        case sf::Keyboard::KeyCount:
            return "KeyCount";
        case sf::Keyboard::Unknown:
        default:
            return "Touche non reconnue";
    }
}

void KeybindingOptionMenu::updateValues() {
    // ON MET A JOUR LES POSITION EN FONCTION DE LA TAILLE DE LA FENETRE
    titleText.setPosition(window->getSize().x / 2, 50);
    titleText1.setPosition(window->getSize().x / 4, 200);
    keybindingOption1Text.setPosition(window->getSize().x / 4, 300);
    keybindingOption2Text.setPosition(window->getSize().x / 4, 400);
    keybindingOption3Text.setPosition(window->getSize().x / 4, 500);
    keybindingOption4Text.setPosition(window->getSize().x / 4, 600);
    titleText2.setPosition(window->getSize().x * 0.75, 200);
    keybindingOption5Text.setPosition(window->getSize().x * 0.75, 300);
    keybindingOption6Text.setPosition(window->getSize().x * 0.75, 400);
    keybindingOption7Text.setPosition(window->getSize().x * 0.75, 500);
    keybindingOption8Text.setPosition(window->getSize().x * 0.75, 600);
}

Menu *KeybindingOptionMenu::clone() {
    return new KeybindingOptionMenu(window);
}



