########################################################################################
# GCC template makefile
########################################################################################

SRC_SOURCES = 
SRC_SOURCES += main.c
SRC_SOURCES += debug.c
SRC_SOURCES += hw_config.c
SRC_SOURCES += stm32f10x_it.c
SRC_SOURCES += syscalls.c


SRCS += $(SRC_SOURCES)