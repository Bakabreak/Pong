//
// Created by Qiu Le Chen on 09-Jul-22.
//

#ifndef BALL_H
#define BALL_H

#include <list>
#include "Player.h"
#include "Renderable.h"

class Ball : public CollisionBox, public Renderable{
public:
    float lastPosX = 0;
    float lastPosY = 0;
    float speed = 0.008;
    float radius;

    explicit Ball(float ballRadius);

    Ball clone();

    void setRadius(float ballRadius);

    void update();

    void setSpeed(float speed);

    void setAngle(float angle);

    void collisionAction(std::list<CollisionBox *> playerList);

    void boundaryCollisionCheck();

    void render() override;
};

#endif
