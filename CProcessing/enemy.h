#pragma once
#include "cprocessing.h"
#include "health.h"
#include "collider_aabb.h"
#include "status.h"

struct Enemy {
	CP_Vector pos;
	struct Health hp;
	struct Collider_AABB collider;
	int active;
	struct Status status;
};