#pragma once

#include "Core/Point.h"
#include <deque>

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
    private:
        std::deque<Point> body;
        Direction dir;
        Point food;
        int fieldH;
        int fieldW;

        void spawnFood();
        bool isOnSnake(Point new_food);

    public:
        Snake(int fieldH, int fieldW);

        void SetDirection(Direction d);
        void Move();

        Point GetHead();
        Point GetFood();
        const std::deque<Point>& GetBody() const;

        bool IsCollided();
        bool IsSelfCollided();

        int GetFieldHeigh();
        int GetFieldWidth();
        
};
