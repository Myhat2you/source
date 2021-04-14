#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define max_machines 5
int machine_count = 0;

const char fname[] = "data/machines.json";
/* json file format */
const char* json_in =
    "\n\t\t\t\"index\": %d,\n\t\t\t\"name\": \"%[^\"]\",\n\t\t\t\"location\": \"%[^\"]\",\n\t\t\t\"pin\": %d,\n\t\t\t\"status\": %d";
const char* json_out =
    "\n\t\t{\n\t\t\t\"index\": %d,\n\t\t\t\"name\": \"%s\",\n\t\t\t\"location\": \"%s\",\n\t\t\t\"pin\": %d,\n\t\t\t\"status\": %d\n\t\t}";

void print_machine(Vending *m, int i);
void get_machines(Vending *m);
void set_machines(Vending *m);
char *check_char(int size, char prompt[]);
int check_int(int min, int max, char prompt[]);

int main() {
	/* initialization */
	Vending machine[max_machines] = {"", "", 0, 0, 0};;
	get_machines(machine);
	int command;

	//system("clear");

	do {
		display_menu();
		command = check_int(0, 5, "Enter command (0-5): ");
		system("clear");

		switch (command) {
			case 1: /* show all machines */
				if (machine_count == 0) {
					printf("> ERROR: No Machines available\n");
				} else {
					for (int i = 0; i < machine_count; i++) {
						print_machine(machine, i);
					}
				}
				break;
	
			case 2: /* show machine */
				if (machine_count == 0) {
					printf("> ERROR: No Machines available\n");
				} else {
					int x = check_int(1, machine_count, "Machine Index: ");
					print_machine(machine, x-1);
				}
				break;
	
			case 3: /* add machine */
				if (machine_count == max_machines) {
					printf("> ERROR: No machines are available\n");
				} else {
					int x = machine_count;
					machine[x].index = x+1;
		
					printf("MACHINE[%d]\n", machine[x].index);
		
					strcpy(machine[x].name, check_char(sizeof(machine[x].name), "Enter name: "));
					strcpy(machine[x].location, check_char(32, "Enter location: "));
					machine[x].pin = check_int(1, max_machines, "Enter Pin: ");
					machine[x].status = check_int(0, 1, "Enter Status: ");
		
					printf("\n");
					print_machine(machine, x);

					machine_count++;
					set_machines(machine);
				}
				break;
	
			case 4: /* del machine */
				if (machine_count == 0) {
					printf("> ERROR: No Machines available\n");
				} else {
					int x = check_int(1, machine_count, "Machine Index: ");
					x--;
		
					for (int i = 0; i < machine_count; i++) {
						if (i >= x) {
							strcpy(machine[i].name, machine[i+1].name);
							strcpy(machine[i].location, machine[i+1].location);
							machine[i].pin = machine[i+1].pin;
							machine[i].status = machine[i+1].status;
						}
					}
		
					machine_count--;
					set_machines(machine);
		
					printf("Machine[%d] deleted\n\n", x+1);
				}
				break;
	
			case 5: /* set machine status */
				if (machine_count == 0) {
					printf("> ERROR: No Machines available\n");
				} else {
					int x = check_int(1, machine_count, "Machine Index: ");
					machine[x-1].status = check_int(0, 1, "Enter Status: ");
		
					set_machines(machine);
		
					if (machine[x-1].status == 1) {
						printf("Machine[%d] on\n\n", x);
					} else {
						printf("Machine[%d] off\n\n", x);
					}
				}
				break;
		}

		printf("Please press ENTER to continue ");
		while ((getchar()) != '\n');
		system("clear");

	} while (command != 0);

	return 0;
}

void display_menu() {
	system("clear");
 	printf("=========================================================");
 	printf("\n|            VENDING MACHINE CONTROL CONSOLE            |");
 	printf("\n|-------------------------------------------------------|");
 	printf("\n| Author: Joshua Talbot             Student ID: 1602114 |");
 	printf("\n|=======================================================|");
 	printf("\n| 1. Show Machines                 2. Search by Index   |");
 	printf("\n| 3. Add Machine                   4. Del Machine       |");
 	printf("\n| 5. Update Status                 0. EXIT              |");
 	printf("\n=========================================================");
}

void print_machine(Vending* m, int i) {
	printf("MACHINE[%d]\n", m[i].index);
	printf("Name:     %s\n", m[i].name);
	printf("Location: %s\n", m[i].location);
	printf("Pin:      %d\n", m[i].pin);
	printf("Status:   %d\n", m[i].status);
	printf("\n");
}

void get_machines(Vending* m) {
	FILE* vendir = fopen(fname, "r");

	if (vendir == NULL) {
		fprintf(stderr, "> ERROR: Unable to locate file '%s'\n", fname); 
	} else {
		char buffer[200];

		fseek(vendir, 14, SEEK_SET); 

		while (!feof(vendir)) {
			int i = machine_count;

			fgets(buffer, 200, vendir);

			if (strpbrk(buffer, "{") != 0) {
				fscanf(vendir, json_in, &m[i].index, &m[i].name, &m[i].location, &m[i].pin, &m[i].status);
				machine_count++;
			}
		}
	}
	fclose(vendir);
}

void set_machines(Vending* m) {
	FILE* vendir = fopen(fname, "w");

	if (vendir == NULL) {
		fprintf(stderr, "> ERROR: Unable to locate file '%s'\n", fname); 
	} else {
		/* write json start */
		fprintf(vendir, "{\n\t\"vendor\": [");

		/* write machine data */
		for (int i = 0; i < machine_count; i++) {
			fprintf(vendir, json_out, m[i].index, m[i].name, m[i].location, m[i].pin, m[i].status);
	
			if (i < machine_count-1) {
				fprintf(vendir, "%s", ",");
			}
		}

		/* write json end */
		fprintf(vendir, "\n\t]\n}");
	}
	fclose(vendir);
}

/* TODO dealloc after return? */
char *check_char(int size, char prompt[]) {
	char *input = malloc(size);
	char buffer[size];

	do {
		printf("%s", prompt);
		fgets(buffer, size, stdin);

		if (buffer == NULL) {
			printf("> ERROR: NULL input\n");
		}
		else if (buffer[strlen(buffer)-1] != '\n') {
			// get EOF / NL to consume input 
			for (int c; (c = getchar()) != EOF && c != '\n';);
			printf("> ERROR: Input too long\n");
		}
		else if (strlen(buffer) > size) {
			printf("> ERROR: INPUT TOO LONG\n");
		}
		else if (sscanf(buffer, "%s", input) != 1) {
			printf("> ERROR: Invalid input\n");
		}

	} while (input[0] == '\0');

	return input;
}

int check_int(int min, int max, char prompt[]) {
	int input = -1;
	char buffer[4];

	do {
		printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);

		if (buffer == NULL) {
			printf("> ERROR: NULL input\n");
		}
		else if (buffer[strlen(buffer)-1] != '\n') {
			// get EOF / NL to consume input 
			for (int c; (c = getchar()) != EOF && c != '\n';);
			printf("> ERROR: Input too long\n");
		}
		else if (sscanf(buffer, "%d", &input) != 1) {
			printf("> ERROR: Invalid input\n");
		}
		else if (input < min || input > max) {
			printf("> ERROR: Option not available\n");
			input = -1;
		}
	} while (input == -1);

	return input;
}
