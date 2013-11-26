#include <inttypes.h>
#include "menu.h"
#include "lcd.h"
#include "suit.h"
#include "constants.h"

Menu* currentMenu;
uint8_t selectedMenu;
Menu menus[MENU_COUNT];
Settings *settings;
SuitState *suitState;

char* NoteNames[MAX_NOTES] = {
	"C0", "C#0", "D0", "D#0", "E0", "F0", "F#0", "G0", "G#0", "A0", "A#0", "B0",
	"C1", "C#1", "D1", "D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
	"C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
	"C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
	"C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
	"C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5",
	"C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6",
	"C7", "C#7", "D7", "D#7", "E7", "F7", "F#7", "G7", "G#7", "A7", "A#7", "B7",
	"C8", "C#8", "D8", "D#8", "E8", "F8", "F#8", "G8", "G#8", "A8", "A#8", "B8",
	"C9", "C#9", "D9", "D#9", "E9", "F9", "F#9", "G9", "G#9", "A9", "A#9", "B9",
	"C10", "C#10", "D10", "D#10", "E10", "F10", "F#10", "G10"
};

char* KeySignatureNames[MAX_KEYSIGNATURES] = {
	"Chromatic", "C Major", "C Minor"
};

void Menu_setKeySignature(uint8_t value) {
	settings->keySignature = ((KeySignature) (value));
	printf("Key signature is now %s\n\r", KeySignatureNames[settings->keySignature]);
}

void Menu_init(Settings *setS, SuitState *suitS) {
	settings = setS;
	suitState = suitS;

	currentMenu = &(menus[0]);
	selectedMenu = 0;

	// Top Level Menu

	menus[0].name = "Main Menu";
	menus[0].submenusCount = 4;
	menus[0].previousMenu = 0;

	menus[0].submenus[0] = &(menus[1]); // Note Output
	menus[0].submenus[1] = &(menus[2]); // MIDI Mappings
	menus[0].submenus[2] = &(menus[11]); // Calibrate
	menus[0].submenus[3] = &(menus[14]); // Suit Lights

	// Main Menus

	menus[1].name = "Note Output";
	menus[1].submenusCount = 3;
	menus[1].submenus[0] = &(menus[3]); // Key Signature
	menus[1].submenus[1] = &(menus[9]); // Min Note
	menus[1].submenus[2] = &(menus[10]); // Max Note
	menus[1].previousMenu = &(menus[0]);

	menus[2].name = "MIDI Mappings";
	menus[2].submenusCount = 2;
	menus[2].submenus[0] = &(menus[7]); // Left Foot
	menus[2].submenus[1] = &(menus[8]); // Right Foot
	menus[2].previousMenu = &(menus[0]);

	// Note Output

	menus[3].name = "Key Signature";
	menus[3].submenusCount = 3;
	menus[3].submenus[0] = &(menus[4]);
	menus[3].submenus[1] = &(menus[5]);
	menus[3].submenus[2] = &(menus[6]);
	menus[3].previousMenu = &(menus[1]);

	menus[4].name = KeySignatureNames[0];
	menus[4].submenusCount = 0;
	menus[4].value = CHROMATIC;
	menus[4].command = Menu_setKeySignature;
	menus[4].previousMenu = &(menus[1]);

	menus[5].name = KeySignatureNames[1];
	menus[5].value = CMAJOR;
	menus[5].submenusCount = 0;
	menus[5].command = Menu_setKeySignature;
	menus[5].previousMenu = &(menus[1]);

	menus[6].name = KeySignatureNames[2];
	menus[6].value = CMINOR;
	menus[6].submenusCount = 0;
	menus[6].command = Menu_setKeySignature;
	menus[6].previousMenu = &(menus[1]);

	menus[9].name = "Min Note";
	menus[9].submenusCount = 0;
	menus[9].previousMenu = &(menus[1]);

	menus[10].name = "Max Note";
	menus[10].submenusCount = 0;
	menus[10].previousMenu = &(menus[1]);

	// MIDI Mappings

	menus[7].name = "Left Foot";
	menus[7].submenusCount = 0;
	menus[7].previousMenu = &(menus[2]);

	menus[8].name = "Right Foot";
	menus[8].submenusCount = 0;
	menus[8].previousMenu = &(menus[2]);

	// Calibrate

	menus[11].name = "Calibrate";
	menus[11].submenusCount = 2;
	menus[11].submenus[0] = &(menus[11]);
	menus[11].submenus[1] = &(menus[12]);
	menus[11].previousMenu = &(menus[0]);

	menus[12].name = "Hand Height Min";
	menus[12].submenusCount = 0;
	menus[12].previousMenu = &(menus[11]);

	menus[13].name = "Hand Height Max";
	menus[13].submenusCount = 0;
	menus[13].previousMenu = &(menus[11]);

	// Suit Lights

	menus[14].name = "Suit Lights";
	menus[14].submenusCount = 7;
	menus[14].submenus[0] = &(menus[15]);
	menus[14].submenus[1] = &(menus[16]);
	menus[14].submenus[2] = &(menus[17]);
	menus[14].submenus[3] = &(menus[18]);
	menus[14].submenus[4] = &(menus[19]);
	menus[14].submenus[5] = &(menus[20]);
	menus[14].submenus[6] = &(menus[21]);
	menus[14].previousMenu = &(menus[0]);

	menus[15].name = "Right Arm";
	menus[15].submenusCount = 0;
	menus[15].previousMenu = &(menus[14]);

	menus[16].name = "Left Arm";
	menus[16].submenusCount = 0;
	menus[16].previousMenu = &(menus[14]);

	menus[17].name = "Right Body";
	menus[17].submenusCount = 0;
	menus[17].previousMenu = &(menus[14]);

	menus[18].name = "Left Body";
	menus[18].submenusCount = 0;
	menus[18].previousMenu = &(menus[14]);

	menus[19].name = "Right Leg";
	menus[19].submenusCount = 0;
	menus[19].previousMenu = &(menus[14]);

	menus[20].name = "Left Leg";
	menus[20].submenusCount = 0;
	menus[20].previousMenu = &(menus[14]);

	menus[21].name = "Chest";
	menus[21].submenusCount = 0;
	menus[21].previousMenu = &(menus[14]);

}

void Menu_displayCurrentMenu() {
	volatile uint8_t i;

	LCD_clearScreen();
	LCD_setSelectorPosition(selectedMenu);
	LCD_drawString(currentMenu->name, 10, 0);

	for (i = 0; i < currentMenu->submenusCount; i++) {
		LCD_drawString((currentMenu->submenus[i])->name, 10, (LCD_LINE_HEIGHT * (i + 1)));
	}
}

void Menu_setMenu(Menu* menu) {
	currentMenu = menu;
	selectedMenu = 0;
	Menu_displayCurrentMenu(currentMenu);
}

void Menu_moveDown() {
	if (selectedMenu < currentMenu->submenusCount - 1) {
		selectedMenu++;
		LCD_setSelectorPosition(selectedMenu);
	}
}

void Menu_moveUp() {
	if (selectedMenu > 0) {
		selectedMenu--;
		LCD_setSelectorPosition(selectedMenu);
	}
}

void Menu_select() {
	Menu *menu = currentMenu->submenus[selectedMenu];
	if (menu->submenusCount == 0) {
		menu->command(menu->value);
		Menu_setMenu(menu->previousMenu);
	} else {
		Menu_setMenu(menu);
	}
}
