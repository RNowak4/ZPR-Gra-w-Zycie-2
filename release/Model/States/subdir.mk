################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
Model/States/Childhood.cpp \
Model/States/Illness.cpp \
Model/States/Mother.cpp \
Model/States/State.cpp 

OBJS += \
./Model/States/Childhood.o \
./Model/States/Illness.o \
./Model/States/Mother.o \
./Model/States/State.o 

CPP_DEPS += \
./Model/States/Childhood.d \
./Model/States/Illness.d \
./Model/States/Mother.d \
./Model/States/State.d 


# Each subdirectory must supply rules for building sources it contributes
Model/States/%.o: ../Model/States/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


