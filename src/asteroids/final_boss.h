#pragma once
#include "cprocessing.h"
#include "enemy.h"
#include "utility.h"
#include "player.h"
#include "bullet.h"
#include "Boss.h"
#include "score.h"

void Asteroids_Final_Boss_Init(void);
void Asteroids_Final_Boss_Update(Player* player, Enemy enemy_pool[], int enemy_count, Bullet bullet_pool[]);
void Asteroids_Enemy_Final_Boss_Spawn(void);
void Asteroids_Final_Boss_Draw(void);

void Asteroids_Final_Boss_Shoot(Enemy Final_Boss, Enemy enemy_pool[], Player* player);
void Asteroids_Final_Boss_Summon_Criteria_Check(void);


void Asteroids_Final_Boss_State_Update(Player* player, Enemy enemy_pool[], int enemy_count, Bullet bullet_pool[]);
void Asteroids_Final_Boss_State_CheckConditions();

void Asteroids_Final_Boss_State_Attack(void* context);
void Asteroids_Final_Boss_State_Idle(void* context);

void Asteroids_Final_Boss_State_Death(const void* context);
void Asteroid_Final_Boss_Reset();
