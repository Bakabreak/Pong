//
// Created by Qiu Le Chen on 09-Jul-22.
//

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    float posX;
    float posY;
    float angle = 0;
    int playerId;
    float width;
    float height;
    float speed = 0.01;
    float rotSpeed = 0.1;
    int keyUp;
    int keyDown;
    int keyLeft;
    int keyRight;


    explicit Player(int playerId, int keyUp, int keyDown, int keyLeft, int keyRight);

    void setWidth(float width);

    void setHeight(float height);

    float getPosX();

    float getPosY();

    void update();

    void turnRight();

    void turnLeft();

    void moveUp();

    void moveDown();

    void updatePos(float xNew, float yNew);

    void renderPlayer();
};

#endif
