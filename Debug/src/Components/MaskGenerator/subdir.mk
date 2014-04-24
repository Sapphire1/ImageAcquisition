################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Components/MaskGenerator/MaskGenerator.cpp 

OBJS += \
./src/Components/MaskGenerator/MaskGenerator.o 

CPP_DEPS += \
./src/Components/MaskGenerator/MaskGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
src/Components/MaskGenerator/%.o: ../src/Components/MaskGenerator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/lzmuda/DisCODe/build/inst/include/Client -I/home/lzmuda/DisCODe/build/inst/include/Base -I/home/lzmuda/DisCODe/build/inst/include/Common -I/home/lzmuda/DisCODe/build/inst/include/Common/Network -I/home/lzmuda/DisCODe/build/inst/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


