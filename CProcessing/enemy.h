#pragma once
#include "cprocessing.h"
#include "health.h"
#include "collider_aabb.h"
#include "status.h"
#include "constants.h"
#include "utility.h"

struct Enemy {
	CP_Vector pos;
	struct Health hp;
	struct Collider_AABB collider;
	int active;
	struct Status status;
};

void init_enemies(struct Enemy arr_enemy[], int count, float enemy_width, float enemy_height);
void process_enemies(struct Enemy arr_enemy[], int count);
void draw_enemies(struct Enemy arr_enemy[], int count, CP_Image enemy_sprite, float enemy_width, float enemy_height, CP_Image enemy_hurt_sprite, CP_Image health_bar_sprite);
void debug_enemies(struct Enemy arr_enemy[], int count);