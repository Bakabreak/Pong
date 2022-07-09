//
// Created by Qiu Le Chen on 09-Jul-22.
//
#include "player.h"
#include <GLFW/glfw3.h>

Player::Player(int aPlayerId) {
    this->playerId = aPlayerId;
}

void Player::setWidth(float aWidth) {
    this->width = aWidth;
}

void Player::setHeight(float aHeight) {
    this->height = aHeight;
}

float Player::getPosX() {
    return this->posX;
}

float Player::getPosY() {
    return this->posY;
}

void Player::updatePos(float xNew, float yNew) {
    this->posX = xNew;
    this->posY = yNew;
}

void Player::renderPlayer() {
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2d(posX - width / 2, posY - height / 2);
    glVertex2d(posX + width / 2, posY - height / 2);
    glVertex2d(posX + width / 2, posY + height / 2);
    glVertex2d(posX - width / 2, posY + height / 2);
    glEnd();
}