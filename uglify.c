#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_SIZE 512

int main(int argc, const char** argv) {
	if (argc < 2) {
		printf("USAGE: %s [FILENAME] [NEW FILENAME]\n\nIf no new name is provided, the original file will be overwritten.\n", argv[0]);
		return EXIT_SUCCESS;
	}

	// Step one: loop through the code:
	FILE* fptr = fopen(argv[1], "r");
		
	if (fptr == NULL) {
		printf("ERROR: %s does not exist. Exiting...\n", argv[1]);
		return EXIT_SUCCESS;
	}

	// We need to know the size of the file to know how big the final things should be.
	
	fseek(fptr, 0L, SEEK_END);
	int size = ftell(fptr);

	char *data = malloc(size);
	char tmp[LINE_SIZE];
	while (fgets(tmp, LINE_SIZE, fptr)) {
		tmp[strcspn(tmp, "\n")] = 0x00;
		// Remove starting whitespace:
		int count = strspn(tmp, "\t");
		char final[LINE_SIZE];
		if (count != 0) {
			strcpy(final, &tmp[count]);
		} else {
			strcpy(final, tmp);
		}
		// Is it a comment?
		if (final[0] != '/' && final[1] != '/') {
			strcat(data, final); // Append the value of final to data, with no line break.
		}
	}	
	fclose(fptr);
	// Figure out what file to write to
	FILE* newfp;
	if (argc > 2) {
		newfp = fopen(argv[2], "w");
	} else {
		newfp = fopen(argv[1], "w");
	}
	if (newfp == NULL) {
		printf("There was an error writing to %s. Exiting...\n", argv[2]);
		return EXIT_SUCCESS;
	}
	fputs(data, newfp);
	fclose(newfp);
	
	// Save it to the specified file:
	return EXIT_SUCCESS;
}
