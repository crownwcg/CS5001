################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/test_all.c \
../src/vcache.c \
../src/vcache_test.c 

OBJS += \
./src/main.o \
./src/test_all.o \
./src/vcache.o \
./src/vcache_test.o 

C_DEPS += \
./src/main.d \
./src/test_all.d \
./src/vcache.d \
./src/vcache_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


