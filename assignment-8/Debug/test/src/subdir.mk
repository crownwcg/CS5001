################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../test/src/issn_test.c \
../test/src/journal_test.c \
../test/src/publisher_test.c \
../test/src/test_all.c 

OBJS += \
./test/src/issn_test.o \
./test/src/journal_test.o \
./test/src/publisher_test.o \
./test/src/test_all.o 

C_DEPS += \
./test/src/issn_test.d \
./test/src/journal_test.d \
./test/src/publisher_test.d \
./test/src/test_all.d 


# Each subdirectory must supply rules for building sources it contributes
test/src/%.o: ../test/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include -I"/Users/crown/Desktop/Assignments/assignment-8/src" -I"/Users/crown/Desktop/Assignments/assignment-8/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


