//---------------------------------------------------------
// file:	bullet.c
// author:	Lee Jia Keat
// contributors: Liu Ke (Initial code for Asteroid Splitting)
//				 Bryan (Bullet splitting implementation)
// email:	l.jiakeat@digipen.edu, 
//
// brief:	Bullet entity source file.
//			Handles Initialization, Updating and Drawing
//			of a specified pool (static array) of bullet entities.
//			Provides an interface for spawning (firing) bullets.
//			Contains implementation of multishot (split bullets) powerup.
//
// Copyright  2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "bullet.h"
#include "collision_manager.h"
#include "collider_aabb.h"
#include "collider_circle.h"
#include "constants.h"
#include "powerups.h"
#include "powerup_interaction.h"

extern bool bullet_split;
extern bool BPM;

void Asteroids_Bullet_Init(Bullet bullets[], int count, float bullet_width, float bullet_height)
{
	for (int i = 0; i < count; i++)
	{
		Bullet bullet = bullets[i];
		bullet.active = 0;
		bullet.pos = CP_Vector_Set(-1, -1);
		bullet.velocity = CP_Vector_Set(0, 0);
		bullet.id = i;

		bullet.collider.diameter = (bullet_width + bullet_height) / 2;

		bullets[i] = bullet;
	}
}

void Asteroids_Bullet_Update(Bullet arr_bullet[], int bullet_count, Enemy enemy_pool[], int enemy_count, Player player)
{
	//bullet
	for (int i = 0; i < bullet_count; i++)
	{
		Bullet bullet = arr_bullet[i];
		if (bullet.active)
		{
			if ((bullet.pos.x > CP_System_GetWindowWidth() || bullet.pos.x < 0) && (bullet.pos.y > CP_System_GetWindowHeight() || bullet.pos.y < 0))
			{
				bullet.active = 0;
				bullet.pos = CP_Vector_Set(-1, -1);
				bullet.velocity = CP_Vector_Set(0, 0);
				bullet.rotation = 0;

				arr_bullet[i] = bullet;
				continue;
			}

			bullet = Asteroids_Collision_CheckCollision_Enemy_Bullet(enemy_pool, enemy_count, bullet, player);

			bullet.pos = CP_Vector_Add(bullet.pos, CP_Vector_Scale(bullet.velocity, CP_System_GetDt()));
			arr_bullet[i] = bullet;
		}

	}
}

void Asteroids_Bullet_Draw(Bullet arr_bullet[], int count, CP_Image bullet_sprite, float bullet_width, float bullet_height)
{
	//Render Bullets
	for (int i = 0; i < count; i++)
	{
		Bullet bullet = arr_bullet[i];
		if (bullet.active) {
			CP_Image_DrawAdvanced(bullet_sprite, bullet.pos.x, bullet.pos.y, bullet_width, bullet_height, 255, bullet.rotation);
		}
	}
}

void Asteroids_Bullet_Debug(Bullet arr_bullet[], int count)
{
	for (int i = 0; i < count; i++)
	{
		Bullet bullet = arr_bullet[i];
		if (bullet.active)
		{
			//Asteroids_Collision_Debug_AABB_Draw(enemy.collider, enemy.pos);
			Asteroids_Collision_Debug_Circle_Draw(bullet.collider, bullet.pos);
		}

	}
}

void Asteroids_Bullet_Spawn(Bullet bullets[], int count, Player player, CP_Vector shoot_direction)
{
	CP_Vector right = CP_Vector_Set(1, 0);
	CP_Vector up = CP_Vector_Set(0, 1);

	float rotate = CP_Vector_Angle(shoot_direction, right);
	if (CP_Vector_DotProduct(shoot_direction, up) < 0)
		rotate = -rotate;

	for (int i = 0; i < count; i++)
	{
		Bullet bullet = bullets[i];
		if (!bullet.active)
		{
			bullet.pos = CP_Vector_Set(player.pos.x, player.pos.y);
			bullet.rotation = rotate;

			if (BPM) // if powerup bpm
			{
				bullet.velocity = CP_Vector_Set(shoot_direction.x * player.weapon.projectile_speed * ASTEROIDS_POWERUP_INCREASE_FIRERATE_VALUE, shoot_direction.y * player.weapon.projectile_speed * 2);
			}
			else
				bullet.velocity = CP_Vector_Set(shoot_direction.x * player.weapon.projectile_speed, shoot_direction.y * player.weapon.projectile_speed);
			bullet.active = 1;

			bullets[i] = bullet;
			break;
		}
	}
}

void Asteroids_Bullet_Powerup_Split(Bullet bullets[], int count, Player player, CP_Vector shoot_direction)
{
	if (!bullet_split)
		return;

	CP_Matrix Rotate1 = CP_Matrix_Rotate(ASTEROIDS_POWERUP_BULLET_SPLIT_ANGLE);
	CP_Matrix Rotate2 = CP_Matrix_Rotate(-ASTEROIDS_POWERUP_BULLET_SPLIT_ANGLE);

	CP_Vector split_1 = shoot_direction;
	CP_Vector split_2 = shoot_direction;

	split_1 = CP_Vector_MatrixMultiply(Rotate1, split_1);
	split_2 = CP_Vector_MatrixMultiply(Rotate2, split_2);

	Asteroids_Bullet_Spawn(bullets, count, player, split_1);
	Asteroids_Bullet_Spawn(bullets, count, player, split_2);
}

void Asteroids_Bullet_Split(Bullet bullets[], int pool_size, int bullet_count, float angle, Player player, CP_Vector shoot_direction)
{
	for (int i = 0; i < bullet_count; i++)
	{
		CP_Vector split = shoot_direction;
		CP_Matrix rotate = CP_Matrix_Rotate((-angle * ((float)bullet_count / 2) + angle * i));
		split = CP_Vector_MatrixMultiply(rotate, split);
		Asteroids_Bullet_Spawn(bullets, pool_size, player, split);
	}

}