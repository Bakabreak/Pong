//
// Created by Qiu Le Chen on 09-Jul-22.
//

#include "ball.h"
#include <GLFW/glfw3.h>
#include <cmath>

Ball::Ball(float ballRadius) {
    this->radius = ballRadius;
}

void Ball::update() {
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
