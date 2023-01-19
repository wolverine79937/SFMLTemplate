#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(320,200), "My SFML Template Window", sf::Style::Default);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                // Close window button clicked.
                window.close();
            }
        }
        window.clear(sf::Color::Blue);
        // Draw here.
        window.display();
    }
}