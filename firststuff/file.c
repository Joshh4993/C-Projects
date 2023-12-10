#include <stdio.h>

int fileMain() {
	FILE *fptr;

	fptr = fopen("data.txt", "r");

	if(fptr != NULL) {
		char fileString[100];

		while(fgets(fileString, 100, fptr)) {
			printf("%s", fileString);
		}

	} else {
		printf("Not able to open the file.");
	}

	fclose(fptr);

	return 0;
}
