################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/applications/App_Module.c \
../includes/applications/Audio.c \
../includes/applications/Door_Button.c \
../includes/applications/Door_Control.c \
../includes/applications/Door_Lock.c \
../includes/applications/Finger_Detector.c \
../includes/applications/Obstacle_Detector.c \
../includes/applications/Out_Module_Ultrasonic_foot.c 

COMPILED_SRCS += \
./includes/applications/App_Module.src \
./includes/applications/Audio.src \
./includes/applications/Door_Button.src \
./includes/applications/Door_Control.src \
./includes/applications/Door_Lock.src \
./includes/applications/Finger_Detector.src \
./includes/applications/Obstacle_Detector.src \
./includes/applications/Out_Module_Ultrasonic_foot.src 

C_DEPS += \
./includes/applications/App_Module.d \
./includes/applications/Audio.d \
./includes/applications/Door_Button.d \
./includes/applications/Door_Control.d \
./includes/applications/Door_Lock.d \
./includes/applications/Finger_Detector.d \
./includes/applications/Obstacle_Detector.d \
./includes/applications/Out_Module_Ultrasonic_foot.d 

OBJS += \
./includes/applications/App_Module.o \
./includes/applications/Audio.o \
./includes/applications/Door_Button.o \
./includes/applications/Door_Control.o \
./includes/applications/Door_Lock.o \
./includes/applications/Finger_Detector.o \
./includes/applications/Obstacle_Detector.o \
./includes/applications/Out_Module_Ultrasonic_foot.o 


# Each subdirectory must supply rules for building sources it contributes
includes/applications/%.src: ../includes/applications/%.c includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git-repo/AutoDoor/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/includes\/applications\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/App_Module.o: ./includes/applications/App_Module.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Audio.o: ./includes/applications/Audio.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Door_Button.o: ./includes/applications/Door_Button.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Door_Control.o: ./includes/applications/Door_Control.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Door_Lock.o: ./includes/applications/Door_Lock.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Finger_Detector.o: ./includes/applications/Finger_Detector.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Obstacle_Detector.o: ./includes/applications/Obstacle_Detector.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/applications/Out_Module_Ultrasonic_foot.o: ./includes/applications/Out_Module_Ultrasonic_foot.src includes/applications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-includes-2f-applications

clean-includes-2f-applications:
	-$(RM) ./includes/applications/App_Module.d ./includes/applications/App_Module.o ./includes/applications/App_Module.src ./includes/applications/Audio.d ./includes/applications/Audio.o ./includes/applications/Audio.src ./includes/applications/Door_Button.d ./includes/applications/Door_Button.o ./includes/applications/Door_Button.src ./includes/applications/Door_Control.d ./includes/applications/Door_Control.o ./includes/applications/Door_Control.src ./includes/applications/Door_Lock.d ./includes/applications/Door_Lock.o ./includes/applications/Door_Lock.src ./includes/applications/Finger_Detector.d ./includes/applications/Finger_Detector.o ./includes/applications/Finger_Detector.src ./includes/applications/Obstacle_Detector.d ./includes/applications/Obstacle_Detector.o ./includes/applications/Obstacle_Detector.src ./includes/applications/Out_Module_Ultrasonic_foot.d ./includes/applications/Out_Module_Ultrasonic_foot.o ./includes/applications/Out_Module_Ultrasonic_foot.src

.PHONY: clean-includes-2f-applications

