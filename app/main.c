#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <openssl/aes.h> /* file ecnryption */
//#include <openssl/evp.h> /* password hash */
#include "main.h"
#include "web.h"

#define max_machines 5
int machine_count = 0;

const char fname[] = "data/machines.json";
/* json file format */
const char* json_in =
    "\n\t\t\t\"index\": %d,\n\t\t\t\"name\": \"%[^\"]\",\n\t\t\t\"location\": \"%[^\"]\",\n\t\t\t\"pin\": %d,\n\t\t\t\"status\": %d";
const char* json_out =
    "\n\t\t{\n\t\t\t\"index\": %d,\n\t\t\t\"name\": \"%s\",\n\t\t\t\"location\": \"%s\",\n\t\t\t\"pin\": %d,\n\t\t\t\"status\": %d\n\t\t}";

//unsigned char *get_password();
//void test(FILE **ifp);
/*struct ctr_state
{
	unsigned char ivec[AES_BLOCK_SIZE]; // AES_BLOCK_SIZE = 16 for 128-bit block
    unsigned int num;
    unsigned char ecount[AES_BLOCK_SIZE];
};*/

void print_home() {
	system("clear");
 	printf("=========================================================\n");
 	printf("|            VENDING MACHINE CONTROL CONSOLE            |\n");
 	printf("|-------------------------------------------------------|\n");
 	printf("| Author: Joshua Talbot             Student ID: 1602114 |\n");
 	printf("|=======================================================|\n");
 	printf("| 1. SHOW Machines                 2. SEARCH by Index   |\n");
 	printf("| 3. ADD Machine                   4. DELETE Machine    |\n");
 	printf("| 5. UPDATE Status                 0. EXIT              |\n");
 	printf("=========================================================\n");
}

