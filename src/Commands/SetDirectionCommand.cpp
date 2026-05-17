#include "Commands/SetDirectionCommand.h"
#include "Core/GameManager.h"

SetDirectionCommand::SetDirectionCommand(Direction _dir) : dir(_dir) {}

void SetDirectionCommand::Execute() {
    GameManager *gm = GameManager::GetInstance();
    Snake *snake = gm->GetSnake();
    snake->SetDirection(dir);
} 
