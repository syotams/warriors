#include "Game.h"


Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

Game *Game::make(int screenWidth, int screenHeight)
{
    Game *game = new Game(screenWidth, screenHeight);
    game->setLevel(Level::make(screenWidth, screenHeight));
    Vector2 knightPosition({.x = (float)(screenWidth / 2), .y = (float)(screenHeight / 2)});
    game->player = Knight::make(knightPosition);
    return game;
}

void Game::move()
{
    level->move();
    player->move();
}

void Game::draw()
{
    level->draw();
    player->draw();
}

void Game::setLevel(Level *level)
{
    this->level = level;
}

Game::~Game()
{
    log("Game::~Game() destructing player and level");
    delete player;
    delete level;
}