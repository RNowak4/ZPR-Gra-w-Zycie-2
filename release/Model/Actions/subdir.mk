################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
Model/Actions/Action.cpp \
Model/Actions/CarnivoreAction.cpp \
Model/Actions/CarnivoreRandomWalking.cpp \
Model/Actions/CarnivoreSleeping.cpp \
Model/Actions/Chasing.cpp \
Model/Actions/ChildAction.cpp \
Model/Actions/ChildFleeing.cpp \
Model/Actions/Copulation.cpp \
Model/Actions/DoNothing.cpp \
Model/Actions/Eating.cpp \
Model/Actions/FeedChildren.cpp \
Model/Actions/Fleeing.cpp \
Model/Actions/Follow.cpp \
Model/Actions/FollowMother.cpp \
Model/Actions/HerbivoreAction.cpp \
Model/Actions/HerbivoreChildEat.cpp \
Model/Actions/HerbivoreChildSleep.cpp \
Model/Actions/HerbivoreRandomWalking.cpp \
Model/Actions/Hunting.cpp \
Model/Actions/LookingForPartner.cpp \
Model/Actions/RandomWalking.cpp \
Model/Actions/Sleeping.cpp 

OBJS += \
./Model/Actions/Action.o \
./Model/Actions/CarnivoreAction.o \
./Model/Actions/CarnivoreRandomWalking.o \
./Model/Actions/CarnivoreSleeping.o \
./Model/Actions/Chasing.o \
./Model/Actions/ChildAction.o \
./Model/Actions/ChildFleeing.o \
./Model/Actions/Copulation.o \
./Model/Actions/DoNothing.o \
./Model/Actions/Eating.o \
./Model/Actions/FeedChildren.o \
./Model/Actions/Fleeing.o \
./Model/Actions/Follow.o \
./Model/Actions/FollowMother.o \
./Model/Actions/HerbivoreAction.o \
./Model/Actions/HerbivoreChildEat.o \
./Model/Actions/HerbivoreChildSleep.o \
./Model/Actions/HerbivoreRandomWalking.o \
./Model/Actions/Hunting.o \
./Model/Actions/LookingForPartner.o \
./Model/Actions/RandomWalking.o \
./Model/Actions/Sleeping.o 

CPP_DEPS += \
./Model/Actions/Action.d \
./Model/Actions/CarnivoreAction.d \
./Model/Actions/CarnivoreRandomWalking.d \
./Model/Actions/CarnivoreSleeping.d \
./Model/Actions/Chasing.d \
./Model/Actions/ChildAction.d \
./Model/Actions/ChildFleeing.d \
./Model/Actions/Copulation.d \
./Model/Actions/DoNothing.d \
./Model/Actions/Eating.d \
./Model/Actions/FeedChildren.d \
./Model/Actions/Fleeing.d \
./Model/Actions/Follow.d \
./Model/Actions/FollowMother.d \
./Model/Actions/HerbivoreAction.d \
./Model/Actions/HerbivoreChildEat.d \
./Model/Actions/HerbivoreChildSleep.d \
./Model/Actions/HerbivoreRandomWalking.d \
./Model/Actions/Hunting.d \
./Model/Actions/LookingForPartner.d \
./Model/Actions/RandomWalking.d \
./Model/Actions/Sleeping.d 


# Each subdirectory must supply rules for building sources it contributes
Model/Actions/%.o: ../Model/Actions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


