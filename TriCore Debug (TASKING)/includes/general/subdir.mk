################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/general/Adc.c \
../includes/general/Buttons.c \
../includes/general/Delay.c \
../includes/general/Gtm.c \
../includes/general/Pwm.c \
../includes/general/Servo.c \
../includes/general/Uart.c \
../includes/general/Ultrasonic.c 

COMPILED_SRCS += \
./includes/general/Adc.src \
./includes/general/Buttons.src \
./includes/general/Delay.src \
./includes/general/Gtm.src \
./includes/general/Pwm.src \
./includes/general/Servo.src \
./includes/general/Uart.src \
./includes/general/Ultrasonic.src 

C_DEPS += \
./includes/general/Adc.d \
./includes/general/Buttons.d \
./includes/general/Delay.d \
./includes/general/Gtm.d \
./includes/general/Pwm.d \
./includes/general/Servo.d \
./includes/general/Uart.d \
./includes/general/Ultrasonic.d 

OBJS += \
./includes/general/Adc.o \
./includes/general/Buttons.o \
./includes/general/Delay.o \
./includes/general/Gtm.o \
./includes/general/Pwm.o \
./includes/general/Servo.o \
./includes/general/Uart.o \
./includes/general/Ultrasonic.o 


# Each subdirectory must supply rules for building sources it contributes
includes/general/%.src: ../includes/general/%.c includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git-repo/AutoDoor/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/includes\/general\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Adc.o: ./includes/general/Adc.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Buttons.o: ./includes/general/Buttons.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Delay.o: ./includes/general/Delay.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Gtm.o: ./includes/general/Gtm.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Pwm.o: ./includes/general/Pwm.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Servo.o: ./includes/general/Servo.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Uart.o: ./includes/general/Uart.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/general/Ultrasonic.o: ./includes/general/Ultrasonic.src includes/general/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-includes-2f-general

clean-includes-2f-general:
	-$(RM) ./includes/general/Adc.d ./includes/general/Adc.o ./includes/general/Adc.src ./includes/general/Buttons.d ./includes/general/Buttons.o ./includes/general/Buttons.src ./includes/general/Delay.d ./includes/general/Delay.o ./includes/general/Delay.src ./includes/general/Gtm.d ./includes/general/Gtm.o ./includes/general/Gtm.src ./includes/general/Pwm.d ./includes/general/Pwm.o ./includes/general/Pwm.src ./includes/general/Servo.d ./includes/general/Servo.o ./includes/general/Servo.src ./includes/general/Uart.d ./includes/general/Uart.o ./includes/general/Uart.src ./includes/general/Ultrasonic.d ./includes/general/Ultrasonic.o ./includes/general/Ultrasonic.src

.PHONY: clean-includes-2f-general

