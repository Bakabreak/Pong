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

Ball PowerUps::multiply(Ball ball) {
    return ball.clone();
}

void PowerUps::accelerate(CollisionBox object) {}

void PowerUps::render() {
    int vertMax = 2;
    float vertAngle = 0;
    float pi = 3.141592654;

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (int i = 0; i < vertMax; i++) {
        glVertex2d(this->posX + cos(vertAngle) * this->width / 2,
                   this->posY + sin(vertAngle + pi / 2) * this->height / 2);
        glVertex2d(this->posX + cos(vertAngle) * this->width / 2,
                   this->posY - sin(vertAngle + pi / 2) * this->height / 2);
        vertAngle += 2 * pi / vertMax;
    }
    glEnd();
}

bool PowerUps::update(std::list<Ball *>* ballList, std::list<CollisionBox *>* collisionBoxList, std::list<Renderable *>* renderList){
    float distanceX;
    float distanceY;
    for (Ball *item: *ballList) {
        distanceX = this->getWidth() / 2 + item->radius;
        distanceY = this->getHeight() / 2 + item->radius;
        if(item->collisionCheck(this->posX, this->posY, distanceX, distanceY)){
            Ball ball2 = this->multiply(*item);
            ballList->insert(ballList->end(),&ball2);
            collisionBoxList->insert(collisionBoxList->end(),&ball2);
            renderList->insert(renderList->end(),&ball2);
            return true;
        }

    }
    return false;
}
