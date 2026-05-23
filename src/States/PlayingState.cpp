#include "States/PlayingState.h"
#include "States/MenuState.h"
#include "States/GameOverState.h"
#include "Commands/ChangeStateCommand.h"
#include "Commands/SetDirectionCommand.h"
#include <iostream>

PlayingState::PlayingState(Snake *_snake) : snake(_snake) {}

void PlayingState::Render() {
    std::cout << "\033[2J\033[H";

    //debug 
    std::cout << "FieldSize: " << snake->GetFieldWidth() << " " << snake->GetFieldHeigh() << std::endl;
    std::cout << "Snake Head: " << snake->GetHead().x << " " << snake->GetHead().y << std::endl;
    std::cout << "Food: " << snake->GetFood().x << " " << snake->GetFood().y << std::endl;

    // верняя граница
    std::cout << "\033[1;43m";
    for (int x = 0; x <= defaultW + 2; x++) std::cout << "#";
    std::cout << "\033[0m";
    std::cout << std::endl;

    // поле
    for (int y = 0; y < defaultH+1; y++) {
        std::cout << "\033[1;43m";
        std::cout << "#";
        std::cout << "\033[0m";
        for (int x = 0; x <= defaultW; x++) {
            bool isSpace = true;

            Point food = snake->GetFood();
            if (food.x == x && food.y == y) {
                isSpace = false;
                std::cout << "\033[1;31m";
                std::cout << "0";
                std::cout << "\033[0m";
            }
            
            if (isSpace) {
                for (Point segment : snake->GetBody()) {
                    if (segment.x == x && segment.y == y) {
                        std::cout << "\033[1;32m";
                        isSpace = false;
                        Point head = snake->GetHead();
                        if (segment.x == head.x && segment.y == head.y) {
                            std::cout << "O";
                        } else {
                            std::cout << "o";
                        }
                        std::cout << "\033[0m";
                        break;
                    }
                }
            }
            if (isSpace)
                std::cout << " ";
        }
        std::cout << "\033[1;43m";
        std::cout << "#" << std::endl;
        std::cout << "\033[0m";
    }
                
    // нижняя граница
    std::cout << "\033[1;43m";
    for (int x = 0; x <= defaultW + 2; x++) std::cout << "#";
    std::cout << "\033[0m";
    std::cout << std::endl;
}

void PlayingState::Update() {
    snake->Move();
    if (snake->IsCollided()) {
        manager->ChangeState(new GameOverState());
    }
}

Command* PlayingState::InputHandler(char input) {
    switch (input) {
        case 'm': return new ChangeStateCommand(new MenuState());
        case 'w': return new SetDirectionCommand(Direction::UP);
        case 's': return new SetDirectionCommand(Direction::DOWN);
        case 'a': return new SetDirectionCommand(Direction::LEFT);
        case 'd': return new SetDirectionCommand(Direction::RIGHT);

        default:
            return nullptr;
    }
}
