#ifndef SUIT_H_
#define SUIT_H_

#include "drivers/CoreUARTapb/core_uart_apb.h"

// NOTE: Baud values based on 100MHz clock
#define BAUD_VALUE_115200    		53 //Possibly a problem because not exactly 53 (53.2535)
#define BAUD_VALUE_31250    		199

#define COREUARTAPB0_BASE_ADDR      0x40050000
#define COREUARTAPB1_BASE_ADDR      0x40050100
#define COREUARTAPB2_BASE_ADDR      0x40050200
#define MAX_RX_DATA_SIZE    		512
#define LIGHT_CHANNELS_COUNT    	8

UART_instance_t XBee_uart, MIDI_uart;

struct SuitState {
	uint8_t accelX, accelY, accelZ;
	uint8_t flexValue;
	uint8_t handHeight;
	uint8_t activeLights;
	uint8_t state;
	uint8_t lightChannelMappings[LIGHT_CHANNELS_COUNT];
	uint8_t lightControlMIDIChannel;
} suitState;

void Suit_init();
void Suit_toggleModes();

// Input

void Suit_capButtonPressed();
void Suit_capButtonReleased();
void Suit_LPiezoPressed();
void Suit_RPiezoPressed();
void Suit_newSensorValues();
void Suit_handleMIDIMessage(uint8_t *message, uint16_t length);

// Utility

uint8_t Suit_MIDIToLightChannel(uint8_t note);
void Suit_turnOnLightChannel(uint8_t channel);
void Suit_turnOffLightChannel(uint8_t channel);

#endif /* SUIT_H_ */
