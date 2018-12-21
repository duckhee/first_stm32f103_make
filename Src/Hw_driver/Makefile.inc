###########################################################
# GCC template makefile
###########################################################


HW_DRIVER_SRCS = 
HW_DRIVER_SRCS += key.c
HW_DRIVER_SRCS += led.c
HW_DRIVER_SRCS += seven_segment.c
HW_DRIVER_SRCS += zigbee_test.c


SRCS += $(HW_DRIVER_SRCS)