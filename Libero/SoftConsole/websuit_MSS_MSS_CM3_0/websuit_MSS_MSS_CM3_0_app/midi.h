#ifndef __MIDI_H_
#define __MIDI_H_ 1

#include "drivers/mss_uart/mss_uart.h"

#define MIDI_DEFAULT_CHANNEL 0
#define MIDI_DEFAULT_VELOCITY 127

void MIDI_init() {
	MSS_UART_init( &g_mss_uart1, 31250,
					MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT );
}

void MIDI_sendMessage(uint8_t dataBytes[], uint32_t numDataBytes) {
    MSS_UART_polled_tx( &g_mss_uart1, dataBytes, numDataBytes );
}

void MIDI_noteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    uint8_t data[3] = { 0x90 | (channel & 0xF), note, velocity};
    MIDI_sendMessage(data, 3);
}

void MIDI_noteOff(uint8_t note, uint8_t velocity, uint8_t channel) {
    uint8_t data[3] = { 0x80 | (channel & 0xF), note, velocity};
    MIDI_sendMessage(data, 3);
}

void MIDI_pitchWheelChange(uint16_t value, uint8_t channel) {
	uint8_t data[3] = {0xE0 | (channel & 0xF), value & 0x7F, value & 0x3F80>> 8};
	MIDI_sendMessage(data, 3);
}

void MIDI_controlChange(uint8_t control, uint8_t value, uint8_t channel) {
    uint8_t data[3] = { 0xB0 | (channel & 0xF), control, value};
    MIDI_sendMessage(data, 3);
}

void MIDI_programChange(uint8_t program, uint8_t channel) {
    uint8_t data[2] = { 0xC0 | (channel & 0xF), program};
    MIDI_sendMessage(data, 2);
}

// Commands not implemented: Aftertouch and Channel Pressure

#endif /* __MIDI_H_ */