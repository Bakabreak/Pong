//
// Created by van den Brand on 09/07/2022.
//

#include "PongGameHandler.h"
#include "../Input.h"
#include <list>
void PongGameHandler::initialize() {
    player1.setHeight(0.1);
    player1.setWidth(0.0133);
    player1.updatePos(-0.95, 0.1);

    player2.setHeight(0.1);
    player2.setWidth(0.0133);
    player2.updatePos(0.95, 0.1);

    std::list<Player> playerList;
    playerList.insert(playerList.end(),player1);
    playerList.insert(playerList.end(),player2);
}
void PongGameHandler::update() {
    ball.update();
    player1.update();
    player2.update();
}

void PongGameHandler::render() {
    player1.renderPlayer();
    player2.renderPlayer();
    ball.renderBall();
}


PongGameHandler::PongGameHandler() : player1(1, GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D),
                                     player2(2, GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT),
                                     ball(0.01) {}
