################################################################################
# Modified by sy,20160520
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dataconstruction/Data_Public.c\
../dataconstruction/Singly_Link_list.c\
../dataconstruction/Double_Link_List.c\
../dataconstruction/Stack.c\
../dataconstruction/List_Test.c\




OBU_OBJS += \
./dataconstruction/Data_Public.o\
./dataconstruction/Singly_Link_list.o\
./dataconstruction/Double_Link_List.o\
./dataconstruction/Stack.o\
./dataconstruction/List_Test.o\

C_DEPS += \
./dataconstruction/Data_Public.d\
./dataconstruction/Singly_Link_list.d\
./dataconstruction/Double_Link_List.d\
./dataconstruction/Stack.d\
./dataconstruction/List_Test.d\


# Each subdirectory must supply rules for building sources it contributes
dataconstruction/%.o: ../dataconstruction/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CC) -I"$(PRO_DIR)/list" -I"$(PRO_DIR)/libv2x-yt/Includes" $(EXTRA_CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


