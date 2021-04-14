# if called from kernel
ifneq ($(KERNELRELEASE),)
    obj-m := piio.o
# else called from terminal
else
    export ARCH=arm
    export CROSS_COMPILE=arm-linux-gnueabihf-
    KERNEL ?= /lib/modules/$(shell uname -r)/build
    PWD := $(shell pwd) 
endif

all: piiotest.c
	$(MAKE) -C $(KERNEL) M=$(PWD) modules 
clean: 
	$(MAKE) -C $(KERNEL) M=$(PWD) clean 
