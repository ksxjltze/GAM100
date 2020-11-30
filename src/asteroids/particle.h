#pragma once
#include "game.h"
#include "collider_circle.h"
#include <stdbool.h>
#include "sprite.h"
#include "enemy.h"

typedef struct Particles
{
	Sprite sprite;
	CP_Vector velocity;
	float posX;
	float posY;
	int enabled;
	float lifetime;
	float life;
	float size;
	int id;
	bool loop;

}Particle;

void particle_init();
void explosion_init(void);
void smoke_init(void);

void spawn_explosion_anim(CP_Vector position, float size);
void spawn_smoke_trail_anim(CP_Vector position, float size);

void particle_update(void);
void draw_particle();

Particle* Spawn_Particle(CP_Vector position, int particles, float min_velocity, float max_velocity, float size, Sprite sprite, int type, bool loop);

void smoke_velocity(CP_Vector position, int particles, float min_velocity, float max_velocity, float size);

void particle_despawning(Particle* particle);

void smoke_update(CP_Vector rotation, CP_Vector playerPos);
