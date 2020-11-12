#include "collision_manager.h"
#include "collider_circle.h"
#include "powerups.h"
#include "powerup_interaction.h"

extern bool invulnerable;

Bullet Asteroids_Collision_CheckCollision_Enemy_Bullet(Enemy enemy_pool[], int enemy_count, Bullet bullet)
{
	for (int j = 0; j < enemy_count; j++)
	{
		if (!enemy_pool[j].active)
			continue;

		Enemy* enemy = &enemy_pool[j];
		if (Asteroids_Collision_CheckCollision_Circle(bullet.collider, bullet.pos, enemy->collider, enemy->pos))
		{
			bullet.active = 0;
			bullet.pos = CP_Vector_Set(-1, -1);
			bullet.velocity = CP_Vector_Set(0, 0);

			if (!enemy->status.hit)
			{
				enemy->status.hit = 1;
				enemy->hp.current -= BULLET_DAMAGE;
			}

			return bullet;
		}
	}
	return bullet;
}

void Asteroids_Collision_CheckCollision_Enemy_Player(Enemy enemy_pool[], int enemy_count, Player* player)
{
	for (int i = 0; i < enemy_count; i++)
	{
		if (!enemy_pool[i].active)
			continue;

		Enemy* enemy = &enemy_pool[i];

			if (Asteroids_Collision_CheckCollision_Circle(enemy->collider, enemy->pos, player->collider, player->pos))
			{
				if (!invulnerable)
				{
					Asteroids_Player_Hit(player, enemy->size);
				}
				Asteroids_Enemy_Death(enemy);
				return;
			}

	}
}

void Asteroids_Collision_CheckCollision_Enemy_Enemy(Enemy enemy_pool[], int enemy_count, Enemy* enemy, Player player)
{
	for (int i = 0; i < enemy_count; i++)
	{
		if (enemy_pool[i].active)
		{
			if (enemy_pool[i].id == enemy->id)
				continue;
			else if (Asteroids_Collision_CheckCollision_Circle(enemy_pool[i].collider, enemy_pool[i].pos, enemy->collider, enemy->pos))
			{
				Asteroids_Enemy_Collide(&enemy_pool[i], enemy, enemy_pool, enemy_count, player);
				return;
			}

		}

	}
}
