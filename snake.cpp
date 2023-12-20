#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Snake {
    private:
        char direction;
        int length;
        int headX;
        int headY;
        vector<pair<int, int>> snake_cords;

    public:
        Snake() {
            direction = 'U';
            length = 3;
            headX = 25;
            headY = 13;

            for (int i = 0; i < length; i++) {
                snake_cords.push_back(make_pair(headX, headY - i));
            }
        }

        const vector<pair<int, int>>& getSnakeCords() const {
            return snake_cords;
        }
};

class Fruit {
    private:
        pair<int, int>  fruit_cords;

    public:
        Fruit() : fruit_cords(make_pair(-1, -1)) {};

        void generateFruitCords(const GameBoard& game_board)
            
        }
};

class GameBoard {
    private:
        static const int WIDTH = 50;
        static const int HEIGHT = 25;
        char board[HEIGHT][WIDTH];

    public:
        GameBoard() {
            for (int y = 0; y < HEIGHT; y++) {
                for (int x = 0; x < WIDTH; x++) {
                    if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                        board[y][x] = '#';
                        continue;
                    }
                    board[y][x] = ' ';
                }
            }
        };

        void initSnakeToBoard(const Snake& snake) {
            vector<pair<int, int>> snake_cords = snake.getSnakeCords();

            for (const auto& pair : snake_cords) {
                board[pair.second][pair.first] = 'S';
            };
        }

        void DrawBoard() {
            for (int y = 0; y < HEIGHT; y++) {
                for (int x = 0; x < WIDTH; x++) {
                    cout << board[y][x];
                }
                cout << endl;
            }
        }

        void ClearBoard() {
            system("cls");
        }
};

int main()
{
    Snake snake;
    GameBoard game_board;
    game_board.initSnakeToBoard(snake);
    game_board.DrawBoard();
    
    return 0;
}
