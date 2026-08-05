#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	//graphics I nitialize
	gfxInitDefault();
	PrintConsole topConsole;
	consoleInit(GFX_TOP, &topConsole);
	consoleSelect(&topConsole);
	touchPosition touch;
	ptmuInit();

	//VERT HORZ
	//[1;0H

	printf("\x1b[1;0H\033[31m             3ds Button Tester v1.2.0             \033[0m");
	printf("\x1b[2;0H                 By:  NetherStef                  \n");
	printf("\x1b[3;0H--------------------------------------------------\n");
	printf("\x1b[4;35H\033[32mShortcuts:\033[0m");
	printf("\x1b[5;35HLT+RT : Return");
	printf("\x1b[6;35HA+B   : Clear");
	printf("\x1b[7;35HX+Y   : Type");
	printf("\x1b[8;35HST + SLT : Power");


	consoleSetWindow(&topConsole, 0, 4, 33, 22);

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		u32 kHeld = hidKeysHeld();
		u32 kDown = hidKeysDown();
		// press home to return to hb

		//Key Test

		if (kDown & KEY_START)
			printf("Start\n");
		if (kDown & KEY_SELECT)
			printf("Select\n");
		if (kDown & KEY_A)
			printf("A\n");
		if (kDown & KEY_B)
			printf("B\n");
		if (kDown & KEY_X)
			printf("X\n");
		if (kDown & KEY_Y)
			printf("Y\n");
		if (kDown & KEY_DOWN)
			printf("Down\n");
		if (kDown & KEY_UP)
			printf("Up\n");
		if (kDown & KEY_LEFT)
			printf("Left\n");
		if (kDown & KEY_RIGHT)
			printf("Right\n");
		if (kDown & KEY_L)
			printf("LT \n");
		if (kDown & KEY_R)
			printf("RT\n");
		if (kDown & KEY_TOUCH){
			hidTouchRead(&touch);
			printf("\x1b[5;0hX:%03d\nY:%03d\n", touch.px, touch.py);
		}

		if (kDown & KEY_CSTICK_DOWN)
			printf("cDown\n");
		if (kDown & KEY_CSTICK_UP)
			printf("cUp\n");
		if (kDown & KEY_CSTICK_LEFT)
			printf("cLeft\n");
		if (kDown & KEY_CSTICK_RIGHT)
			printf("cRight\n");
		if (kDown & KEY_ZL)
			printf("ZL\n");
		if (kDown & KEY_ZR)
			printf("ZR\n");
		if ((kHeld & KEY_B) && (kHeld & KEY_A))
			consoleClear();
		// Add on screen keyboard when X and Y are pressed, then output that text or cancel and make new line.
		if ((kHeld & KEY_X) && (kHeld & KEY_Y)){
			static char kbBuffer[100];
			SwkbdState swkbd;
			swkbdInit(&swkbd, SWKBD_TYPE_NORMAL, 2, -1);
			swkbdSetHintText (&swkbd, "3DS Button Tester");
			swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, 0, 0);
			SwkbdButton button = swkbdInputText(&swkbd, kbBuffer, sizeof(kbBuffer));
			if (button == SWKBD_BUTTON_CONFIRM) {
				printf("%s\n", kbBuffer);
			} else {
				printf("\n");
			}
		}
		//Return to hb menu with LT and RT
		if ((kHeld & KEY_R) && (kHeld & KEY_L))
			break;
		//Return to hb menu with LT and RT
		if ((kHeld & KEY_START) && (kHeld & KEY_SELECT))
		{
			u8 batteryLevel = 0;
			u8 isCharging = 0;
			PTMU_GetBatteryLevel(&batteryLevel);
			PTMU_GetBatteryChargeState(&isCharging);

			printf("Battery Level: %d / 5 ", batteryLevel);
			if (isCharging) {
				printf("Charging\n");
			} else {
				printf("Disconnected\n\n");
			}
		}
	}
	ptmuExit();
	gfxExit();
	return 0;
}
