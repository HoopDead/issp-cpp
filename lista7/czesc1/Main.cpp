#include <SFML/Graphics.hpp>

int main()
{
    const int HEIGHT = 800;
    const int WIDTH = 600;
    const int RADIUS = 150.f;
    float x = 250;
    float y = 150;
    float vx = 0.5;
    float vy = 0.5;
    int dt = 5;
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "Czesc 1");
    sf::CircleShape shape(RADIUS);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        if(x > 500)
        {
            vx = -0.5;
        }
        else if(x < 0)
        {
            vx = 0.5;
        }
        else if(y > 300)
        {
            vy = -0.5;
        }
        else if(y < 0)
        {
            vy = 0.5;
        }
        x = x+vx;
        y = y+vy;
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear();
        shape.setPosition(x, y);
        window.draw(shape);
        window.display();
    }
    return 0;
}