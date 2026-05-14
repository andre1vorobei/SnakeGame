#include "States/MenuState.h"
#include "States/PlayingState.h"
#include <iostream>

void MenuState::Render() {
    std::cout << "Menu Render" << std::endl;
    manager->ChangeState(new PlayingState());
}

void MenuState::Update() {
    std::cout << "Menu Update" << std::endl;
}
