#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	//Graphics initilize

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	touchPosition touch;

    // Title \n makes a new line
	printf("\033[31m                3ds Button Tester                 \033[0m");
	printf("                By: Stefan Burner                 ");
	printf("\033[36m    Press START to return to the Homebrew Menu.   \033[0m");
	printf("\033[32m        Press A + B To clear the Console.         \033[0m\n");
	//Mount SD Card (for future file manage tool)

//	Result rc = qtmcInit();
//	if (R_FAILED(rc)) {
//		printf("Failed to initialize SD card: %08lX\n", rc);
//	} else {
//		printf("SD card initialized successfully.\n");
//		printf("Warning:\n The C stick is very sensitive\n");
//	}





	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kHeld = hidKeysHeld();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		//Key Test
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
			printf("\x1b[5;0hTouch Sensed at X: %03d, Y: %03d\n", touch.px, touch.py);
		}



		if (kHeld & KEY_CSTICK_DOWN)
			printf("cDown\n");
		if (kHeld & KEY_CSTICK_UP)
			printf("cUp\n");
		if (kHeld & KEY_CSTICK_LEFT)
			printf("cLeft\n");
		if (kHeld & KEY_CSTICK_RIGHT)
			printf("cRight\n");
		if (kDown & KEY_ZL)
			printf("ZL\n");
		if (kDown & KEY_ZR)
			printf("ZR\n");
		if ((kDown & KEY_B) && (kDown & KEY_A))
			consoleClear();




	}

	gfxExit();
	return 0;
}
