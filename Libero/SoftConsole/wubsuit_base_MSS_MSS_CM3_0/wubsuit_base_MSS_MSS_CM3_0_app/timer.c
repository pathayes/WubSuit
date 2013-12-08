#include "timer.h"

void MYTIMER_init()
{
    // we don't have to do anything.
}

void MYTIMER_enable()
{
    MYTIMER->control |= MYTIMER_ENABLE_MASK;
}

void MYTIMER_disable()
{
    MYTIMER->control &= ~MYTIMER_ENABLE_MASK;
}

void MYTIMER_setOverflowVal(uint32_t value)
{
	// Yes it's inefficient, but it's written this way to
	// show you the C to assembly mapping.
    uint32_t * timerAddr = (uint32_t*)(MYTIMER);
    *timerAddr = value; // overflowReg is at offset 0x0
}

uint32_t MYTIMER_getCounterVal()
{

// Yes it's inefficient, but it's written this way to
// show you the C to assembly mapping.
    uint32_t * timerAddr = (uint32_t*)(MYTIMER);
    return *(timerAddr + 1); // counterReg is at offset 0x4
}

/**
 * Enable all interrupts
 */
void MYTIMER_enable_allInterrupts() {
	MYTIMER->control |= MYTIMER_ENABLE_ALL_MASK;
}
/**
 * Disable all interrupts
 */

void MYTIMER_disable_allInterrupts() {
	MYTIMER->control &= MYTIMER_DISABLE_ALL_MASK;
}
/**
 * Enable compare interrupt
 */

void MYTIMER_enable_compareInt() {
	MYTIMER->control |= MYTIMER_ENABLE_COMPARE_INT_MASK;
}
/**
 * Disable compare interrupt
 */

void MYTIMER_disable_compareInt() {
	MYTIMER->control &= MYTIMER_DISABLE_COMPARE_INT_MASK;
}
/**
 * Set Compare value
 */

void MYTIMER_setCompareVal(uint32_t compare) {
	// Yes it's inefficient, but it's written this way to
	// show you the C to assembly mapping.
	uint32_t * timerAddr = (uint32_t*)(MYTIMER);
	*(timerAddr + 3) = compare; // compareReg is at offset 0x0C
}
/**
 * Enable overflow interrupt
 */

void MYTIMER_enable_overflowInt() {
	MYTIMER->control |= MYTIMER_ENABLE_OVERFLOW_INT_MASK;
}
/**
 * Disable overflow interrupt
 */

void MYTIMER_disable_overflowInt() {
	MYTIMER->control &= MYTIMER_DISABLE_OVERFLOW_INT_MASK;
}
/**
  * Interrupt status
*/

uint32_t MYTIMER_getInterrupt_status() {
	// Yes it's inefficient, but it's written this way to
	// show you the C to assembly mapping.
	uint32_t * timerAddr = (uint32_t*)(MYTIMER);
	return *(timerAddr + 4); // interruptReg is at offset 0x10
}
/**
 * Enable overflow interrupt
 */

void MYTIMER_enable_pwm() {
	MYTIMER->control |= MYTIMER_ENABLE_PWM_MASK;
}
/**
 * Disable overflow interrupt
 */

void MYTIMER_disable_pwm() {
	MYTIMER->control &= MYTIMER_DISABLE_PWM_MASK;
}
/**
 * Enable Capture
 */
void MYTIMER_enable_capture() {
	MYTIMER->control |= MYTIMER_ENABLE_CAPTURE_MASK;
}
/**
 * Disable Capture
 */
void MYTIMER_disable_capture() {
	MYTIMER->control &= MYTIMER_DISABLE_CAPTURE_MASK;
}

/**
 * Read the synchronous capture value
*/

uint32_t MYTIMER_get_sync_capture() {
	uint32_t * timerAddr = (uint32_t*)(MYTIMER);
	return *(timerAddr + 5); // captureSync is at offset 0x14
}
/**
 * Read the asynchronous capture value
*/

uint32_t MYTIMER_get_async_capture() {
	uint32_t * timerAddr = (uint32_t*)(MYTIMER);
	return *(timerAddr + 6); // captureAsync is at offset 0x18
}
