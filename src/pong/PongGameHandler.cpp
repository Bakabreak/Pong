//
// Created by van den Brand on 09/07/2022.
//

#include "PongGameHandler.h"
#include "../Input.h"
#include <list>

std::list<CollisionBox *> playerList;

void PongGameHandler::initialize() {
    player1.setHeight(0.1);
    player1.setWidth(0.0133);
    player1.updatePos(-0.95, 0.1);
    player1.setAngle(0);

    player2.setHeight(0.1);
    player2.setWidth(0.0133);
    player2.updatePos(0.95, 0.1);
    player2.setAngle(0);

//    player3.setHeight(0.1);
//    player3.setWidth(0.0133);
//    player3.updatePos(0.1, 0.55);
//    player3.setAngle(0.5*pi);
//
//    player4.setHeight(0.1);
//    player4.setWidth(0.0133);
//    player4.updatePos(0.1, 0.55);
//    player4.setAngle(0.5*pi);

    playerList.insert(playerList.end(), &player1);
    playerList.insert(playerList.end(), &player2);
}

void PongGameHandler::update() {
    player1.update();
    player2.update();
    ball.update();
    ball.collisionAction(playerList);
    ball.boundaryCollisionCheck();
}

void PongGameHandler::render() {
    player1.renderPlayer();
    player2.renderPlayer();
    ball.renderBall();
}


PongGameHandler::PongGameHandler() : player1(1, GLFW_KEY_W, GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D),
                                     player2(2, GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT),
                                     ball(0.5) {}
