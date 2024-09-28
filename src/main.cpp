/**
 * @file main.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Main for MineSweeper.
 * @headerfile "include/generator/fieldgenerator.hpp"
 * @headerfile "SFML/Graphics.hpp"
 */

#include "generator/fieldgenerator.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Generation
    MineSweeper::Generation::FieldGenerator fieldGenerator(10, 10, 4);
    std::unique_ptr<MineSweeper::FieldVector> playfield = fieldGenerator.generateField();

    // testing only
    // TODO: Remove
    for (std::vector<MineSweeper::CellStruct> row : playfield->getFieldGrid()) {
        for (MineSweeper::CellStruct column : row) {
            std::cout << (column.isMine ? "X" : std::to_string(column.adjecentMines));
        }
        std::cout << "\n";
    }

    // setting up SFML (according to https://github.com/SFML/cmake-sfml-project/blob/a9b227e6575ba2509139208c2ca31f9b54004b40/src/main.cpp)
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

        // refresh GUI
        window.clear();
        window.display();
    }

    // exit program
    return 0;
}