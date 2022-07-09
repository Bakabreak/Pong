//
// Created by Qiu Le Chen on 09-Jul-22.
//
#include "GLFW/glfw3.h"
#include <cmath>
#include "player.h"
#include "ball.h"
using namespace std;

Player player1(1);
Ball ball(0.01);

void initialize(){
    player1.setHeight(0.1);
    player1.setWidth(0.1);
}

void update(){
    player1.updatePos(0.1,0.1);
    ball.update();
}

void render(){
    player1.renderPlayer();
    ball.renderBall();
}
