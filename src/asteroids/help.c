#include "help.h"
#include "utility.h"
#include "button.h"
#include "main_menu.h"
#include "audio_manager.h"
#include <string.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 150
#define BTN_TEXTSIZE 75

Help_screen screen;
#define FIRST_PAGE 0
#define LAST_PAGE 4

CP_Image Page_Image[LAST_PAGE];

Button BackBtn, NextBtn, ExitBtn;

void Asteroids_Help_Screen_Init(void)
{
	for (int i = 0; i < LAST_PAGE; i++)
	{
		char path[100];
		sprintf_s(path, 100, "./Assets/Control_screen%d.png", i);
		Page_Image[i] = CP_Image_Load(path);
	}

	screen.id = FIRST_PAGE;

	Asteroids_Audio_Manager_Init();

	screen.width = (float)CP_System_GetWindowWidth();
	screen.height = (float)CP_System_GetWindowHeight();
	screen.pos = Asteroids_Utility_GetWindowMiddle();
	screen.Image = Page_Image[screen.id];

	BackBtn = Asteroids_Button_Add_New_Button(BUTTON_WIDTH, BUTTON_HEIGHT);
	NextBtn = Asteroids_Button_Add_New_Button(BUTTON_WIDTH, BUTTON_HEIGHT);
	ExitBtn = Asteroids_Button_Add_New_Button(BUTTON_WIDTH, BUTTON_HEIGHT);

	Asteroids_Button_Set_Text(&BackBtn, BTN_TEXTSIZE, "Back");
	Asteroids_Button_Set_Text(&NextBtn, BTN_TEXTSIZE, "Next");
	Asteroids_Button_Set_Text(&ExitBtn, BTN_TEXTSIZE, "Exit");

	CP_Vector position_offset = Asteroids_Utility_GetWindowMiddle();

	CP_Vector ExitBtnPos = CP_Vector_Set(position_offset.x - BUTTON_WIDTH / 2, (float)WIN_HEIGHT - BUTTON_HEIGHT);
	CP_Vector BackBtnPos = CP_Vector_Set(0, position_offset.y - BUTTON_HEIGHT / 2);
	CP_Vector NextBtnPos = CP_Vector_Set((float)WIN_WIDTH - BUTTON_WIDTH, position_offset.y - BUTTON_HEIGHT / 2);

	Asteroids_Button_Set_Position(&BackBtn, BackBtnPos);
	Asteroids_Button_Set_Position(&NextBtn, NextBtnPos);
	Asteroids_Button_Set_Position(&ExitBtn, ExitBtnPos);

	Asteroids_Button_Set_Callback_Void(&Asteroids_Help_Screen_Exit_ToMenu, &ExitBtn);
	Asteroids_Button_Set_Callback_Void(&Asteroids_Help_Screen_IncreasePageNo, &NextBtn);
	Asteroids_Button_Set_Callback_Void(&Asteroids_Help_Screen_DecreasePageNo, &BackBtn);

}
void Asteroids_Help_Screen_Update(void)
{
	Asteroids_Draw_Screen_Page();
	Asteroids_Button_Update(&ExitBtn);
}
void Asteroids_Help_Screen_Exit(void)
{

}

void Asteroids_Help_Screen_Exit_ToMenu(void)
{
	CP_Engine_SetNextGameState(Asteroids_MainMenu_Init, Asteroids_MainMenu_Update, Asteroids_MainMenu_Exit);
}

void Asteroids_Draw_Screen_Page(void)
{
	if(screen.id < LAST_PAGE)
		CP_Image_Draw(Page_Image[screen.id], screen.pos.x, screen.pos.y, screen.width, screen.height, 255);

	if (screen.id > FIRST_PAGE)
		Asteroids_Button_Update(&BackBtn);

	if (screen.id < LAST_PAGE -1)
		Asteroids_Button_Update(&NextBtn);
}

void Asteroids_Help_Screen_IncreasePageNo(void)
{
	if (screen.id >= LAST_PAGE)
		return;

	screen.id += 1;
}

void Asteroids_Help_Screen_DecreasePageNo(void)
{
	if (screen.id <= FIRST_PAGE)
		return;

	screen.id -= 1;
}