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
CSOURCES+=system_S32K118.c
CSOURCES+=startup.c

ASMSOURCES+=startup_S32K118.s

## Define SOURCEDIR variable ##
# Define two helper vars, BASEDIR (SDK base) and SOURCEDIRSDK (paths inside SDK to be included/searched)
BASEDIR:=../../../../../
SOURCEDIRSDK:=platform/
SOURCEDIRSDK+=platform/drivers/src/
SOURCEDIRSDK+=platform/drivers/src/clock/
SOURCEDIRSDK+=platform/drivers/src/interrupt/
SOURCEDIRSDK+=platform/drivers/src/clock/S32K1xx/
SOURCEDIRSDK+=platform/devices/
SOURCEDIRSDK+=platform/devices/S32K118/
SOURCEDIRSDK+=platform/devices/S32K118/startup/
SOURCEDIRSDK+=platform/devices/S32K118/startup/iar/
SOURCEDIRSDK+=platform/devices/S32K118/include/
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
ASM_EXT:=s

# Map file names
MAP_RAM:=app_ram.map
MAP_FLASH:=app_flash.map

## Elf file names ##
EXECUTABLE_RAM:=app_ram.elf
EXECUTABLE_FLASH:=app_flash.elf

## Toolchain executables ##
CC:=iccarm
AS:=iasmarm
LD:=ilinkarm

## Toolchain flags ##
CFLAGS:=-Ol -e --cpu=Cortex-M0+ --cpu_mode=thumb --no_wrap_diagnostics --debug -DCPU_S32K118
ASFLAGS_RAM:= --thumb --cpu Cortex-M0+
ASFLAGS_FLASH:= --thumb --cpu Cortex-M0+ -DSTART_FROM_FLASH

LDFLAGS_RAM:=--no_wrap_diagnostics --config "$(BASEDIR)\platform\devices\S32K118\linker\iar\S32K118_25_ram.icf"
LDFLAGS_RAM+= --map $(MAP_RAM) --entry Reset_Handler 
LDFLAGS_FLASH:=--no_wrap_diagnostics --config "$(BASEDIR)\platform\devices\S32K118\linker\iar\S32K118_25_flash.icf"
LDFLAGS_FLASH+= --map $(MAP_FLASH) --entry Reset_Handler 

include Makefile-arm
