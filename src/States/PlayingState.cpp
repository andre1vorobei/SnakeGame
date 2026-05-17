#include "States/PlayingState.h"
#include "States/MenuState.h"
#include "Commands/ChangeStateCommand.h"
#include <iostream>

void PlayingState::Render() {
    std::cout << "Playing Render" << std::endl;
}

void PlayingState::Update() {
    std::cout << "Playing Update" << std::endl;
}

Command* PlayingState::InputHandler(char input) {
    switch (input) {
        case 'm': return new ChangeStateCommand(new MenuState());
        default:
            return nullptr;
    }
}
