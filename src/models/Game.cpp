#include "Game.h"

void Game::loadTextures()
{
    char file[] = "resources/knight/png/Idle (%d).png";
    std::array<Texture2D *, 2> textures = load_lr_animated_images(10, file, TEXTURE_SIZE);
    textures_container_add_texture(&container, TexturesNames::Knight_Idle_Right, textures[0]);
    textures_container_add_texture(&container, TexturesNames::Knight_Idle_Left, textures[1]);
}

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

Game *Game::make(int screenWidth, int screenHeight)
{
    Game *game = new Game(screenWidth, screenHeight);
    game->setLevel(Level::make(screenWidth, screenHeight));
    game->loadTextures();
    game->player = game->createPlayer();
    return game;
}

Knight *Game::createPlayer()
{
    Vector2 knightPosition({.x = (float)(screenWidth / 2), .y = (float)(screenHeight / 2)});
    return Knight::make(&container, knightPosition);
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
    textures_container_clear(&container, TexturesNames::Knight_Idle_Right, 10);
    delete player;
    delete level;
}