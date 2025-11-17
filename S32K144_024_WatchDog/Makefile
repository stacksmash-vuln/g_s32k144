# Toolchain
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

SDK_ROOT = /home/ijk5201/S32_SDK_S32K1xx_RTM_4.0.2

# Target MCU
MCU     = cortex-m4

# ---- Compile & Link Flags ----


CFLAGS  = -mcpu=$(MCU) -mthumb -O2 -ffreestanding -fno-builtin \
          -mfpu=fpv4-sp-d16 -mfloat-abi=softfp \
          -Wall -Wextra \
          -DCPU_S32K144HFT0VLLT \
          -DUSING_OS_FREERTOS \
          -I./Sources \
          -I./Sources/FreeMASTER \
          -I./Sources/FreeMASTER/src_common \
          -I./Generated_Code \
          -I../S32K144_003_new_project/s32k144_test_project_1/Project_Settings/Startup_Code \
          -I$(SDK_ROOT)/platform/devices \
          -I$(SDK_ROOT)/platform/devices/common \
          -I$(SDK_ROOT)/platform/devices/S32K144/include \
          -I$(SDK_ROOT)/platform/drivers/inc \
          -I$(SDK_ROOT)/rtos/osif \
          -I$(SDK_ROOT)/platform/devices/S32K144/startup \
          -I$(SDK_ROOT)/rtos/FreeRTOS_S32K/Source/include \
          -I$(SDK_ROOT)/rtos/FreeRTOS_S32K/Source/portable/GCC/ARM_CM4F \
          -I$(SDK_ROOT)/examples/S32K144/demo_apps/freemaster/FreeMASTER/src_platforms/S32xx

LDFLAGS = -mcpu=$(MCU) -mthumb \
          -mfpu=fpv4-sp-d16 -mfloat-abi=softfp \
          -specs=nosys.specs -Wl,--gc-sections \
          -T ../S32K144_003_new_project/s32k144_test_project_1/Project_Settings/Linker_Files/S32K144_64_flash.ld

# ---- Sources ----

FREERTOS_DIR := $(SDK_ROOT)/rtos/FreeRTOS_S32K/Source

FREERTOS_SRCS := \
  $(wildcard $(FREERTOS_DIR)/*.c) \
  $(wildcard $(FREERTOS_DIR)/portable/GCC/ARM_CM4F/*.c) \
  $(FREERTOS_DIR)/portable/MemMang/heap_4.c

DRV_DIR := $(SDK_ROOT)/platform/drivers/src

SDK_SRCS := \
  $(wildcard $(DRV_DIR)/**/*.c) \

SRCS = \
  Sources/main.c \
  Sources/rtos.c \
  Sources/wdg_lld.c \
  Sources/lpuart_lld.c \
  Sources/rtc_lld.c \
  Sources/adc_lld.c \
  Sources/lpit_lld.c \
  Sources/printf.c \
  Sources/FreeMASTER/src_common/freemaster_sfio.c \
  Sources/FreeMASTER/src_common/freemaster_scope.c \
  Sources/FreeMASTER/src_common/freemaster_serial.c \
  Sources/FreeMASTER/src_common/freemaster_bdm.c \
  Sources/FreeMASTER/src_common/freemaster_protocol.c \
  Sources/FreeMASTER/src_common/freemaster_can.c \
  Sources/FreeMASTER/src_common/freemaster_lin.c \
  Sources/FreeMASTER/src_common/freemaster_rec.c \
  Sources/FreeMASTER/src_common/freemaster_pipes.c \
  Sources/FreeMASTER/src_common/freemaster_tsa.c \
  Sources/FreeMASTER/src_common/freemaster_appcmd.c \
  Generated_Code/Cpu.c \
  Generated_Code/pin_mux.c \
  Generated_Code/dmaController1.c \
  Generated_Code/lpit1.c \
  Generated_Code/pdb1.c \
  Generated_Code/adConv1.c \
  Generated_Code/watchdog1.c \
  Generated_Code/rtcTimer1.c \
  Generated_Code/lpuart1.c \
  Generated_Code/clockMan1.c \
  ../S32K144_003_new_project/s32k144_test_project_1/Project_Settings/Startup_Code/system_S32K144.c \
  ../S32K144_003_new_project/s32k144_test_project_1/Project_Settings/Startup_Code/startup.c \
   $(FREERTOS_SRCS) \
   $(SDK_SRCS)


