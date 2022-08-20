//
// Created by Qiu Le Chen on 11-Jul-22.
//

#include "PowerUps.h"
#include "CollisionBox.h"
#include "Ball.h"
#include <GLFW/glfw3.h>
#include <cmath>

PowerUps::PowerUps(float aWidth, float aHeight) {
    this->setWidth(aWidth);
    this->setHeight(aHeight);
    this->setTag("powerUp");
}

void PowerUps::setPos(float xPos, float yPos) {
    this->posY = yPos;
    this->posX = xPos;
}

void PowerUps::expand(Ball *ball) {
    ball->setRadius(ball->radius * 2);
}

void PowerUps::expand() {

}
