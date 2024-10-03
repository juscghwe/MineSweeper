/**
 * @file main.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Main for MineSweeper.
 * @headerfile "generator/fieldgenerator.hpp"
 * @headerfile "utility/fieldvector.hpp"
 */

#include "generator/fieldgenerator.hpp"
#include "gui/fieldarray.hpp"
#include "gui/texturemanager.hpp"
#include "utility/fieldvector.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    // Generation
    Generator::FieldGenerator fieldGenerator(10, 10, 4);
    std::unique_ptr<Utility::FieldVector> playfield = fieldGenerator.generateField();

    // Texture manager
    Gui::TextureManager& textureManager = Gui::TextureManager::getInstance();
    Gui::FieldArray fieldArray(playfield, textureManager);

    // GUI / Gameloop
    auto window = sf::RenderWindow{{500u, 500u}, "MineSweeper"};
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        //event handling
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        fieldArray.draw(window);

        window.display();
    }

    // exit program
    return 0;
}