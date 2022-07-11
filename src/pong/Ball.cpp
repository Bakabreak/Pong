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
    int vertMax = 100;
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

void Ball::collisionAction(std::list<CollisionBox *> aPlayerList) {
    float rotLastPosX;
    float rotLastPosY;
    float pi = 3.141592654;
    float rotAngle;
    float cornerAngle;
    float normRotAngle;
    float relativeAngle;
    float distanceX;
    float distanceY;

    for (CollisionBox *item: aPlayerList) {
        distanceX = item->getWidth() / 2 + this->radius;
        distanceY = item->getHeight() / 2 + this->radius;

        item->transform(this->lastPosX, this->lastPosY, &rotLastPosX , &rotLastPosY);
        // Skip if already inside the collision box
        if (std::abs(rotLastPosX) <= distanceX &&
            std::abs(rotLastPosY) <= distanceY) {
            continue;
        }

        // Check if we are colliding
        if (item->collisionCheck(this->posX, this->posY, distanceX, distanceY)) {

            rotAngle = this->angle - item->getAngle();
            normRotAngle = std::fmod(std::fmod(rotAngle, 2 * pi) + 2 * pi, 2 * pi);

            if (normRotAngle >= 0 && normRotAngle <= 0.5 * pi) {
                cornerAngle = std::fmod(
                        std::atan2(-item->getHeight() / 2 - rotLastPosY, -item->getWidth() / 2 - rotLastPosX) + 2 * pi,
                        2 * pi);
                relativeAngle = std::fmod(cornerAngle - normRotAngle + 2 * pi, 2 * pi);
                if (relativeAngle > pi)
                    this->angle = (pi - rotAngle) + item->getAngle();
                else
                    this->angle = -rotAngle + item->getAngle();
            }
            if (normRotAngle > 0.5 * pi && normRotAngle <= pi) {
                cornerAngle = std::fmod(
                        std::atan2(-item->getHeight() / 2 - rotLastPosY, item->getWidth() / 2 - rotLastPosX) + 2 * pi,
                        2 * pi);
                relativeAngle = std::fmod(cornerAngle - normRotAngle + 2 * pi, 2 * pi);
                if (relativeAngle > pi)
                    this->angle = -rotAngle + item->getAngle();
                else
                    this->angle = pi - rotAngle + item->getAngle();
            }
            if (normRotAngle > pi && normRotAngle <= 1.5 * pi) {
                cornerAngle = std::fmod(
                        std::atan2(item->getHeight() / 2 - rotLastPosY, item->getWidth() / 2 - rotLastPosX) + 2 * pi,
                        2 * pi);
                relativeAngle = std::fmod(cornerAngle - normRotAngle + 2 * pi, 2 * pi);
                if (relativeAngle > pi)
                    this->angle = pi - rotAngle + item->getAngle();
                else
                    this->angle = -rotAngle + item->getAngle();
            }
            if (normRotAngle > 1.5 * pi && normRotAngle <= 2 * pi) {
                cornerAngle = std::fmod(
                        std::atan2(item->getHeight() / 2 - rotLastPosY, -item->getWidth() / 2 - rotLastPosX) + 2 * pi,
                        2 * pi);
                relativeAngle = std::fmod(cornerAngle - normRotAngle + 2 * pi, 2 * pi);
                if (relativeAngle > pi)
                    this->angle = -rotAngle + item->getAngle();
                else
                    this->angle = pi - rotAngle + item->getAngle();
            }
        }
    }
}

void Ball::boundaryCollisionCheck() {
    float pi = 3.141592654;
    if (std::abs(this->posX) >= 1) {
        this->angle = (pi - this->angle);
    }

    if (std::abs(this->posY) >= 0.6) {
        this->angle = -(this->angle);
    }
}
