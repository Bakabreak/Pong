//
// Created by Qiu Le Chen on 10-Jul-22.
//

#include "CollisionBox.h"
#include <cmath>
#include <string>

void CollisionBox::setTag(std::string aTag) {
    this->tag = aTag;
}

std::string CollisionBox::getTag(){
    return this->tag;
}

void CollisionBox::setWidth(float width) {
    this->width = width;
}

void CollisionBox::setHeight(float height) {
    this->height = height;
}

void CollisionBox::setPos(float posX, float posY){
    this->posX = posX;
    this->posY = posY;
}
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

    transPosX = aPosX - this->posX;
    transPosY = aPosY - this->posY;
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