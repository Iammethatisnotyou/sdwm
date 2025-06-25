#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void panic(char *msg) {
	puts(msg);
	exit(EXIT_FAILURE);
}
void die(const char *msg) {
	if (msg[0] && msg[strlen(msg) - 1] == ':') {
		fprintf(stderr, "%s\n", msg);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}
void ptr_check(void *ptr) {
	if (ptr == NULL) {
		perror("ERROR: Can't allocate memory");
		exit(2);
	}
}