void print_machine(Vending* m, int i) {
	printf("MACHINE %d\n",   m[i].index);
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
		exit(-1);
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
		exit(-1);
	} else {
		/* write json start */
		fprintf(vendir, "{\n\t\"vendor\": [");

		/* write machine data */
		int i;
		for (i = 0; i < machine_count; i++) {
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

		if (strlen(buffer) == 0) {
			printf("> ERROR: NULL input\n");
		}
		else if (buffer[strlen(buffer)-1] != '\n') {
			// get EOF/NL to consume input 
			int c;
			for (c = 0; (c = getchar()) != EOF && c != '\n';);
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
	char buffer[50];

	do {
		printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
		if (strlen(buffer) == 0) {
			printf("> ERROR: NULL input\n");
		}
		else if (buffer[strlen(buffer)-1] != '\n') {
			// get EOF / NL to consume input 
			int c;
			for (c = 0; (c = getchar()) != EOF && c != '\n';);
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

void display_menu(Vending* machine, int command) {
	switch (command) {
		case 1: // show all machines
			if (machine_count == 0) {
				printf("> ERROR: No Machines available\n");
			} else {
				int i;
				for (i = 0; i < machine_count; i++) {
					print_machine(machine, i);
				}
			}
		break;

		case 2: // show machine
			if (machine_count == 0) {
				printf("> ERROR: No Machines available\n");
			} else {
				int x = check_int(1, machine_count, "Machine Index: ");
				print_machine(machine, x-1);
			}
		break;
	
		case 3: // add machine
			if (machine_count == max_machines) {
				printf("> ERROR: No machines are available\n");
			} else {
				int x = machine_count;
				machine[x].index = x+1;
	
				printf("MACHINE[%d]\n", machine[x].index);
	
				strcpy(machine[x].name, check_char(sizeof(machine[x].name), "Enter name: "));
				strcpy(machine[x].location, check_char(32, "Enter location: "));
				machine[x].pin = check_int(0, 27, "Enter Pin: ");
				machine[x].status = check_int(0, 1, "Enter Status: ");
	
				printf("\n");
				print_machine(machine, x);

				machine_count++;
				set_machines(machine);
			}
		break;
	
		case 4: // del machine
			if (machine_count == 0) {
				printf("> ERROR: No Machines available\n");
			} else {
				int x = check_int(1, machine_count, "Machine Index: ");
				x--;
	
				int i;
				for (i = 0; i < machine_count; i++) {
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

		case 5: // set machine status
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
}

int main(int argc, char** argv) {
	/* initialization */
	Vending machine[max_machines] = {{"", "", 0, 0, 0}};
	get_machines(machine);
	
	if (argc == 1) {

		int command;
		do {
			web_print_header();

			printf("<h1>Error World!</h1>");
			return 1;

			//system("clear");
			print_home();
			command = check_int(0, 5, "Enter command (0-5): ");
		
			system("clear");
			display_menu(machine, command);
			//display_menu(machine, command, message);

			printf("Please press ENTER to continue ");
			while ((getchar()) != '\n');
			system("clear");
		} while (command != 0);
	} else {
		/*for (int i=1; i < argc; i++){
			printf("arg: %s", argv[i]);
		}*/
		web_print_header();

		printf("<h1>Hello World!</h1>");
		return 1;
	}

	return 0;
}

/*
unsigned char *get_password() {
	int ITERATION = 512000; 

	// this will be the result of PBKDF2-HMAC-SHA1  
	int SHA1_LEN = 16;
	unsigned char* out = (unsigned char*)calloc(SHA1_LEN, sizeof(unsigned char));

	int SALT_LEN = 10;
	unsigned char* salt = "asdf1234a";
	//unsigned char* salt = (unsigned char*)calloc(SALT_LEN, sizeof(unsigned char));
	//RAND_bytes(salt, SALT_LEN);

	char* pwd = check_char(19, "password: "); //your password here
	PKCS5_PBKDF2_HMAC_SHA1(pwd, strlen(pwd), salt, SALT_LEN, ITERATION, SHA1_LEN, out);	

	return out;
}

void test() {
	// input password
	// hash password to 16-bit length (must be repeatable for PHP)
	// check password / decryption attempt
	// decrypt file to memory
	// encrypt memory and write to file
	
	FILE* vendir = fopen(fname, "rwb"); // "b" required for windows

	if (vendir == NULL) {
		fprintf(stderr, "> ERROR: Unable to locate file '%s'\n", fname); 
	} else {
		// set encryption key
		AES_KEY key;

		// initialize encryption data
		int bytes_read, bytes_written;
		unsigned char indata[AES_BLOCK_SIZE];
		unsigned char outdata[AES_BLOCK_SIZE];
		unsigned char iv[AES_BLOCK_SIZE];
		struct ctr_state state;

		// en-derecryption keys TODO: random ivec function
		unsigned char ckey[] = "thiskeyisverybad";
		unsigned char ivec[] = "dontusethisinput";

		// write json start
		fprintf(vendir, "{\n\t\"vendor\": [");

		// write machine data
		for (int i = 0; i < machine_count; i++) {
			fprintf(vendir, json_out, m[i].index, m[i].name, m[i].location, m[i].pin, m[i].status);
	
			if (i < machine_count-1) {
				fprintf(vendir, "%s", ",");
			}
		}

		// write json end
		fprintf(vendir, "\n\t]\n}");
	}
	test(&vendir);
	fclose(vendir);

	// set the encryption key
	AES_set_encrypt_key(ckey, 128, &key);

	int num = 0;

	FILE *ofp = fopen("data/output_file", "wb");

	while(1) {
		bytes_read = fread(indata, 1, AES_BLOCK_SIZE, *ifp);

		AES_cfb128_encrypt(indata, indata, bytes_read, &key, ivec, &num, AES_ENCRYPT);

		bytes_written = fwrite(indata, 1, bytes_read, *ifp);
		if (bytes_read < AES_BLOCK_SIZE)
		break;
	}
	fclose(ofp);
}*/
