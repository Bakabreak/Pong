//
// Created by Qiu Le Chen on 09-Jul-22.
//

#ifndef BALL_H
#define BALL_H
#include <list>
#include "Player.h"
class Ball {
public:
    float posX = 0;
    float posY = 0;
    float lastPosX = 0;
    float lastPosY = 0;
    float speed = 0.005;
    float angle = 0;
    float radius;
    float playerLine;

    explicit Ball(float ballRadius);

    void update();

    void setSpeed(float speed);

    void setAngle(float angle);

    void collisionCheck(std::list<Player>& playerList);

    void renderBall();
};

#endif
