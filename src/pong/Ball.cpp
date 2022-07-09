//
// Created by Qiu Le Chen on 09-Jul-22.
//

#include "Ball.h"
#include "Player.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <list>

Ball::Ball(float ballRadius) {
    this->radius = ballRadius;
}

void Ball::update() {
    this->lastPosX = this->posX;
    this->lastPosY = this->posY;
    this->posX += this->speed * std::cos(this->angle);
    this->posY += this->speed * std::sin(this->angle);
}

void Ball::setSpeed(float aSpeed) {
    this->speed = aSpeed;
}

void Ball::setAngle(float aAngle) {
    this->angle = aAngle;
}

void Ball::renderBall() {
    int vertMax = 20;
    float vertAngle = 0;
    float pi = 3.141592654;

    glBegin(GL_POLYGON);
    for (int i = 0; i < vertMax; i++) {
        glColor3f(1, 1, 1);
        glVertex2d(this->posX + this->radius * std::cos(vertAngle), this->posY + this->radius * std::sin(vertAngle));
        vertAngle += 2 * pi / vertMax;
    }
    glEnd();
}

//void Ball::collisionCheck(std::list<Player>& aPlayerList){
//    for (const auto &item: aPlayerList){
//        this->playerLine = item
//        if(std::sqrtf(std::powf(this->posY - item.posY,2) + std::powf(this->posX - item.posX,2)) < ;
//
//    }
//}