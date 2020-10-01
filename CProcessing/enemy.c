#include "enemy.h"

void init_enemies(struct Enemy arr_enemy[], int count, float enemy_width, float enemy_height)
{
	for (int i = 0; i < count; i++)
	{
		//test enemy
		struct Enemy enemy = arr_enemy[i];
		enemy.pos = generate_random_pos();
		enemy.active = 1;
		enemy.hp.max = 100;
		enemy.hp.current = enemy.hp.max;

		enemy.collider.width = enemy_width;
		enemy.collider.height = enemy_height;

		arr_enemy[i] = enemy;

	}

}

void process_enemies(struct Enemy arr_enemy[], int count)
{
	for (int i = 0; i < count; i++)
	{
		struct Enemy* enemy = &arr_enemy[i];
		if (enemy->status.hit)
		{
			enemy->status.hit_cooldown -= CP_System_GetDt();
			if (enemy->status.hit_cooldown <= 0)
			{
				enemy->status.hit = 0;
				enemy->status.hit_cooldown = HURT_WINDOW;
			}
		}

		if (enemy->hp.current <= 0)
		{
			enemy->active = 0;
		}

	}
}

void draw_enemies(struct Enemy arr_enemy[], int count, CP_Image enemy_sprite, float enemy_width, float enemy_height, CP_Image enemy_hurt_sprite, CP_Image health_bar_sprite)
{
	for (int i = 0; i < count; i++)
	{
		struct Enemy enemy = arr_enemy[i];
		if (enemy.active)
		{
			CP_Image_Draw(enemy_sprite, enemy.pos.x, enemy.pos.y, enemy_width, enemy_height, 255);
			float percent = enemy.hp.current / enemy.hp.max;
			CP_Image_Draw(health_bar_sprite, enemy.pos.x, enemy.pos.y - 100, percent * BAR_WIDTH, BAR_HEIGHT, 255);

			if (enemy.status.hit)
			{
				CP_Image_Draw(enemy_hurt_sprite, enemy.pos.x, enemy.pos.y, enemy_width, enemy_height, 255);
			}
		}
	}
}
