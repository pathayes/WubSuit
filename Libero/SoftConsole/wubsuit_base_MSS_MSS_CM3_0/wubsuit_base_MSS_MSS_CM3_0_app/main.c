#include <inttypes.h>
#include <stdio.h>
#include "suit.h"

int main()
{
	Suit_init(&suitState);

	while (1) {
		printf("Waiting for an interrupt...\n\r");
		asm("wfi");
	}

	return 0;
}