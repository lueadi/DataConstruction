################################################################################
# Modified by sy,20160912
# Normal Compile:make
# CROSS Compile:make E9
################################################################################
#define all app names here,added by cxh,20160410
APP1 = List_Test
#APP2 = TTC_main_rsu
#APP += $(APP1) $(APP2) 
APP += $(APP1)

#Set project directory
PRO_DIR = $(shell cd .. && pwd)

# Fallback defaults (host),added by cxh,20160405
BOARD ?= $(shell uname --m)
CC := $(CROSS_COMPILE)gcc 

# DEBUG choice,added by cxh,20160405
# DEBUG choice,added by cxh,20160405,modified by cxh,20160408
isDEBUG = y
isPRINT = y

# 是否打印调试信息,added by cxh,20160411
ifeq ($(isPRINT),y)
	D_PRINT = -DDEBUG
endif

ifeq ($(isDEBUG),y)
  # "-O" is needed to expand inlines
  EXTRA_CFLAGS += -O0 -g3 -Wall $(D_PRINT) -c -fmessage-length=0
else
  EXTRA_CFLAGS += -O0 $(D_PRINT) -c -fmessage-length=0
endif
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include dataconstruction/subdir.mk
#-include obu/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(APP)

# Tool invocations
$(APP1): $(OBU_OBJS) $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CC) -L"$(PRO_DIR)/libv2x-yt" -o "$(APP1)" $(OBU_OBJS) $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	
#$(APP2): $(RSU_OBJS) $(USER_OBJS)
#	@echo 'Building target: $@'
#	@echo 'Invoking: GCC C Linker'
#	$(CC) -L"$(PRO_DIR)/libv2x-yt" -o "$(APP2)" $(RSU_OBJS) $(OBJS) $(USER_OBJS) $(LIBS)
#	@echo 'Finished building target: $@'
#	@echo ' '

# Other Targets
#for arm
#make e9 or E9,modified by cxh,20160408
e9 E9:	
	env BOARD=$@ ARCH=arm PATH=$(PATH):/home/duser/duser/arm_gcc/opt/Embedsky/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/tq-linaro-toolchain/bin  \
	CROSS_COMPILE="ccache arm-none-linux-gnueabi-" isE9="y" \
	$(MAKE)
#	env BOARD=$@ ARCH=arm PATH=$(PATH):/opt/FriendlyARM/toolschain/4.4.3/bin \
	CROSS_COMPILE="ccache arm-none-linux-gnueabi-" isE9="y" \
	$(MAKE)

clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) $(OBU_OBJS) $(RSU_OBJS) $(APP)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
