//
// Created by Qiu Le Chen on 09-Jul-22.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "CollisionBox.h"
#include "Renderable.h"

class Player : public CollisionBox, public Renderable{

public:
    int playerId;
    float speed = 0.01;
    float rotSpeed = 0.01;
    int keyUp;
    int keyDown;
    int keyLeft;
    int keyRight;


    explicit Player(int playerId, int keyUp, int keyDown, int keyLeft, int keyRight);

    void setWidth(float width);

    void setHeight(float height);

    float getPosX();

    float getPosY();

    float getAngle();

    void setAngle(float angle);

    void update();

    void turnRight();

    void turnLeft();

    void moveUp();

    void moveDown();

    void updatePos(float xNew, float yNew);

    void render() override;

};

#endif
