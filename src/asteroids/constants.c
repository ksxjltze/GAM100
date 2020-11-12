#include "constants.h"
const float SPLASH_DURATION = 3.0f;

const float MAX_VELOCITY = 10.0f; //pixels per second
const float SPEED = 200.0f;
const float ASTEROIDS_PLAYER_SLOWED_SPEED = 20.0f;

const int BULLET_SPEED = 1000;
const float FIRE_RATE = 600.0f; //bullets per minute
const float HURT_WINDOW = 0.1f; //seconds
const float BULLET_DAMAGE = 1;

const float ASTEROID_MIN_SPEED = 50.0f;
const float ASTEROID_MAX_SPEED = 200.0f; //pixels per second
const int ASTEROIDS_PLAYER_SIMPLE_SPEED = 10;

const float ASTEROIDS_ENEMY_SIZE_MIN = 1.0f;
const float ASTEROIDS_ENEMY_SIZE_MAX = 5.0f;
const int ASTEROIDS_ENEMY_BASE_DIAMETER = 32;

const int ASTEROIDS_ENEMY_SPLIT_MAX_COUNT = 3;
const int ASTEROIDS_ENEMY_SPLIT_MIN_NUMBER = 2;
const int ASTEROIDS_ENEMY_SPLIT_MAX_NUMBER = 5;

const float ASTEROIDS_ENEMY_IDLE_ROTATE_RATE_MIN = -60.0f;
const float ASTEROIDS_ENEMY_IDLE_ROTATE_RATE_MAX = 60.0f;

const float ASTEROIDS_ASTEROID_ENEMY_VELOCITY_OFFSET = 300.0f;
const float ASTEROIDS_ENEMY_SPAWN_OFFSET = 300.0f;

const int ASTEROIDS_ASTEROID_ENEMY_SPAWN_COUNT_MIN = 5;
const int ASTEROIDS_ASTEROID_ENEMY_SPAWN_COUNT_MAX = 15;
const int ASTEROIDS_ASTEROID_ENEMYSPLIT_SPAWN_COUNT_MIN = 2;
const int ASTEROIDS_ASTEROID_ENEMYSPLIT_SPAWN_COUNT_MAX = 3;

const float ASTEROIDS_ASTEROID_ENEMY_BASE_DAMAGE = 2.0f;

//health bar
const float ASTEROIDS_UI_PLAYER_HEALTH_BAR_WIDTH = 300.0f;

const float PLAYER_MAX_HP = 100;
const float PLAYER_MAX_FUEL = 100.0f;
const float DRAIN_RATE = 5.0f;

const CP_KEY ASTEROIDS_PAUSE_KEY = KEY_ESCAPE;
const float ASTEROIDS_ENEMY_BASE_MAX_HP = 3.0f;
const float ASTEROIDS_ENEMY_BASE_SPAWN_INTERVAL = 2.0f;

const char* PLAYER_SPRITE_PATH = "./Assets/spaceship1.png";
const char* ASTEROIDS_HEART_SPRITE_PATH = "./Assets/heart.png";
const char* ASTEROIDS_ERROR_STR_MISSING_SPRITE = "ERROR - Missing Sprite";
const float ASTEROIDS_DIFFICULTY_INTERVAL = 60.0f;