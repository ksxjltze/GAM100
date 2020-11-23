#pragma once
#include "game.h"
#include "collider_circle.h"
#include <stdbool.h>
#include "sprite.h"

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
	bool loop;

}Particle;

void particle_init();
void explosion_init(void);
void smoke_init(void);

void draw_explosion(void);

void spawn_explosion_anim(CP_Vector position, float size);

void particle_update(void);

void Spawn_Particle(CP_Vector position, int particles, float min_velocity, float max_velocity, float size, Sprite sprite);

void particle_despawning(Particle* particle);
