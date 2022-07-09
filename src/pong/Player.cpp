//
// Created by Qiu Le Chen on 09-Jul-22.
//
#include "Player.h"
#include <GLFW/glfw3.h>
#include "../Input.h"
#include <cmath>

Player::Player(int aPlayerId, int aKeyUp, int aKeyDown, int aKeyLeft, int aKeyRight) {
    this->playerId = aPlayerId;
    this->keyUp = aKeyUp;
    this->keyDown = aKeyDown;
    this->keyLeft = aKeyLeft;
    this->keyRight = aKeyRight;
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

void Player::moveUp() {
    this->posY = std::min(this->posY + this->speed, 0.6f - this->height / 2 - 0.03f);
}

void Player::moveDown() {
    this->posY = std::max(this->posY - this->speed, -0.6f + this->height / 2 + 0.03f);
}

void Player::turnRight() {
    this->angle -= this->rotSpeed;
}

void Player::turnLeft() {
    this->angle += this->rotSpeed;
}

void Player::update() {
    if (input::isKeyDown(this->keyDown)) {
        moveDown();
    }
    if (input::isKeyDown(this->keyUp)) {
        moveUp();
    }
    if (input::isKeyDown(this->keyRight)){
        turnRight();
    }
    if (input::isKeyDown(this->keyLeft)){
        turnLeft();
    }
};

void Player::renderPlayer() {
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(posX - (width / 2)*std::cos(this->angle + (height / 2)*std::sin(this->angle)), posY - (height / 2)*std::sin(this->angle));
    glVertex2d(posX + (width / 2)*std::cos(this->angle), posY - (height / 2)*std::sin(this->angle));
    glVertex2d(posX + (width / 2)*std::cos(this->angle), posY + (height / 2)*std::sin(this->angle));
    glVertex2d(posX - (width / 2)*std::cos(this->angle), posY + (height / 2)*std::sin(this->angle));
    glEnd();
}