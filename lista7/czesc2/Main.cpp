#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    const int HEIGHT = 800;
    const int WIDTH = 600;
    float dt = 1;
    float x[5] = {50, 100, 150, 200, 250};
    float y[5] = {123, 90, 152, 223, 99};
    float vx[5] = {1, 0.8, 0.7, 0.3, 0.2};
    float vy[5] = {0.2, 0.3, 0.7, 0.8, 0.6};
    float temp_vy[5] = {0.2, 0.3, 0.7, 0.8, 0.6};
    const int N = 5;
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "Czesc 2");
    std::vector <sf::CircleShape> shapes(N);
    for(int i = 0; i < N; i++)
    {
        sf::CircleShape shape(120.f);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color(0,0,0));
        shapes[i] = shape;
    }
    while (window.isOpen())
    {
        dt += 0.0000001;
        for(int i = 0; i<N; i++)
        {
            if(x[i] > 555)
            {
                vx[i] = -0.5;
            }
            else if(x[i] < 0)
            {
                vx[i] = 0.5;
            }
            else if(y[i] > 355)
            {
                vy[i] = -0.5;
            }
            else if(y[i] < 0)
            {
                vy[i] = 0.5;
            }
            x[i] = x[i]+vx[i] * dt;
            y[i] = y[i]+vy[i] * dt;
            vy[i]= vy[i] + 0.001 * dt;
            temp_vy[i] += vy[i];
            shapes[i].setFillColor(sf::Color(0 + temp_vy[i], 125, 0));
        }
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
        for(int i = 0; i<N; i++)
        {
            window.draw(shapes[i]);
            shapes[i].setPosition(x[i], y[i]);
        }
        window.display();
    }
    return 0;
}