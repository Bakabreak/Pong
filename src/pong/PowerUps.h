//
// Created by Qiu Le Chen on 11-Jul-22.
//

#ifndef PONG_POWERUPS_H
#define PONG_POWERUPS_H
#include "CollisionBox.h"
#include "Ball.h"

class PowerUps : public CollisionBox, public Renderable{

public:
    float color;
    int mode;

    explicit PowerUps(float width, float height);

    void setPos(float xPos, float yPos);

    void expand(Ball *ball);

    Ball multiply(Ball ball);

    void collisionAction(auto* object);

    void accelerate(CollisionBox object);

    void curve(CollisionBox object);

    void shrink(CollisionBox object);

    void render() override;

    bool update(std::list<Ball *>* ballList, std::list<CollisionBox *>* collisionBoxList, std::list<Renderable *>* renderList);
};


#endif //PONG_POWERUPS_H
