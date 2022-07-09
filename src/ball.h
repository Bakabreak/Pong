//
// Created by Qiu Le Chen on 09-Jul-22.
//
class Ball{
public:
    float posX = 0;
    float posY = 0;
    float speed = 0;
    float angle = 0;
    float radius;
    explicit Ball(float ballRadius);
    void update();
    void setSpeed(float speed);
    void setAngle(float angle);
    void renderBall();
};