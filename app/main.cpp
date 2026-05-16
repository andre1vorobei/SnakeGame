#include "Core/GameManager.h"
#include "States/MenuState.h"
#include "States/PlayingState.h"
#include "States/GameOverState.h"

int main() {
    GameManager *manager = GameManager::GetInstance();
    manager->ChangeState(new MenuState());
    manager->Run();    

    return 0;
}