OSIF_DIR  := $(SDK_ROOT)/rtos/osif
OSIF_SRCS := \
    $(OSIF_DIR)/osif_freertos.c

SRCS += $(OSIF_SRCS)

CLOCK_DIR  := $(SDK_ROOT)/platform/drivers/src/clock
CLOCK_SRCS := $(wildcard $(CLOCK_DIR)/*.c)

SRCS += $(CLOCK_SRCS)

CFLAGS += -I$(FREERTOS_DIR)/include
CFLAGS += -I$(FREERTOS_DIR)/portable/GCC/ARM_CM4F
CFLAGS += -I$(PROJECT_ROOT)/rtos_config

SRCS += Sources/rtc_user.c

CLOCK_MGR_SRCS := \
    $(SDK_ROOT)/platform/drivers/src/clock/S32K1xx/clock_S32K1xx.c

SRCS += $(CLOCK_MGR_SRCS) $(CLOCK_DEV_SRCS)


ENET_DIR  := $(SDK_ROOT)/platform/drivers/src/enet
ENET_SRCS := $(wildcard $(ENET_DIR)/*.c)

SRCS := $(filter-out $(ENET_SRCS), $(SRCS))

QSPI_FLASH_DIR := $(SDK_ROOT)/platform/drivers/src/flash_mx25l6433f
QSPI_CORE_DIR  := $(SDK_ROOT)/platform/drivers/src/quadspi   # 있으면

QSPI_SRCS := $(wildcard $(QSPI_FLASH_DIR)/*.c) \
             $(wildcard $(QSPI_CORE_DIR)/*.c)

SRCS := $(filter-out $(QSPI_SRCS), $(SRCS))

LIN_DIR  := $(SDK_ROOT)/platform/drivers/src/lin
LIN_SRCS := $(wildcard $(LIN_DIR)/*.c)

SRCS := $(filter-out $(LIN_SRCS), $(SRCS))

PHY_DIR  := $(SDK_ROOT)/platform/drivers/src/phy
PHY_SRCS := $(wildcard $(PHY_DIR)/*.c)

SRCS := $(filter-out $(PHY_SRCS), $(SRCS))

QUADSPI_DIR  := $(SDK_ROOT)/platform/drivers/src/quadspi
QUADSPI_SRCS := $(wildcard $(QUADSPI_DIR)/*.c)

SRCS := $(filter-out $(QUADSPI_SRCS), $(SRCS))

SAI_DIR  := $(SDK_ROOT)/platform/drivers/src/sai
SAI_SRCS := $(wildcard $(SAI_DIR)/*.c)

SRCS := $(filter-out $(SAI_SRCS), $(SRCS))


OBJS = $(SRCS:.c=.o) startup_S32K144.o

TARGET = S32K144_024_WatchDog

# ---- Rules ----

all: $(TARGET).elf $(TARGET).bin

# C compile
%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

# Startup assembly (.S = preprocessed asm)
startup_S32K144.o: ../S32K144_003_new_project/s32k144_test_project_1/Project_Settings/Startup_Code/startup_S32K144.S
        $(CC) -mcpu=$(MCU) -mthumb -c $< -o $@

# Link
$(TARGET).elf: $(OBJS)
        $(CC) $(LDFLAGS) $(OBJS) -o $@

# Binary for flashing
$(TARGET).bin: $(TARGET).elf
        $(OBJCOPY) -O binary $< $@

clean:
        rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

                                                                                                                                                                                                      171,0-1       Bot
