################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mss_pdma/mss_pdma.c 

OBJS += \
./drivers/mss_pdma/mss_pdma.o 

C_DEPS += \
./drivers/mss_pdma/mss_pdma.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mss_pdma/%.o: ../drivers/mss_pdma/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -DACTEL_STDIO_THRU_UART -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\CMSIS -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_ace -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_gpio -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_i2c -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_nvm -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_pdma -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_rtc -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_spi -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_timer -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers\mss_uart -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers_config -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\drivers_config\mss_ace -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\hal -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\hal\CortexM3 -IN:\EECS373\wubsuit\websuit\SoftConsole\websuit_MSS_MSS_CM3_0\websuit_MSS_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O1 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


