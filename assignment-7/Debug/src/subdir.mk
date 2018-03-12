################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/assignment-7_test.c \
../src/circle.c \
../src/point.c \
../src/rectangle.c \
../src/str.c 

OBJS += \
./src/assignment-7_test.o \
./src/circle.o \
./src/point.o \
./src/rectangle.o \
./src/str.o 

C_DEPS += \
./src/assignment-7_test.d \
./src/circle.d \
./src/point.d \
./src/rectangle.d \
./src/str.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -I"/Users/crown/Desktop/Assignments/assignment-7/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


