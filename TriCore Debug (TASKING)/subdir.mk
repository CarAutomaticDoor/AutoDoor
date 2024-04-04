################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App_Module.c \
../Audio_Module.c \
../Cpu0_Main.c \
../Cpu1_Main.c \
../Cpu2_Main.c \
../Door_Module.c \
../Door_Module_Pressure_HandProtect.c \
../Door_Module_Servo_Door.c \
../Door_Module_Servo_Lock.c \
../Door_Module_Ultrasonic_ObjectDetection.c \
../ECU_Module.c \
../In_Module.c \
../In_Module_Switch_Door.c \
../In_Module_Switch_KidLock.c \
../Out_Module.c \
../Out_Module_Pressure_touch.c \
../Out_Module_TactSwitch.c \
../Out_Module_Ultrasonic_foot.c \
../myGtm.c \
../myPwm.c 

COMPILED_SRCS += \
./App_Module.src \
./Audio_Module.src \
./Cpu0_Main.src \
./Cpu1_Main.src \
./Cpu2_Main.src \
./Door_Module.src \
./Door_Module_Pressure_HandProtect.src \
./Door_Module_Servo_Door.src \
./Door_Module_Servo_Lock.src \
./Door_Module_Ultrasonic_ObjectDetection.src \
./ECU_Module.src \
./In_Module.src \
./In_Module_Switch_Door.src \
./In_Module_Switch_KidLock.src \
./Out_Module.src \
./Out_Module_Pressure_touch.src \
./Out_Module_TactSwitch.src \
./Out_Module_Ultrasonic_foot.src \
./myGtm.src \
./myPwm.src 

C_DEPS += \
./App_Module.d \
./Audio_Module.d \
./Cpu0_Main.d \
./Cpu1_Main.d \
./Cpu2_Main.d \
./Door_Module.d \
./Door_Module_Pressure_HandProtect.d \
./Door_Module_Servo_Door.d \
./Door_Module_Servo_Lock.d \
./Door_Module_Ultrasonic_ObjectDetection.d \
./ECU_Module.d \
./In_Module.d \
./In_Module_Switch_Door.d \
./In_Module_Switch_KidLock.d \
./Out_Module.d \
./Out_Module_Pressure_touch.d \
./Out_Module_TactSwitch.d \
./Out_Module_Ultrasonic_foot.d \
./myGtm.d \
./myPwm.d 

OBJS += \
./App_Module.o \
./Audio_Module.o \
./Cpu0_Main.o \
./Cpu1_Main.o \
./Cpu2_Main.o \
./Door_Module.o \
./Door_Module_Pressure_HandProtect.o \
./Door_Module_Servo_Door.o \
./Door_Module_Servo_Lock.o \
./Door_Module_Ultrasonic_ObjectDetection.o \
./ECU_Module.o \
./In_Module.o \
./In_Module_Switch_Door.o \
./In_Module_Switch_KidLock.o \
./Out_Module.o \
./Out_Module_Pressure_touch.o \
./Out_Module_TactSwitch.o \
./Out_Module_Ultrasonic_foot.o \
./myGtm.o \
./myPwm.o 


# Each subdirectory must supply rules for building sources it contributes
%.src: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git_repo/AutoDoor/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

App_Module.o: ./App_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Audio_Module.o: ./Audio_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Cpu0_Main.o: ./Cpu0_Main.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Cpu1_Main.o: ./Cpu1_Main.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Cpu2_Main.o: ./Cpu2_Main.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Door_Module.o: ./Door_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Door_Module_Pressure_HandProtect.o: ./Door_Module_Pressure_HandProtect.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Door_Module_Servo_Door.o: ./Door_Module_Servo_Door.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Door_Module_Servo_Lock.o: ./Door_Module_Servo_Lock.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Door_Module_Ultrasonic_ObjectDetection.o: ./Door_Module_Ultrasonic_ObjectDetection.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ECU_Module.o: ./ECU_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

In_Module.o: ./In_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

In_Module_Switch_Door.o: ./In_Module_Switch_Door.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

In_Module_Switch_KidLock.o: ./In_Module_Switch_KidLock.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Out_Module.o: ./Out_Module.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Out_Module_Pressure_touch.o: ./Out_Module_Pressure_touch.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Out_Module_TactSwitch.o: ./Out_Module_TactSwitch.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Out_Module_Ultrasonic_foot.o: ./Out_Module_Ultrasonic_foot.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

myGtm.o: ./myGtm.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

myPwm.o: ./myPwm.src subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./App_Module.d ./App_Module.o ./App_Module.src ./Audio_Module.d ./Audio_Module.o ./Audio_Module.src ./Cpu0_Main.d ./Cpu0_Main.o ./Cpu0_Main.src ./Cpu1_Main.d ./Cpu1_Main.o ./Cpu1_Main.src ./Cpu2_Main.d ./Cpu2_Main.o ./Cpu2_Main.src ./Door_Module.d ./Door_Module.o ./Door_Module.src ./Door_Module_Pressure_HandProtect.d ./Door_Module_Pressure_HandProtect.o ./Door_Module_Pressure_HandProtect.src ./Door_Module_Servo_Door.d ./Door_Module_Servo_Door.o ./Door_Module_Servo_Door.src ./Door_Module_Servo_Lock.d ./Door_Module_Servo_Lock.o ./Door_Module_Servo_Lock.src ./Door_Module_Ultrasonic_ObjectDetection.d ./Door_Module_Ultrasonic_ObjectDetection.o ./Door_Module_Ultrasonic_ObjectDetection.src ./ECU_Module.d ./ECU_Module.o ./ECU_Module.src ./In_Module.d ./In_Module.o ./In_Module.src ./In_Module_Switch_Door.d ./In_Module_Switch_Door.o ./In_Module_Switch_Door.src ./In_Module_Switch_KidLock.d ./In_Module_Switch_KidLock.o ./In_Module_Switch_KidLock.src ./Out_Module.d ./Out_Module.o ./Out_Module.src ./Out_Module_Pressure_touch.d ./Out_Module_Pressure_touch.o ./Out_Module_Pressure_touch.src ./Out_Module_TactSwitch.d ./Out_Module_TactSwitch.o ./Out_Module_TactSwitch.src ./Out_Module_Ultrasonic_foot.d ./Out_Module_Ultrasonic_foot.o ./Out_Module_Ultrasonic_foot.src ./myGtm.d ./myGtm.o ./myGtm.src ./myPwm.d ./myPwm.o ./myPwm.src

.PHONY: clean--2e-

