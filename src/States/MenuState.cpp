#include "Core/Kbhit.h"
#include "States/MenuState.h"
#include "States/PlayingState.h"

#include <iostream>

void MenuState::Render() {
    std::cout << "Menu Render" << std::endl;
}

void MenuState::Update() {
    std::cout << "Menu Update" << std::endl;
    if (Kbhit()) {
        char in = getchar();
        if (in == 'y') {
            std::cout << "Game started" << std::endl;
            manager->ChangeState(new PlayingState());
        }
    }
}
