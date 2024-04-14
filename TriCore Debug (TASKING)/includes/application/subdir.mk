################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/application/Audio.c \
../includes/application/Finger_Detector.c \
../includes/application/Foot_Sensor.c \
../includes/application/Light.c \
../includes/application/Lock.c \
../includes/application/Obstacle_Detector.c \
../includes/application/Side_Door.c \
../includes/application/Touch_Sensor.c 

COMPILED_SRCS += \
./includes/application/Audio.src \
./includes/application/Finger_Detector.src \
./includes/application/Foot_Sensor.src \
./includes/application/Light.src \
./includes/application/Lock.src \
./includes/application/Obstacle_Detector.src \
./includes/application/Side_Door.src \
./includes/application/Touch_Sensor.src 

C_DEPS += \
./includes/application/Audio.d \
./includes/application/Finger_Detector.d \
./includes/application/Foot_Sensor.d \
./includes/application/Light.d \
./includes/application/Lock.d \
./includes/application/Obstacle_Detector.d \
./includes/application/Side_Door.d \
./includes/application/Touch_Sensor.d 

OBJS += \
./includes/application/Audio.o \
./includes/application/Finger_Detector.o \
./includes/application/Foot_Sensor.o \
./includes/application/Light.o \
./includes/application/Lock.o \
./includes/application/Obstacle_Detector.o \
./includes/application/Side_Door.o \
./includes/application/Touch_Sensor.o 


# Each subdirectory must supply rules for building sources it contributes
includes/application/%.src: ../includes/application/%.c includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git-repo/AutoDoor/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/includes\/application\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Audio.o: ./includes/application/Audio.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Finger_Detector.o: ./includes/application/Finger_Detector.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Foot_Sensor.o: ./includes/application/Foot_Sensor.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Light.o: ./includes/application/Light.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Lock.o: ./includes/application/Lock.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Obstacle_Detector.o: ./includes/application/Obstacle_Detector.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Side_Door.o: ./includes/application/Side_Door.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/application/Touch_Sensor.o: ./includes/application/Touch_Sensor.src includes/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-includes-2f-application

clean-includes-2f-application:
	-$(RM) ./includes/application/Audio.d ./includes/application/Audio.o ./includes/application/Audio.src ./includes/application/Finger_Detector.d ./includes/application/Finger_Detector.o ./includes/application/Finger_Detector.src ./includes/application/Foot_Sensor.d ./includes/application/Foot_Sensor.o ./includes/application/Foot_Sensor.src ./includes/application/Light.d ./includes/application/Light.o ./includes/application/Light.src ./includes/application/Lock.d ./includes/application/Lock.o ./includes/application/Lock.src ./includes/application/Obstacle_Detector.d ./includes/application/Obstacle_Detector.o ./includes/application/Obstacle_Detector.src ./includes/application/Side_Door.d ./includes/application/Side_Door.o ./includes/application/Side_Door.src ./includes/application/Touch_Sensor.d ./includes/application/Touch_Sensor.o ./includes/application/Touch_Sensor.src

.PHONY: clean-includes-2f-application

