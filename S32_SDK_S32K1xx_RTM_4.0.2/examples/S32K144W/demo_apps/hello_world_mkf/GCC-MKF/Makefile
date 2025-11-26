### S32 SDK Build Makefile ###
# This makefile will build a bare metal S32 SDK application.
# Some make variables need to be defined here so make targets can be built correctly.
#
# Prerequisites:
#   - an arm toolchain
#   - GNU Make or an Unix-like environment
#
# Application specific variables that must be defined:
#   - CSOURCES, ASMSOURCES: C and assembly sources, respectively. Note: only files, without paths
#   - SOURCEDIR: Locations for all source and header files. The paths defined here will be used:
#       1)to match source files defined in CSOURCES and ASMSOURCES 
#       2)as include path for the compiler
#   - OBJECTDIR: object directory to save object and intermediate files. Objects will be generated
#       as a flat list (no subdirectories).
# Common make variables. These are recommended to be defined, but can be omitted:
#   - CFLAGS: flags to pass to the C compiler
#   - ASFLAGS: flags to pass to the assembler
#   - LDFLAGS: flags to pass to the linker
#   - EXECUTABLE: name and location of the executable (.elf file)
# Variables that define the toolchain:
#   - CC: C compiler executable
#   - AS: Assembler executable
#   - LD: Linker executable
#   - RM: removed command (default 'rm -f')
#   - CCSIZE: Size executable (prints sections sizes: text, data, bss)
#   - CCOBJDUMP: Objdump executable
#
# Most variables have default values defined, but it is recommended to define 

## Define CSOURCES and ASMSOURCES variables ##
CSOURCES:=main.c
CSOURCES+=system_S32K144W.c
CSOURCES+=startup.c
CSOURCES+=pins_driver.c
CSOURCES+=pins_port_hw_access.c
CSOURCES+=clock_S32K1xx.c
CSOURCES+=interrupt_manager.c

ASMSOURCES+=startup_S32K144W.S

## Define SOURCEDIR variable ##
# Define two helper vars, BASEDIR (SDK base) and SOURCEDIRSDK (paths inside SDK to be included/searched)
BASEDIR:=../../../../../
SOURCEDIRSDK:=platform/
SOURCEDIRSDK+=platform/drivers/src/
SOURCEDIRSDK+=platform/drivers/src/clock/
SOURCEDIRSDK+=platform/drivers/src/interrupt/
SOURCEDIRSDK+=platform/drivers/src/clock/S32K1xx/
SOURCEDIRSDK+=platform/devices/
SOURCEDIRSDK+=platform/devices/S32K144W/
SOURCEDIRSDK+=platform/devices/S32K144W/startup/
SOURCEDIRSDK+=platform/devices/S32K144W/startup/gcc/
SOURCEDIRSDK+=platform/devices/S32K144W/include/
SOURCEDIRSDK+=platform/devices/common
SOURCEDIRSDK+=platform/drivers/inc/
SOURCEDIRSDK+=platform/drivers/src/adc/
SOURCEDIRSDK+=platform/drivers/src/flash/
SOURCEDIRSDK+=platform/drivers/src/lpuart/
SOURCEDIRSDK+=platform/drivers/src/lpi2c/
SOURCEDIRSDK+=platform/drivers/src/pins/

# Location of objects and final source directories
OBJECTDIR_NAME:=obj
SOURCEDIR_NAME:=../Sources

# Assembler file extension
ASM_EXT:=S

# Map file names
MAP_RAM:=app_ram.map
MAP_FLASH:=app_flash.map

## Elf file names ##
EXECUTABLE_RAM:=app_ram.elf
EXECUTABLE_FLASH:=app_flash.elf

## Toolchain executables ##
CC:=arm-none-eabi-gcc
AS:=arm-none-eabi-gcc
LD:=arm-none-eabi-gcc
RM:=rm -f
CCSIZE:=arm-none-eabi-size

## Toolchain flags ##
CFLAGS:=-mcpu=cortex-m4 -DCPU_S32K144W -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS+=-mthumb -Werror -Wall -Wextra -Wstrict-prototypes -Wunused -Wsign-compare -pedantic -O1 -funsigned-char -funsigned-bitfields -fshort-enums -ffunction-sections -fdata-sections -fno-jump-tables -std=gnu99 -save-temps=obj -g -fno-common

ASFLAGS_RAM:= -x assembler-with-cpp
ASFLAGS_FLASH:=-x assembler-with-cpp -DSTART_FROM_FLASH

## Linker flags
LDFLAGS_RAM:=-Wl,-Map=$(MAP_RAM)
LDFLAGS_RAM+=-nostartfiles -nodefaultlibs -nostdlib -T "$(BASEDIR)\platform\devices\S32K144W\linker\gcc\S32K144W_64_ram.ld" --entry=Reset_Handler -Wl,-gc-sections
LDFLAGS_RAM+=-lgcc -lm -lc -lrdimon --specs=rdimon.specs
LDFLAGS_FLASH:=-Wl,-Map=$(MAP_FLASH)
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs -nostdlib -T "$(BASEDIR)\platform\devices\S32K144W\linker\gcc\S32K144W_64_flash.ld" --entry=Reset_Handler -Wl,-gc-sections
LDFLAGS_FLASH+=-lgcc -lm -lc -lrdimon --specs=rdimon.specs

include Makefile-arm
