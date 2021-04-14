# if called from kernel
ifneq ($(KERNELRELEASE),)
    obj-m := mygpio.o
# else called from terminal
else
    export ARCH=arm
    export CROSS_COMPILE=arm-linux-gnueabihf-
    KERNEL ?= /lib/modules/$(shell uname -r)/build
    PWD := $(shell pwd) 
endif

mygpio.o: mygpio.c
	$(MAKE) -C $(KERNEL) M=$(PWD) modules 
clean: 
	$(MAKE) -C $(KERNEL) M=$(PWD) clean 
