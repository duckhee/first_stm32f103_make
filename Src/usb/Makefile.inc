###########################################################
# GCC template makefile
###########################################################

HW_USB_SRCS = usb_desc.c
HW_USB_SRCS += usb_endp.c
HW_USB_SRCS += usb_istr.c
HW_USB_SRCS += usb_prop.c
HW_USB_SRCS += usb_pwr.c


SRCS += $(HW_USB_SRCS)