#ifndef MAIN_H
#define MAIN_H

typedef struct vending {
	char name[16];
	char location[32];
	int index, pin, status;
} Vending;

typedef struct gpio_pin {
	char desc[16];
	unsigned int pin;
	int value;
	char opt;
} Pin;

#endif