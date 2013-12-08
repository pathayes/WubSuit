################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd.c \
../main.c \
../menu.c \
../midi.c \
../suit.c \
../timer.c 

OBJS += \
./lcd.o \
./main.o \
./menu.o \
./midi.o \
./suit.o \
./timer.o 

C_DEPS += \
./lcd.d \
./main.d \
./menu.d \
./midi.d \
./suit.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\CMSIS -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\CoreUARTapb -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_gpio -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_nvm -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_pdma -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_rtc -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_timer -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_uart -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal\CortexM3 -IN:\EECS373\WubSuit\Libero\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


