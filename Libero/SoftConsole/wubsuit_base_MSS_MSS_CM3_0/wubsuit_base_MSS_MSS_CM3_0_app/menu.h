#ifndef MENU_H_
#define MENU_H_

#include <inttypes.h>
#include "suit.h"

#define MENU_COUNT 100
#define MAX_SUBMENUS 10
#define MAX_NAME 20

typedef struct _Menu {
	char* name;
	uint8_t value;
	void (*command)(uint8_t);
	uint8_t submenusCount;
	struct _Menu* submenus[MAX_SUBMENUS];
} Menu;

void Menu_setKeySignature(uint8_t value);
void Menu_init(Settings *setS, SuitState *suitS);
void Menu_displayCurrentMenu();
void Menu_setMenu(Menu* menu);
void Menu_moveDown();
void Menu_moveUp();
void Menu_select();

#endif /* MENU_H_ */
