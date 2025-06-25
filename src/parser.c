#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "util.h"

#define default_file "default_sdwmrc"

/* static const char call_table[] = {{"close_window", close_focused},
                  {"decrease_gaps", dec_gaps},
                  {"focus_next", focus_next},
                  {"focus_prev", focus_prev},
                  {"focus_next_mon", focus_next_mon},
                  {"focus_prev_mon", focus_prev_mon},
                  {"increase_gaps", inc_gaps},
                  {"master_next", move_master_next},
                  {"master_previous", move_master_prev},
                  {"move_next_mon", move_next_mon},
                  {"move_prev_mon", move_prev_mon},
                  {"quit", quit},
                  {"reload_config", reload_config},
                  {"master_increase", resize_master_add},
                  {"master_decrease", resize_master_sub},
                  {"stack_increase", resize_stack_add},
                  {"stack_decrease", resize_stack_sub},
                  {"toggle_floating", toggle_floating},
                  {"global_floating", toggle_floating_global},
                  {"fullscreen", toggle_fullscreen},
                  {NULL, NULL}};
*/

void parse(void) {
	char ch;
	size_t file_size = 0;
	FILE *fptr       = fopen(default_file, "r");
	ptr_check(fptr);
	while ((ch = fgetc(fptr)) != EOF) file_size++;
	rewind(fptr);

	char *file_contents = malloc(++file_size);
	for (size_t i = 0; i < file_size; i++) {
		ch               = fgetc(fptr);
		file_contents[i] = ch;
	}
	fclose(fptr);
	printf("%s\n", file_contents);
}
