//
// Created by van den Brand on 09/07/2022.
//

#ifndef PONG_GAME_HANDLER_H
#define PONG_GAME_HANDLER_H

#include "../GameHandler.h"
#include "Player.h"
#include "Ball.h"
#include "PowerUps.h"
class PongGameHandler : public GameHandler {
public:
    PongGameHandler();

    void initialize() override;

    void addGameObject(auto* object);

    void update() override;

    void render() override;

private:
    Player player1;
    Player player2;
    Ball ball;
    PowerUps powerUp1;

};

#endif
