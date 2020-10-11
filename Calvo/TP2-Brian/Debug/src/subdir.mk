################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EstacionDeFerrocarril.cpp \
../src/EstacionDeMetrobus.cpp \
../src/EstacionDeSubte.cpp \
../src/Garaje.cpp \
../src/ParadaDeColectivo.cpp \
../src/lectura.cpp \
../src/main.cpp 

OBJS += \
./src/EstacionDeFerrocarril.o \
./src/EstacionDeMetrobus.o \
./src/EstacionDeSubte.o \
./src/Garaje.o \
./src/ParadaDeColectivo.o \
./src/lectura.o \
./src/main.o 

CPP_DEPS += \
./src/EstacionDeFerrocarril.d \
./src/EstacionDeMetrobus.d \
./src/EstacionDeSubte.d \
./src/Garaje.d \
./src/ParadaDeColectivo.d \
./src/lectura.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


