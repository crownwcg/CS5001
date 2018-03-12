################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/issn.c \
../src/issn_test.c \
../src/main.c \
../src/test_all.c 

OBJS += \
./src/issn.o \
./src/issn_test.o \
./src/main.o \
./src/test_all.o 

C_DEPS += \
./src/issn.d \
./src/issn_test.d \
./src/main.d \
./src/test_all.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


