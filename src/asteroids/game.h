#pragma once
#include "cprocessing.h" //CProcessing Framework, used to Render sprites and perform game logic (e.g. Vectors)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Used to seed rand() function for random number generation.

typedef int DIFFICULTY;
enum DIFFICULTY_TYPE {EASY, NORMAL, HARD, INSANE, IMPOSSIBLE};

extern DIFFICULTY ASTEROIDS_GAME_DIFFICULTY;

void Asteroids_Init(void);
void Asteroids_Update(void);
void Asteroids_Exit(void);

void Asteroids_Check_Input();

void Asteroids_Draw();
void Asteroids_FPS_Draw();

void Asteroids_Debug();

void Asteroids_Sprites_Load();
void Asteroids_Entities_Init();

void Asteroids_Player_Rotate(CP_Vector direction);

void Asteroids_Cooldown_Update();

//Difficulty
void Asteroids_Set_Difficulty(DIFFICULTY difficulty);
void Asteroids_Difficulty_Update();
void Asteroids_Raise_Difficulty();