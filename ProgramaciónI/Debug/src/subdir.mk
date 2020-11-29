################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase12.c \
../src/alumno.c \
../src/calculosArray.c \
../src/contratacion.c \
../src/main.c \
../src/pantalla.c \
../src/punteros.c \
../src/utn.c 

OBJS += \
./src/Clase12.o \
./src/alumno.o \
./src/calculosArray.o \
./src/contratacion.o \
./src/main.o \
./src/pantalla.o \
./src/punteros.o \
./src/utn.o 

C_DEPS += \
./src/Clase12.d \
./src/alumno.d \
./src/calculosArray.d \
./src/contratacion.d \
./src/main.d \
./src/pantalla.d \
./src/punteros.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


