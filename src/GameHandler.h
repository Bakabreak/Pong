//
// Created by van den Brand on 09/07/2022.
//

#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

class GameHandler {
public:
    /**
     * Handles any setup needed before the game begins.
     */
    virtual void initialize() = 0;

    /**
     * Handles any setup needed before the game begins.
     */
    virtual void update() = 0;

    /**
     * Handles any setup needed before the game begins.
     */
    virtual void render() = 0;

    /**
     * Called when a key is pressed down.
     * @param keyCode code of the pressed key
     */
    virtual void onKeyDown(int keyCode) {};

    /**
     * Called when a key is released.
     * @param keyCode code of the released key
     */
    virtual void onKeyUp(int keyCode) {};
};

#endif
