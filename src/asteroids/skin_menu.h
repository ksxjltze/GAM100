#pragma once
#include "cprocessing.h"

typedef struct Skins
{
	CP_Image sprite;
	const char* name;
	float cost;
}Skin;

extern Skin current_skin;

void Asteroids_Skin_Menu_Init(void);
void Asteroids_Skin_Menu_Update(void);
void Asteroids_Skin_Menu_Draw(void);
void Asteroids_Skin_Menu_Load_Skin(const char* path, const char* skin_name, float cost);
void Asteroids_Skin_Menu_Load_Default(void);
void Asteroids_Skin_Menu_Next_Skin(void);
