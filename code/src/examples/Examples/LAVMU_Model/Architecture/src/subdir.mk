################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Algo.cpp \
../src/CodecSink.cpp \
../src/CodecSource.cpp \
../src/IIRFilter.cpp \
../src/PView.cpp \
../src/main.cpp \
../src/top.cpp 

OBJS += \
./src/Algo.o \
./src/CodecSink.o \
./src/CodecSource.o \
./src/IIRFilter.o \
./src/PView.o \
./src/main.o \
./src/top.o 

CPP_DEPS += \
./src/Algo.d \
./src/CodecSink.d \
./src/CodecSource.d \
./src/IIRFilter.d \
./src/PView.d \
./src/main.d \
./src/top.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/lib/systemc-2.3.1/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


