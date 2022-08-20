//
// Created by Qiu Le Chen on 11-Jul-22.
//

#ifndef PONG_POWERUPS_H
#define PONG_POWERUPS_H


class PowerUps {
    void expand();

    void multiply();

    void accelerate();

    void curve();

    void shrink();

    void accelerate(CollisionBox object);

    void curve(CollisionBox object);

    void shrink(CollisionBox object);

    void render() override;

    bool update(std::list<Ball *>* ballList, std::list<CollisionBox *>* collisionBoxList, std::list<Renderable *>* renderList);
};


#endif //PONG_POWERUPS_H
