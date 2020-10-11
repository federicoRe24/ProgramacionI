################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clase10.c \
../src/clase7.c \
../src/clase8.c \
../src/clase9.c \
../src/main.c 

OBJS += \
./src/clase10.o \
./src/clase7.o \
./src/clase8.o \
./src/clase9.o \
./src/main.o 

C_DEPS += \
./src/clase10.d \
./src/clase7.d \
./src/clase8.d \
./src/clase9.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


