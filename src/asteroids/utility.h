#include <stdlib.h>
#include <stdbool.h>
#include "cprocessing.h"
#include "constants.h"
#define getVarName(name) #name

CP_Vector Asteroids_Utility_Generate_Random_Pos();
CP_Vector Asteroids_Utility_GetWindowMiddle();
void Asteroids_Utility_Generate_Hurt_Sprite(CP_Image sprite, CP_Image* out);
bool isMouseOver_Rect(CP_Vector position, float width, float height, float mouseX, float mouseY);
bool Asteroids_Utility_isInWindow(CP_Vector position);
void Asteroids_Utility_Move_Object_To_Mouse(CP_Vector* position);
void Asteroids_Utility_Move_Object_To_Mouse_Stationary(CP_Vector* position, CP_Vector* velocity);