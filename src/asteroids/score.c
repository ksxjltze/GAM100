#include "score.h"


#define y 160.0f
#define x1 130.0f
#define x2 310.0f

#define textsize 40.0f

float time_counter;

void Asteroids_Init_Score(void)
{
	CURRENT_SCORE.Asteroid_Killed_Sprite = CP_Image_Load("./Assets/Asteroid_killed_sprite.png");
	CURRENT_SCORE.Time_Score_Sprite = CP_Image_Load("./Assets/Time_score_sprite.png");

	CURRENT_SCORE.enemy_kill_score = 0;
	CURRENT_SCORE.time_score = 0;
}
void Asteroids_Draw_Scores(void)
{
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	Asteroids_Time_Score_Manager();
	Asteroids_EnemyKill_Score_Manager();
}


void Asteroids_EnemyKill_Score_Manager(void)
{

	char kill_buffer[16];
	sprintf_s(kill_buffer, 16, ":%d", CURRENT_SCORE.enemy_kill_score);

	CP_Settings_TextSize(textsize);
	CP_Image_Draw(CURRENT_SCORE.Asteroid_Killed_Sprite, x2 - 60.0f, y, 50.0f, 50.0f, 255);
	CP_Font_DrawText(kill_buffer, x2, y);
}

void Asteroids_Time_Score_Manager(void)
{
	time_counter = CP_System_GetDt();
	CURRENT_SCORE.time_score += time_counter;

	char time_buffer[16];
	sprintf_s(time_buffer, 16, ":%.2f", CURRENT_SCORE.time_score);
	CP_Settings_TextSize(textsize);
	CP_Font_DrawText(time_buffer, x1, y);

	CP_Image_Draw(CURRENT_SCORE.Time_Score_Sprite, x1 - 90.0f, y, 50.0f, 50.0f, 255);
}