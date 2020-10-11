################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdditionalSource.cpp \
../src/EasyBMP.cpp \
../src/EasyBMP_Font.cpp \
../src/EasyBMP_Geometry.cpp \
../src/FontTest.cpp \
../src/main.cpp 

OBJS += \
./src/AdditionalSource.o \
./src/EasyBMP.o \
./src/EasyBMP_Font.o \
./src/EasyBMP_Geometry.o \
./src/FontTest.o \
./src/main.o 

CPP_DEPS += \
./src/AdditionalSource.d \
./src/EasyBMP.d \
./src/EasyBMP_Font.d \
./src/EasyBMP_Geometry.d \
./src/FontTest.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


