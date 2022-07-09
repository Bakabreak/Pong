//
// Created by van den Brand on 09/07/2022.
//

#ifndef PONG_GAME_HANDLER_H
#define PONG_GAME_HANDLER_H

#include "GameHandler.h"
#include "player.h"
#include "ball.h"

class PongGameHandler : public GameHandler {
public:
    PongGameHandler();

    void initialize() override;

    void update() override;

    void render() override;

private:
    Player player1;
    Ball ball;
};

#endif
