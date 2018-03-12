################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/issn.c \
../src/journal.c \
../src/main_v2.c \
../src/publisher.c 

OBJS += \
./src/issn.o \
./src/journal.o \
./src/main_v2.o \
./src/publisher.o 

C_DEPS += \
./src/issn.d \
./src/journal.d \
./src/main_v2.d \
./src/publisher.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -I"/Users/crown/Desktop/Assignments/assignment-8/src" -I"/Users/crown/Desktop/Assignments/assignment-8/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


