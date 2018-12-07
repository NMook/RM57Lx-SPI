################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
hcg/source/%.obj: ../hcg/source/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 --abi=eabi -me --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/include" --include_path="C:/Users/nlcmo/workspace_v8/project1/RM57Lx-SPI/INBIT_SPI/hcg/include" --include_path="C:/Users/nlcmo/workspace_v8/project1/RM57Lx-SPI/INBIT_SPI/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.3.1/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.3.1/safety_library/include" -g --define=_RM57Lx_ --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --preproc_with_compile --preproc_dependency="hcg/source/$(basename $(<F)).d_raw" --obj_directory="hcg/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

hcg/source/%.obj: ../hcg/source/%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 --abi=eabi -me --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/include" --include_path="C:/Users/nlcmo/workspace_v8/project1/RM57Lx-SPI/INBIT_SPI/hcg/include" --include_path="C:/Users/nlcmo/workspace_v8/project1/RM57Lx-SPI/INBIT_SPI/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.3.1/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.3.1/safety_library/include" -g --define=_RM57Lx_ --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --preproc_with_compile --preproc_dependency="hcg/source/$(basename $(<F)).d_raw" --obj_directory="hcg/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


