#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    int keyonoff = 1;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
                keyonoff=1-keyonoff;
            }
        }
        window.clear(sf::Color::Black);
        if(keyonoff)
        {
            window.draw(shape);
            window.display();
        }
    }
    return 0;
}