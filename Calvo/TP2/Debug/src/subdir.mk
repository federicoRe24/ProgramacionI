################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Camino.cpp \
../src/DibujarRecorrido.cpp \
../src/EasyBMP.cpp \
../src/EasyBMP_Font.cpp \
../src/EasyBMP_Geometry.cpp \
../src/Estaciones.cpp \
../src/Garaje.cpp \
../src/buscarCamino.cpp \
../src/lectura.cpp \
../src/main.cpp 

OBJS += \
./src/Camino.o \
./src/DibujarRecorrido.o \
./src/EasyBMP.o \
./src/EasyBMP_Font.o \
./src/EasyBMP_Geometry.o \
./src/Estaciones.o \
./src/Garaje.o \
./src/buscarCamino.o \
./src/lectura.o \
./src/main.o 

CPP_DEPS += \
./src/Camino.d \
./src/DibujarRecorrido.d \
./src/EasyBMP.d \
./src/EasyBMP_Font.d \
./src/EasyBMP_Geometry.d \
./src/Estaciones.d \
./src/Garaje.d \
./src/buscarCamino.d \
./src/lectura.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


