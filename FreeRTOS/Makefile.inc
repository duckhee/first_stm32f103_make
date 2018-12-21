###########################################################
# GCC template makefile
###########################################################



FREE_RTOS_SRCS =
FREE_RTOS_SRCS += croutine.c
FREE_RTOS_SRCS += list.c
FREE_RTOS_SRCS += queue.c
FREE_RTOS_SRCS += tasks.c

SRCS += $(FREE_RTOS_SRCS)