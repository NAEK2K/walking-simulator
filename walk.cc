#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

class Game {
    public:

        // constructor - sets the maps initial values
        Game() {
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    map[i][j] = 0;
                }
            }
            x = 0;
            y = 0;
            score = 0;
        }
        // displays the map in the terminal
        void show() {
            system("clear");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if(this->x == j && this->y == i) {
                        std::cout << 1 << " ";
                    } else if(this->pointX == j && this->pointY == i) {
                        std::cout << 0 << " ";
                    } else {
                        // std::cout << map[i][j] << " ";
                        std::cout << "|" << " ";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "Score: " << this->score << std::endl;
        }
        // checks if x or y will go out of bounds in the next move, returns true if it will go out of bounds
        bool edgeCheck(int x, int y) {
            return this->x + x > 9 || this->x + x < 0 || this->y + y > 9 || this->y + y < 0;
        }

        // move the "character" around the map
        void move(char dir) {
            if(dir == 'w') {
                if(!edgeCheck(0, -1)) {
                        this->y--;
                    }
            } else if(dir == 's') {
                if(!edgeCheck(0, 1)) {
                        this->y++;
                    }
            } else if(dir == 'a') {
                if(!edgeCheck(-1, 0)) {
                        this->x--;
                    }
            } else if(dir == 'd') {
                if(!edgeCheck(1, 0)) {
                        this->x++;
                    }
            }
        }

        // generates a new point for the player to collect
        void generatePoint() {
            pointX = floor(rand() % 10);
            pointY = floor(rand() % 10);
            while(this->pointX == this->x && this->pointY == this->y) {
                pointX = floor(rand() % 10);
                pointY = floor(rand() % 10); 
            }
        }

        // checks if the user has picked up the point
        void collectPoint() {
            if(this->x == this->pointX && this->y == this->pointY) {
                score++;
                generatePoint();
            }
        }

        // runs the game in the terminal window
        void run() {
            this->generatePoint();
            this->show();
            char move;
            while (move != 'q') {
                std::cin >> move;
                // exit command
                if (move == 'q') {
                    break;
                }
                else {
                    this->move(move);
                    collectPoint();
                }
                this->show();
            }
        }

    private:
        int x, y;
        int pointX, pointY;
        int score;
        int map[10][10];
};

int main() {
    Game game;
    game.run();
    
    return 0;
}
