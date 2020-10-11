################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EasyBMP.cpp \
../src/EasyBMP_Geometry.cpp \
../src/EasyBMPsample.cpp \
../src/PruebaBMP.cpp 

OBJS += \
./src/EasyBMP.o \
./src/EasyBMP_Geometry.o \
./src/EasyBMPsample.o \
./src/PruebaBMP.o 

CPP_DEPS += \
./src/EasyBMP.d \
./src/EasyBMP_Geometry.d \
./src/EasyBMPsample.d \
./src/PruebaBMP.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


