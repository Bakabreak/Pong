//
// Created by Qiu Le Chen on 09-Jul-22.
//

#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
    float posX;
    float posY;
    int playerId;
    float width;
    float height;
    explicit Player(int playerId);
    void setWidth(float width);
    void setHeight(float height);
    float getPosX();
    float getPosY();
    void updatePos(float xNew, float yNew);
    void renderPlayer();
};

#endif
