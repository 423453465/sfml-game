#include <SFML/Graphics.hpp>
#include <cmath>

int main() {

int a,b,c;

a = 50;
b = a*2;
c = (sqrt(pow(a, 2) + pow(b, 2)));

int x_offset = 0;
int y_offset = 0;
int num_rows = 5;
int num_columns = 5;
int key_x = 0;
int key_y = 0;

    sf::RenderWindow window(sf::VideoMode(200, 200), "Window");
    window.setFramerateLimit(60);

    	// create an empty shape
	 std::vector<std::vector<sf::ConvexShape>> tiles(num_rows, std::vector<sf::ConvexShape>(num_columns));


	for (int i = 1; i < num_rows; ++i) {
		for (int j = 1; j < num_columns; j++) {
	
	// resize it to 4 points
	tiles[i][j].setPointCount(4);
	
	x_offset = ((i * 2*b) + j * b) - (2*b * j);
	y_offset = (j * c/2);

	tiles[i][j].setFillColor(j % 2 == 0 ? sf::Color::Blue : sf::Color::Red);

	// define the points
	//
	//    *1*
	//  ********
	//0**********2
	//  ********
	//    *3*
	//

	tiles[i][j].setPoint(0, sf::Vector2f(0 + x_offset, c/2 + y_offset));
	tiles[i][j].setPoint(1, sf::Vector2f(b + x_offset, 0 + y_offset));
	tiles[i][j].setPoint(2, sf::Vector2f((b * 2) + x_offset, c/2 + y_offset));
	tiles[i][j].setPoint(3, sf::Vector2f(b + x_offset, c + y_offset));

		}

	}

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))

        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key_y += 10; // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key_y -= 10; // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            key_x += 10; // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            key_x -= 10; // Move right
        }

        window.clear();
        
	for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_columns; j++) {

		window.draw(tiles[i][j]);
		tiles[i][j].setPosition(key_x, key_y);
        	}
	}

        window.display();
    }

    return 0;
}
