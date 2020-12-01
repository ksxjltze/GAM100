//---------------------------------------------------------
// file:	weapon.h
// author:	Lee Jia Keat
// email:	l.jiakeat@digipen.edu
//
// brief:	Weapon data header file.
//			Provides the Weapon struct and types.
// Copyright  2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#pragma once
#include <stdbool.h>

enum WeaponType {RAILGUN, LASER};

typedef struct Weapons
{
	int id;
	float damage;
	float fire_rate;
	float projectile_speed;
	bool isPiercing;
} Weapon;