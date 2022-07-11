//
// Created by Qiu Le Chen on 10-Jul-22.
//

#include "CollisionBox.h"
#include <cmath>

float CollisionBox::getPosX() {
    return posX;
}

float CollisionBox::getPosY() {
    return posY;
}

float CollisionBox::getAngle() {
    return angle;
}

float CollisionBox::getWidth() {
    return width;
}

float CollisionBox::getHeight() {
    return height;
}

void CollisionBox::transform(float aPosX, float aPosY, float *rotPosX, float *rotPosY) {
    float transPosX;
    float transPosY;

    transPosX = aPosX - this->getPosX();
    transPosY = aPosY - this->getPosY();
    *rotPosX = transPosX * std::cos(this->getAngle()) + transPosY * std::sin(this->getAngle());
    *rotPosY = -transPosX * std::sin(this->getAngle()) + transPosY * std::cos(this->getAngle());
}

bool CollisionBox::collisionCheck(float aPosX, float aPosY, float aDistanceX, float aDistanceY) {
    float rotPosX;
    float rotPosY;

    transform(aPosX, aPosY, &rotPosX, &rotPosY);

    return (std::abs(rotPosX) < aDistanceX &&
            std::abs(rotPosY) < aDistanceY);
}