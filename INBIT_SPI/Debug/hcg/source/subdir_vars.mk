################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../hcg/source/HL_sys_link.cmd 

ASM_SRCS += \
../hcg/source/HL_sys_core.asm \
../hcg/source/HL_sys_intvecs.asm \
../hcg/source/HL_sys_mpu.asm \
../hcg/source/HL_sys_pmu.asm 

C_SRCS += \
../hcg/source/HL_adc.c \
../hcg/source/HL_epc.c \
../hcg/source/HL_errata.c \
../hcg/source/HL_esm.c \
../hcg/source/HL_gio.c \
../hcg/source/HL_mibspi.c \
../hcg/source/HL_nmpu.c \
../hcg/source/HL_notification.c \
../hcg/source/HL_pinmux.c \
../hcg/source/HL_rti.c \
../hcg/source/HL_sci.c \
../hcg/source/HL_sys_dma.c \
../hcg/source/HL_sys_pcr.c \
../hcg/source/HL_sys_phantom.c \
../hcg/source/HL_sys_pmm.c \
../hcg/source/HL_sys_startup.c \
../hcg/source/HL_sys_vim.c \
../hcg/source/HL_system.c 

C_DEPS += \
./hcg/source/HL_adc.d \
./hcg/source/HL_epc.d \
./hcg/source/HL_errata.d \
./hcg/source/HL_esm.d \
./hcg/source/HL_gio.d \
./hcg/source/HL_mibspi.d \
./hcg/source/HL_nmpu.d \
./hcg/source/HL_notification.d \
./hcg/source/HL_pinmux.d \
./hcg/source/HL_rti.d \
./hcg/source/HL_sci.d \
./hcg/source/HL_sys_dma.d \
./hcg/source/HL_sys_pcr.d \
./hcg/source/HL_sys_phantom.d \
./hcg/source/HL_sys_pmm.d \
./hcg/source/HL_sys_startup.d \
./hcg/source/HL_sys_vim.d \
./hcg/source/HL_system.d 

OBJS += \
./hcg/source/HL_adc.obj \
./hcg/source/HL_epc.obj \
./hcg/source/HL_errata.obj \
./hcg/source/HL_esm.obj \
./hcg/source/HL_gio.obj \
./hcg/source/HL_mibspi.obj \
./hcg/source/HL_nmpu.obj \
./hcg/source/HL_notification.obj \
./hcg/source/HL_pinmux.obj \
./hcg/source/HL_rti.obj \
./hcg/source/HL_sci.obj \
./hcg/source/HL_sys_core.obj \
./hcg/source/HL_sys_dma.obj \
./hcg/source/HL_sys_intvecs.obj \
./hcg/source/HL_sys_mpu.obj \
./hcg/source/HL_sys_pcr.obj \
./hcg/source/HL_sys_phantom.obj \
./hcg/source/HL_sys_pmm.obj \
./hcg/source/HL_sys_pmu.obj \
./hcg/source/HL_sys_startup.obj \
./hcg/source/HL_sys_vim.obj \
./hcg/source/HL_system.obj 

ASM_DEPS += \
./hcg/source/HL_sys_core.d \
./hcg/source/HL_sys_intvecs.d \
./hcg/source/HL_sys_mpu.d \
./hcg/source/HL_sys_pmu.d 

OBJS__QUOTED += \
"hcg\source\HL_adc.obj" \
"hcg\source\HL_epc.obj" \
"hcg\source\HL_errata.obj" \
"hcg\source\HL_esm.obj" \
"hcg\source\HL_gio.obj" \
"hcg\source\HL_mibspi.obj" \
"hcg\source\HL_nmpu.obj" \
"hcg\source\HL_notification.obj" \
"hcg\source\HL_pinmux.obj" \
"hcg\source\HL_rti.obj" \
"hcg\source\HL_sci.obj" \
"hcg\source\HL_sys_core.obj" \
"hcg\source\HL_sys_dma.obj" \
"hcg\source\HL_sys_intvecs.obj" \
"hcg\source\HL_sys_mpu.obj" \
"hcg\source\HL_sys_pcr.obj" \
"hcg\source\HL_sys_phantom.obj" \
"hcg\source\HL_sys_pmm.obj" \
"hcg\source\HL_sys_pmu.obj" \
"hcg\source\HL_sys_startup.obj" \
"hcg\source\HL_sys_vim.obj" \
"hcg\source\HL_system.obj" 

C_DEPS__QUOTED += \
"hcg\source\HL_adc.d" \
"hcg\source\HL_epc.d" \
"hcg\source\HL_errata.d" \
"hcg\source\HL_esm.d" \
"hcg\source\HL_gio.d" \
"hcg\source\HL_mibspi.d" \
"hcg\source\HL_nmpu.d" \
"hcg\source\HL_notification.d" \
"hcg\source\HL_pinmux.d" \
"hcg\source\HL_rti.d" \
"hcg\source\HL_sci.d" \
"hcg\source\HL_sys_dma.d" \
"hcg\source\HL_sys_pcr.d" \
"hcg\source\HL_sys_phantom.d" \
"hcg\source\HL_sys_pmm.d" \
"hcg\source\HL_sys_startup.d" \
"hcg\source\HL_sys_vim.d" \
"hcg\source\HL_system.d" 

ASM_DEPS__QUOTED += \
"hcg\source\HL_sys_core.d" \
"hcg\source\HL_sys_intvecs.d" \
"hcg\source\HL_sys_mpu.d" \
"hcg\source\HL_sys_pmu.d" 

C_SRCS__QUOTED += \
"../hcg/source/HL_adc.c" \
"../hcg/source/HL_epc.c" \
"../hcg/source/HL_errata.c" \
"../hcg/source/HL_esm.c" \
"../hcg/source/HL_gio.c" \
"../hcg/source/HL_mibspi.c" \
"../hcg/source/HL_nmpu.c" \
"../hcg/source/HL_notification.c" \
"../hcg/source/HL_pinmux.c" \
"../hcg/source/HL_rti.c" \
"../hcg/source/HL_sci.c" \
"../hcg/source/HL_sys_dma.c" \
"../hcg/source/HL_sys_pcr.c" \
"../hcg/source/HL_sys_phantom.c" \
"../hcg/source/HL_sys_pmm.c" \
"../hcg/source/HL_sys_startup.c" \
"../hcg/source/HL_sys_vim.c" \
"../hcg/source/HL_system.c" 

ASM_SRCS__QUOTED += \
"../hcg/source/HL_sys_core.asm" \
"../hcg/source/HL_sys_intvecs.asm" \
"../hcg/source/HL_sys_mpu.asm" \
"../hcg/source/HL_sys_pmu.asm" 


