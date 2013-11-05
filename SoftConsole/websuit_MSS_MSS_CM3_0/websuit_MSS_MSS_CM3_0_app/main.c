#include <stdio.h>
#include <inttypes.h>
#include "midi.h"

int main()
{

	MIDI_init();
	MIDI_noteOn(60, MIDI_DEFAULT_VELOCITY, MIDI_DEFAULT_CHANNEL);
	int i;
	for (i = 0; i < 200; i++) {
		printf("Busy looping: %d\n\r", i);
	}
	MIDI_noteOff(60, MIDI_DEFAULT_VELOCITY, MIDI_DEFAULT_CHANNEL);
	return(0);
}
