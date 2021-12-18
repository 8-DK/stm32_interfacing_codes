################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/mainApp.c \
../Src/spi.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/sx1276_7_8.c \
../Src/system_stm32f1xx.c \
../Src/usb_device.c \
../Src/usbd_cdc_if.c \
../Src/usbd_conf.c \
../Src/usbd_desc.c 

OBJS += \
./Src/main.o \
./Src/mainApp.o \
./Src/spi.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/sx1276_7_8.o \
./Src/system_stm32f1xx.o \
./Src/usb_device.o \
./Src/usbd_cdc_if.o \
./Src/usbd_conf.o \
./Src/usbd_desc.o 

C_DEPS += \
./Src/main.d \
./Src/mainApp.d \
./Src/spi.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/sx1276_7_8.d \
./Src/system_stm32f1xx.d \
./Src/usb_device.d \
./Src/usbd_cdc_if.d \
./Src/usbd_conf.d \
./Src/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I../../../../../../Inc -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Drivers/CMSIS/Include" -I"C:/Users/dkhairnar/STM32workspace/LoraSTM32/Inc"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


