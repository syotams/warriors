#include "Game.h"

void Game::loadTextures()
{
    char file1[] = "resources/knight/png/Idle (%d).png";
    std::array<Texture2D *, 2> textures = load_lr_animated_images(10, file1, TEXTURE_SIZE);
    textures_container_add_texture(&container, TexturesNames::Knight_Idle_Right, textures[0]);
    textures_container_add_texture(&container, TexturesNames::Knight_Idle_Left, textures[1]);

    char file2[] = "resources/knight/png/Run (%d).png";
    textures = load_lr_animated_images(10, file2, TEXTURE_SIZE);
    textures_container_add_texture(&container, TexturesNames::Knight_Run_Right, textures[0]);
    textures_container_add_texture(&container, TexturesNames::Knight_Run_Left, textures[1]);

    char file3[] = "resources/knight/png/Attack (%d).png";
    textures = load_lr_animated_images(10, file3, TEXTURE_SIZE);
    textures_container_add_texture(&container, TexturesNames::Knight_Attack_Right, textures[0]);
    textures_container_add_texture(&container, TexturesNames::Knight_Attack_Left, textures[1]);
}

void Game::nextLevel()
{
    setLevel(Level::make(&container, screenWidth, screenHeight));
}

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

Game *Game::make(int screenWidth, int screenHeight)
{
    Game *game = new Game(screenWidth, screenHeight);
    game->loadTextures();
    game->nextLevel();
    game->player = game->createPlayer();
    game->level->addConstrainOn(game->player);
    return game;
}

Knight *Game::createPlayer()
{
    Vector2 knightPosition({.x = (float)(screenWidth / 2), .y = (float)(screenHeight / 2)});
    Knight *knight = Knight::make(&container, knightPosition);
    knight->addConstrain(new SimpleConstrain(knight));
    return knight;
}

void Game::move()
{
    player->move();
    level->move();
    level->detectCollisions(player);
}

void Game::draw()
{
    level->draw();
    player->draw();
    // DrawText("Hello World", 20, 20, 20, BLACK);
}

void Game::setLevel(Level *level)
{
    this->level = level;
}

Game::~Game()
{
    log("Game::~Game() destructing player and level");
    textures_container_clear(&container, TexturesNames::Knight_Idle_Right, 10);
    textures_container_clear(&container, TexturesNames::Knight_Idle_Left, 10);
    textures_container_clear(&container, TexturesNames::Knight_Run_Right, 10);
    textures_container_clear(&container, TexturesNames::Knight_Run_Left, 10);
    textures_container_clear(&container, TexturesNames::Knight_Attack_Right, 10);
    textures_container_clear(&container, TexturesNames::Knight_Attack_Left, 10);
    delete player;
    delete level;
}