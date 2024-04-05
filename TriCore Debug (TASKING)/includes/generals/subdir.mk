################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../includes/generals/myDelay.c \
../includes/generals/myGtm.c \
../includes/generals/myPwm.c \
../includes/generals/myUltraSonic.c 

COMPILED_SRCS += \
./includes/generals/myDelay.src \
./includes/generals/myGtm.src \
./includes/generals/myPwm.src \
./includes/generals/myUltraSonic.src 

C_DEPS += \
./includes/generals/myDelay.d \
./includes/generals/myGtm.d \
./includes/generals/myPwm.d \
./includes/generals/myUltraSonic.d 

OBJS += \
./includes/generals/myDelay.o \
./includes/generals/myGtm.o \
./includes/generals/myPwm.o \
./includes/generals/myUltraSonic.o 


# Each subdirectory must supply rules for building sources it contributes
includes/generals/%.src: ../includes/generals/%.c includes/generals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/git-repo/AutoDoor/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/includes\/generals\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

includes/generals/myDelay.o: ./includes/generals/myDelay.src includes/generals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/generals/myGtm.o: ./includes/generals/myGtm.src includes/generals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/generals/myPwm.o: ./includes/generals/myPwm.src includes/generals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

includes/generals/myUltraSonic.o: ./includes/generals/myUltraSonic.src includes/generals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-includes-2f-generals

clean-includes-2f-generals:
	-$(RM) ./includes/generals/myDelay.d ./includes/generals/myDelay.o ./includes/generals/myDelay.src ./includes/generals/myGtm.d ./includes/generals/myGtm.o ./includes/generals/myGtm.src ./includes/generals/myPwm.d ./includes/generals/myPwm.o ./includes/generals/myPwm.src ./includes/generals/myUltraSonic.d ./includes/generals/myUltraSonic.o ./includes/generals/myUltraSonic.src

.PHONY: clean-includes-2f-generals

