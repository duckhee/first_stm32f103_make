###########################################################
# GCC template makefile
###########################################################


STM32F10X_USB_SRC = usb_core.c
STM32F10X_USB_SRC += usb_init.c
STM32F10X_USB_SRC += usb_int.c
STM32F10X_USB_SRC += usb_mem.c
STM32F10X_USB_SRC += usb_regs.c


SRCS += $(STM32F10X_USB_SRC)