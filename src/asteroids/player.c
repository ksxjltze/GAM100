#include "player.h"
#include "constants.h"

struct Player init_player(float player_width, float player_height)
{
	struct Player player;
	player.active = 1;
	player.pos = CP_Vector_Set((float)WIN_WIDTH / 2, (float)WIN_HEIGHT / 2);

	player.collider.diameter = (player_width + player_height) / 2;

	player.hp.max = PLAYER_MAX_HP;
	player.hp.current = player.hp.max;
	player.speed = (float) SPEED;

	player.engine.fuel.current = PLAYER_MAX_FUEL;
	player.engine.fuel.max = player.engine.fuel.current;

	player.engine.drain_rate = DRAIN_RATE;
	return player;
}

void draw_player(CP_Image player_sprite, CP_Vector pos, float player_width, float player_height, float player_rotation)
{
	CP_Image_DrawAdvanced(player_sprite, pos.x, pos.y, player_width, player_height, 255, player_rotation);

}

void debug_player(struct Player player)
{
	//debug_draw_collider_rect(player.collider, player.pos);
	debug_draw_collider_circle(player.collider, player.pos);
}

void player_wrap(CP_Image player_sprite, CP_Vector pos, float player_width, float player_height, float player_rotation)
{
	if (pos.x > WIN_WIDTH - player_width / 2) //x-max
	{
		float new_x = 0 - (WIN_WIDTH - pos.x);
		CP_Image_DrawAdvanced(player_sprite, new_x, pos.y, player_width, player_height, 255, player_rotation);
		if (pos.x > WIN_WIDTH)
			pos.x = 0;
	}
	else if (pos.x < 0 + player_width / 2) //x-min
	{
		float new_x = WIN_WIDTH + pos.x;
		CP_Image_DrawAdvanced(player_sprite, new_x, pos.y, player_width, player_height, 255, player_rotation);
		if (pos.x <= 0)
			pos.x = (float)WIN_WIDTH;
	}

	if (pos.y > WIN_HEIGHT - player_height / 2) //y-max
	{
		float new_y = 0 - (WIN_HEIGHT - pos.y);
		CP_Image_DrawAdvanced(player_sprite, pos.x, new_y, player_width, player_height, 255, player_rotation);
		if (pos.y > WIN_HEIGHT)
			pos.y = 0;
	}
	else if (pos.y < 0 + player_height / 2) //y-min
	{
		float new_y = WIN_HEIGHT + pos.y;
		CP_Image_DrawAdvanced(player_sprite, pos.x, new_y, player_width, player_height, 255, player_rotation);
		if (pos.y <= 0)
			pos.y = (float)WIN_HEIGHT;
	}

	if (pos.x > WIN_WIDTH - player_width / 2 && pos.y > WIN_HEIGHT - player_height / 2) //x-max && y-max
	{
		float new_x = 0 - (WIN_WIDTH - pos.x);
		float new_y = 0 - (WIN_HEIGHT - pos.y);
		CP_Image_DrawAdvanced(player_sprite, new_x, new_y, player_width, player_height, 255, player_rotation);
	}
	else if (pos.x > WIN_WIDTH - player_width / 2 && pos.y < 0 + player_height / 2) //x-max && y-min
	{
		float new_x = 0 - (WIN_WIDTH - pos.x);
		float new_y = WIN_HEIGHT + pos.y;
		CP_Image_DrawAdvanced(player_sprite, new_x, new_y, player_width, player_height, 255, player_rotation);
	}
	else if (pos.x < 0 + player_width / 2 && pos.y > WIN_HEIGHT - player_height / 2) //x-min && y-max
	{
		float new_x = WIN_WIDTH + pos.x;
		float new_y = 0 - (WIN_HEIGHT - pos.y);
		CP_Image_DrawAdvanced(player_sprite, new_x, new_y, player_width, player_height, 255, player_rotation);
	}
	else if (pos.x < 0 + player_width / 2 && pos.y < 0 + player_height / 2) //x-min && y-min
	{
		float new_x = WIN_WIDTH + pos.x;
		float new_y = WIN_HEIGHT + pos.y;
		CP_Image_DrawAdvanced(player_sprite, new_x, new_y, player_width, player_height, 255, player_rotation);
	}
}

void update_player(struct Player* player)
{
	calculate_fuel(player);
	if (player->status.hit)
	{
		player->status.hit_cooldown -= CP_System_GetDt();
		if (player->status.hit_cooldown <= 0)
		{
			player->status.hit = 0;
			player->status.hit_cooldown = HURT_WINDOW;
		}
	}

	if (player->hp.current <= 0)
	{
		player->active = 0;
	}

}

void calculate_fuel(struct Player* player)
{
	//temp
	if (player->engine.fuel.current <= 0)
	{
		player->engine.fuel.current = 0.0f;
		player->speed = 1;
		//if(player->active)
		//	player->active = 0;

		return;
	}

	player->engine.fuel.current -= player->engine.drain_rate * CP_System_GetDt();

}