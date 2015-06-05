################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
Model/Animal.cpp \
Model/AnimalData.cpp \
Model/Attributes.cpp \
Model/Carnivore.cpp \
Model/Constants.cpp \
Model/Herbivore.cpp \
Model/Model.cpp \
Model/Parameters.cpp 

OBJS += \
./Model/Animal.o \
./Model/AnimalData.o \
./Model/Attributes.o \
./Model/Carnivore.o \
./Model/Constants.o \
./Model/Herbivore.o \
./Model/Model.o \
./Model/Parameters.o 

CPP_DEPS += \
./Model/Animal.d \
./Model/AnimalData.d \
./Model/Attributes.d \
./Model/Carnivore.d \
./Model/Constants.d \
./Model/Herbivore.d \
./Model/Model.d \
./Model/Parameters.d 


# Each subdirectory must supply rules for building sources it contributes
Model/%.o: ../Model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


