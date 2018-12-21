###########################################################
# GCC template makefile
###########################################################


STM32F10X_DRV_ASRCS = 

STM32F10X_DRV_SRCS = misc.c
STM32F10X_DRV_SRCS += stm32f10x_adc.c
STM32F10X_DRV_SRCS += stm32f10x_bkp.c
STM32F10X_DRV_SRCS += stm32f10x_can.c
STM32F10X_DRV_SRCS += stm32f10x_crc.c
STM32F10X_DRV_SRCS += stm32f10x_dac.c
STM32F10X_DRV_SRCS += stm32f10x_dbgmcu.c
STM32F10X_DRV_SRCS += stm32f10x_dma.c
STM32F10X_DRV_SRCS += stm32f10x_exti.c
STM32F10X_DRV_SRCS += stm32f10x_flash.c
STM32F10X_DRV_SRCS += stm32f10x_fsmc.c
STM32F10X_DRV_SRCS += stm32f10x_gpio.c
STM32F10X_DRV_SRCS += stm32f10x_i2c.c
STM32F10X_DRV_SRCS += stm32f10x_iwdg.c
STM32F10X_DRV_SRCS += stm32f10x_pwr.c
STM32F10X_DRV_SRCS += stm32f10x_rcc.c
STM32F10X_DRV_SRCS += stm32f10x_rtc.c
STM32F10X_DRV_SRCS += stm32f10x_sdio.c
STM32F10X_DRV_SRCS += stm32f10x_spi.c
STM32F10X_DRV_SRCS += stm32f10x_tim.c
STM32F10X_DRV_SRCS += stm32f10x_usart.c
STM32F10X_DRV_SRCS += stm32f10x_wwdg.c

ASRCS += $(STM32F10X_DRV_ASRCS)
SRCS += $(STM32F10X_DRV_SRCS)

