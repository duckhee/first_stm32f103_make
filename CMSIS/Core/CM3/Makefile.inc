###########################################################
# GCC template makefile
###########################################################


STM32F10X_ASRCS = startup_stm32f10x_md.s

CM3_SRCS = 
CM3_SRCS += core_cm3.c
CM3_SRCS += system_stm32f10x.c


ASRCS += $(STM32F10X_ASRCS)
SRCS += $(CM3_SRCS)