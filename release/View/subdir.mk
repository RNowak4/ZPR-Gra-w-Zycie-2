################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./View/Assets.cpp \
./View/Graphics.cpp \
./View/SdlHelper.cpp \
./View/View.cpp 

OBJS += \
./View/Assets.o \
./View/Graphics.o \
./View/SdlHelper.o \
./View/View.o 

CPP_DEPS += \
./View/Assets.d \
./View/Graphics.d \
./View/SdlHelper.d \
./View/View.d 


# Each subdirectory must supply rules for building sources it contributes
View/%.o: ../View/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


