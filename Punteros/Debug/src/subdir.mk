################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ejercicio1.cpp \
../src/main.cpp \
../src/memoriaDinamica.cpp \
../src/pruebas.cpp \
../src/referencias.cpp 

OBJS += \
./src/ejercicio1.o \
./src/main.o \
./src/memoriaDinamica.o \
./src/pruebas.o \
./src/referencias.o 

CPP_DEPS += \
./src/ejercicio1.d \
./src/main.d \
./src/memoriaDinamica.d \
./src/pruebas.d \
./src/referencias.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


