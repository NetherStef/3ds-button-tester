Basic C program for the 3DS to test touch screen and button inputs.

Pressing start will show you it works by returning you to the Homebrew menu, as so does the home button in a similar fashion. Pressing A + B will clear the console

For Users running Arch Linux (With devkitpro Installed) cd Into the folder with the source code inside

$ cd /3ds-button-tester/

$ make

In the homebrew menu on the 3ds press "Y"
Then in your Console type

$ $DEVKITPRO/tools/bin/3dslink application.3dsx

and it will show up on your 3ds

For users using windows or other operating systems

follow the instructions to make the base devkitpro template
and it should work correctly.

Changelogs
Added the On screen keyboard if X + Y are pressed.
Changed kDown to kHeld on dual inputs to get more accurate input.
Added version number 
Changed the homebrew return buttons to LT and RT.
Changed my name to my username.
