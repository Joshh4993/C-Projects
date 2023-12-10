#include <stdio.h>
#include <stdlib.h>

void menu();
void loadHiScore();
void saveHiScore();
void play();
int cpuChoice();
int randomRps(int min, int max);

int hiScore;
int roundNum = 0;

int main() {
	// Program entry point
	loadHiScore();
	menu();
}

void menu() {
	// Main menu
	printf("\n\nWelcome to rock, paper, scissors!\n\n");

	int userOpt;

	printf("Hi-Score: %d\n", hiScore);
	printf("1. Play\n2.Quit\n");
	scanf("%d", &userOpt);
	switch (userOpt) {
	case 1:
		play();
		break;
	default:
		exit(1);
		break;
	}
}

void play() {
	// Game loop
	int option;
	printf("\n\nROUND %d\n", roundNum);
	printf("1. Rock\n2. Paper\n3. Scissors\n");
	scanf("%d", &option);

	if (option > 3 || option < 1) {
		printf("\n\nOption out of bounds.");
		play();
	}

	int compChoice = cpuChoice();

	if (option == compChoice) {
		roundNum++;
		if (roundNum > hiScore) {
			hiScore++;
		}

		printf("\nIt's a tie! Next round.");
		play();
	} else if ((option == 1 && compChoice == 3) ||
			(option == 2 && compChoice == 1) ||
			(option == 3 && compChoice == 2)) {
		roundNum++;
		if (roundNum > hiScore) {
			hiScore++;
		}
		printf("\nYou win! Next round.");
		play();
	} else {
		roundNum = 0;
		saveHiScore();
		printf("\nYou lost! Back to menu.");
		menu();
	}
}

int randomRps(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int cpuChoice() {
	// CPU player choice
	int min = 1;
	int max = 3;
	return randomRps(min, max);
}

void loadHiScore() {
	// read high score from file, if doesn't exist then create file and set HS to 0
	FILE *fptr;
	fptr = fopen("rps.data", "r");

	if (fptr != NULL) {
		char buffer[50];
		fgets(buffer, 50, fptr);
		hiScore = atoi(buffer);
	} else {
		fptr = fopen("rps.data", "w");
		fprintf(fptr, "0");
		hiScore = 0;
	}

	fclose(fptr);
}

void saveHiScore() {
	// save high score to file
	FILE *fptr;
	fptr = fopen("rps.data", "w");
	fprintf(fptr, "%d", hiScore);
	fclose(fptr);
}
