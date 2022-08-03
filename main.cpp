#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <unistd.h>


struct ball {
  double x;
  double y;
  double xv;
  double yv;
};

int main() {
    int wid = 400;
    int hei = 400;
    
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(wid, hei), "test");
    
    int numballs = 10;
    ball balls[numballs];
    
    for (int i = 0; i < numballs; i++) {
      balls[i].x = 100;
      balls[i].y = 100;
      balls[i].xv = rand() % 20 - 10;
      balls[i].yv = rand() % 20 - 10;
      std::cout << balls[i].xv;
    }
    
    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                wid = event.size.width;
                hei = event.size.height;
            }
        }


        //wid = window.getSize().x;
        //hei = window.getSize().y;
        
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
          window.clear();
        }
        for (int i = 0; i < numballs; i++) {
          if (balls[i].x < 0) {
            balls[i].x = 0;
            balls[i].xv *= -1;
          }
          if (balls[i].x > wid-20) {
            balls[i].x = wid-20;
            balls[i].xv *= -1;
          }
          if (balls[i].y < 0) {
            balls[i].y = 0;
            balls[i].yv *= -1;
          }
          if (balls[i].y > hei-20) {
            balls[i].y = hei-20;
            balls[i].yv *= -1;
          }
          
          balls[i].x += balls[i].xv;
          balls[i].y += balls[i].yv;
          

          /*
          if (balls[i].x < 10 || balls[i].x > wid-10) {
            balls[i].xv *= -1;
          }
          
          if (balls[i].y < 10 || balls[i].y > hei-10) {
            balls[i].yv *= -1;
          }*/
          
          sf::CircleShape shape(10);
          shape.setFillColor(sf::Color(200, 200, 200));
          shape.setPosition(balls[i].x, balls[i].y);
          window.draw(shape);
        }
      
        window.display();
        
        usleep(1000000/50);
    }

    return 0;
}
