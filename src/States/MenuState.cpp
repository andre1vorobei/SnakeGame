#include "States/MenuState.h"
#include "States/PlayingState.h"
#include "Commands/ChangeStateCommand.h"
#include <iostream>

void MenuState::Render() {
    std::cout << "\033[2J\033[H";
    std::cout << "Menu Render" << std::endl;
    std::cout << "press s to start" << std::endl;
}

void MenuState::Update() {
    std::cout << "Menu Update" << std::endl;
}

Command* MenuState::InputHandler(char input) {
    switch (input) {
        case 's': return new ChangeStateCommand(new PlayingState(GameManager::GetInstance()->GetSnake()));
        default:
            return nullptr;
    }
}
