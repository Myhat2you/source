#make /home/cmp408/tools/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc piiotest.c
PWD := $(shell pwd) 

all: piiotest.c
	arm-linux-gnueabihf-gcc -g -Wall -o piiotest piiotest.c

clean: 
	$(RM) piiotest
