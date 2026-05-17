#include "States/GameOverState.h"
#include "States/MenuState.h"
#include "Commands/ChangeStateCommand.h"

#include <iostream>

void GameOverState::Render() {
    std::cout << "Game Over Render" << std::endl;
}

void GameOverState::Update() {
    std::cout << "Game Over Update" << std::endl;
}

Command* GameOverState::InputHandler(char input) {
    switch (input) {
        case 'm': return new ChangeStateCommand(new MenuState());
        default:
            return nullptr;
    }
}
