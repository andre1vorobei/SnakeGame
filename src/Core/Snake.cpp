#include "Core/Snake.h"

#include <random>


Snake::Snake(int _fieldH, int _fieldW) : dir(Direction::UP), fieldH(_fieldH), fieldW(_fieldW) {
    Point start_point{fieldW/2, fieldH/2};
    body.push_front(start_point);
    spawnFood();
}

void Snake::spawnFood() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> heighDist(0, fieldH);
    std::uniform_int_distribution<> widthDist(0, fieldW);
    
    Point new_food{widthDist(gen), heighDist(gen)};

    while (isOnSnake(new_food)) {
        new_food.x = widthDist(gen);
        new_food.y = heighDist(gen);
    }

    food = new_food;
    
}

bool Snake::isOnSnake(Point new_food) {
    for(Point p: body)
        if (p.x == new_food.x && p.y == new_food.y)
            return true;
    return false;
}

void Snake::SetDirection(Direction d) {
    dir = d;
}

void Snake::Move() {
    Point new_head = GetHead();
    switch (dir) {
        case(UP):
            new_head.y -= 1;
            break;
        case(DOWN):
            new_head.y += 1;
            break;
        case(LEFT):
            new_head.x -= 1;
            break;
        case(RIGHT):
            new_head.x += 1;
            break;
    }

    body.push_front(new_head);

    if (new_head.x == food.x && new_head.y == food.y) {
        spawnFood();
    } else {
        body.pop_back();
    } 
}

Point Snake::GetHead() {
    return body.front();
}

Point Snake::GetFood() {
    return food;
}

const std::deque<Point>& Snake::GetBody() const {
    return body;
}

bool Snake::IsCollided() {
    Point head = GetHead();
    if (head.x > fieldW || head.x < 0 || head.y > fieldH || head.y < 0 || IsSelfCollided()) 
        return true;
    return false;
}

bool Snake::IsSelfCollided() {
    Point head = GetHead();

    for (int i = 1; i < body.size(); i++)
        if (head.x == body[i].x && head.y == body[i].y)
            return true;
    return false;
}

int Snake::GetFieldHeigh() {
    return fieldH;
}

int Snake::GetFieldWidth() {
    return fieldW;
}
