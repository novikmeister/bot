#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return sqrtf((start.x - finish.x) * (start.x - finish.x) + (start.y - finish.y) * (start.y - finish.y));
}

sf::Vector2f angle(sf::Vector2f start, sf::Vector2f finish)
{
    sf::Vector2f ang = { (finish.x - start.x), (finish.y - start.y) };
    ang = ang / distance(start, finish);
    return  ang;
}



struct Ball
{
    float radius;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float mass;
    int charge;

    /*Ball( float radius, sf::Vector2f position, sf::Vector2f velocity, float mass, int charge) : 
         radius(radius), position(position), velocity(velocity), mass(mass), charge(charge)
    {  
    }
    Ball()
    {
        radius = 0;
        position = { 0, 0 };
        velocity = { 0, 0 };
        mass = 0;
        charge = 0;
    }*/
};


int main()
{
    srand(time(0));

    const int width = 1000;
    const int height = 800;
    int n_balls = 20;

    // Шаг по времени
    const float delta_t = 0.1;

    // Создаём экземпляр класса окно
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    // Задаём максимальное количество кадров в секунду
    window.setFramerateLimit(60);

    // Так как sf::CircleShape занимает много памяти, создаём всего 1 экземпляр
    sf::CircleShape circle(50.0f);
    circle.setFillColor({ 255, 30, 30 });


    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].radius = 6 + rand() % 12;
        float w = (float)(rand() % width);
        float h = (float)(rand() % height);

        if ((w - balls[i].radius) < 0)
            w = w + balls[i].radius + 5;
        if ((w - balls[i].radius) > width)
            w = w - balls[i].radius - 5;
        if ((h - balls[i].radius) < 0)
            h = h + 5 + balls[i].radius;
        if ((h - balls[i].radius) > height)
            h = h - 5 - balls[i].radius;
        balls[i].position = { w, h };

        balls[i].velocity = { (float)(rand() % 100 - 50), (float)(rand() % 100 - 50) };
        balls[i].mass = 3.14 * balls[i].radius * balls[i].radius;
        balls[i].charge = (int)(rand() % 510)-255;
    }
    /*balls[0].radius = 10;                   // отладка
    balls[0].position = { 15, 15 };
    balls[0].velocity = { 0, 0 };
    balls[0].mass = 1;
    balls[1].radius = 20;
    balls[1].position = { 970, 150 };
    balls[1].velocity = { 0, 0};
    balls[1].mass = 1;
    balls[0].charge = 255;
    balls[1].charge = 255;*/
    
    int n_added = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f mouse_position = { (float)event.mouseButton.x, (float)event.mouseButton.y };
            sf::Vector2f veloc = { (float)(rand() % 100 - 50), (float)(rand() % 100 - 50) };
            balls.resize(n_balls + 1);
            n_balls++;
            // При нажатии левой кнопки мыши:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                balls[balls.size() - 1].radius = 12;
                balls[balls.size() - 1].position = mouse_position;
                balls[balls.size() - 1].velocity = veloc;
                balls[balls.size() - 1].mass = (3.14 * 12 * 12);
                // Если зажат левый Shift
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                    balls[balls.size() - 1].charge = -128;
                else
                    balls[balls.size() - 1].charge = 128;
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                balls[balls.size() - 1].radius = 25;
                balls[balls.size() - 1].position = mouse_position;
                balls[balls.size() - 1].velocity = veloc;
                balls[balls.size() - 1].mass = (3.14 * 25 * 25);
                // Если зажат левый Shift
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                    balls[balls.size() - 1].charge = -250;
                else
                    balls[balls.size() - 1].charge = 250;
            }
        }
        for (int i = 0; i < n_balls; i++) 
        {
            balls[i].position += balls[i].velocity * delta_t;

            
            /*if (balls[i].position.x < 0)  // телепорт на другую сторону 
                balls[i].position.x += width;
            if (balls[i].position.x > width)
                balls[i].position.x -= width;

            if (balls[i].position.y < 0)
                balls[i].position.y += height;
            if (balls[i].position.y > height)
                balls[i].position.y -= height;*/
            
            // Используем 1 sf::CircleShape, чтобы нарисовать все шары
            circle.setRadius(balls[i].radius);
            // setOrigin - задаёт центр объекта
            // По умолчанию центр - в левом верхнем угле объекта
            // Строка ниже устанавливает центр в центре шарика
            // В дальнейшем функция, setPosition устанавливает положение шарика так, 
            // чтобы его центр был в точке balls[i].position
            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);




            if ((balls[i].position.x - balls[i].radius) < 0 || (balls[i].position.x + balls[i].radius) > width)  // отражение
                balls[i].velocity.x *= -1;
            if ((balls[i].position.y - balls[i].radius) < 0 || (balls[i].position.y + balls[i].radius) > height)
                balls[i].velocity.y *= -1;

             
            float min_distance = 20;
            for (int k = i; k < n_balls; ++k)
            {
                float dis = distance(balls[i].position, balls[k].position);

                if (dis > min_distance)
                {   
                    sf::Vector2f ang = angle(balls[i].position, balls[k].position);
                    
                    float const_power = 0.001;                     // гравитация
                    float f_grav = const_power * balls[i].mass * balls[k].mass / (dis * dis);
                    balls[i].velocity += ang * f_grav;
                    balls[k].velocity -= ang * f_grav;
                    
                    float const_charge = 0.5;                    // сила кулона
                    float f_kul = - const_charge * balls[i].charge * balls[k].charge / (dis * dis);
                    balls[i].velocity += ang * f_kul;
                    balls[k].velocity -= ang * f_kul;
                    

                }
            }
            unsigned char color = (unsigned char)(abs(balls[i].charge));
            //if (color < 50)
              //  color += 30;
            if(balls[i].charge > 0)
                circle.setFillColor({ color, 0, 0 });
            if (balls[i].charge < 0)
                circle.setFillColor({ 0, 0, color });
            window.draw(circle);
        }

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}