#pragma once

#define NUM_UPGRADES 10
enum UpgradeType {NONE, FUEL_CAPACITY, MAX_HEALTH, BULLET_DMG};

typedef struct Upgrades
{
	const char* name;
	int cost;
	unsigned int id;
	unsigned int level;
}Upgrade;

void Asteroids_Upgrades_Init(void);
Upgrade Asteroids_Upgrades_Initialize_Upgrade(unsigned int id, int cost, const char* name);
void Asteroids_Upgrades_Create_Upgrade(unsigned int id, int cost, const char* name);
void Asteroids_Upgrades_Add_Upgrade(Upgrade upgrade);
Upgrade Asteroids_Upgrades_Get_Upgrade(unsigned int id);
void Asteroids_Upgrade_Add_Level(unsigned int id);
void Asteroids_Upgrades_Save_All_To_File(void);
void Asteroids_Upgrades_Read_From_File(void);
void Asteroids_Upgrades_Set_Upgrade_Name(Upgrade* upgrade);