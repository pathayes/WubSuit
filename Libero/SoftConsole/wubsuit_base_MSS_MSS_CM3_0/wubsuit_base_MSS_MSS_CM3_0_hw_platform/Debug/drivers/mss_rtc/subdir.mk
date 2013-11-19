################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mss_rtc/mss_rtc.c 

OBJS += \
./drivers/mss_rtc/mss_rtc.o 

C_DEPS += \
./drivers/mss_rtc/mss_rtc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mss_rtc/%.o: ../drivers/mss_rtc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -DACTEL_STDIO_THRU_UART -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\CMSIS -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\CoreUARTapb -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_gpio -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_nvm -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_pdma -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_rtc -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_timer -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\drivers\mss_uart -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal\CortexM3 -IN:\EECS373\wubsuit_base\SoftConsole\wubsuit_base_MSS_MSS_CM3_0\wubsuit_base_MSS_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O1 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


