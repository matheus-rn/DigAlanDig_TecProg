#include "Alan.h"
#include <algorithm>
#include "AlanAnimation.h"
#include "Interpol.h"
#include "Sprite.h"

Alan::Alan(GameObject &associated)
    : Component(associated), input(InputManager::GetInstance()) 
    {}

// Direção do movimento
void Alan::getMovement() 
{
    if (moved ||
        associated.getComponent<AlanActionControl *>()->getMovementDirection())
        return;
    //
    if (input.actionPress(input.dig_up)) 
    {
        associated.getComponent<AlanActionControl *>()->setMovementDirection(
            AlanActionControl::Direction::up);
        moved = true;
    }
    if (input.actionPress(input.dig_down)) 
    {
        associated.getComponent<AlanActionControl *>()->setMovementDirection(
            AlanActionControl::Direction::down);
        moved = true;
    }
    if (input.actionPress(input.dig_left)) 
    {
        associated.getComponent<AlanActionControl *>()->setMovementDirection(
            AlanActionControl::Direction::left);
        moved = true;
    }
    if (input.actionPress(input.dig_right)) 
    {
        associated.getComponent<AlanActionControl *>()->setMovementDirection(
            AlanActionControl::Direction::right);
        moved = true;
    }

    if (associated.getComponent<AlanActionControl *>()
            ->getMovementDirection()) 
            {
        float duty = 0.6;
        input.move();
        if (std::abs(input.getDeltaRhythm()) < duty) 
        {
            std::cout << "\n\nHit: " << input.getDeltaRhythm() << "\n\n";
            Game::getInstance()->combo++;
        } else 
        {
            Camera::shake();
            Game::getInstance()->combo = 0;
            std::cout << "\n\nMiss: " << input.getDeltaRhythm() << "\n\n";
        }
    }

    Game::getInstance()->getGridControl()->checkEnemyAlanCollision(true);
}

void Alan::update(float dt) 
{
    if (max_position < std::max(associated.gridPosition.y + 4, 7.0)) 
    {
        max_position = std::max(associated.gridPosition.y + 4, 7.0);
    }

    getMovement();
}
