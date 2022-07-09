//
// Created by van den Brand on 09/07/2022.
//

#include "PongGameHandler.h"

void PongGameHandler::initialize() {
    player1.setHeight(0.1);
    player1.setWidth(0.1);
}

void PongGameHandler::update() {
    player1.updatePos(0.1, 0.1);
    ball.update();
}

void PongGameHandler::render() {
    player1.renderPlayer();
    ball.renderBall();
}

PongGameHandler::PongGameHandler() : player1(1), ball(0.01) {}
