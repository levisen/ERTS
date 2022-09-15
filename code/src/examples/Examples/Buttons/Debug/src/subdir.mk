################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Buttons.cpp \
../src/Debounce.cpp \
../src/Monitor.cpp \
../src/Simuli.cpp \
../src/Top.cpp \
../src/main.cpp 

OBJS += \
./src/Buttons.o \
./src/Debounce.o \
./src/Monitor.o \
./src/Simuli.o \
./src/Top.o \
./src/main.o 

CPP_DEPS += \
./src/Buttons.d \
./src/Debounce.d \
./src/Monitor.d \
./src/Simuli.d \
./src/Top.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/lib/systemc-2.3.1/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


