//
// Created by Qiu Le Chen on 10-Jul-22.
//

#ifndef PONG_COLLISIONBOX_H
#define PONG_COLLISIONBOX_H

#include <tuple>

class CollisionBox {
protected:
    float posX;
    float posY;
    float width;
    float height;
    float angle;
public:
    float getPosX();

    float getPosY();

    float getAngle();

    float getWidth();

    float getHeight();

    bool collisionCheck(float posX, float posY, float distanceX, float distanceY);

    void transform(float posX, float posY, float* rotPosX, float* rotPosY);

};


#endif //PONG_COLLISIONBOX_H
