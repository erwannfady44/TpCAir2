#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int red[10];
int white[10];

int try = 0;

void check(int tab[], int exepected[]);
void display(int send[10][4]);

int main(int argc, char const *argv[]) {
	int send[10][4];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			send[i][j] = -1;
		}
	}

	srand(time(NULL));

	int exepected[4];

	for (int i = 0; i < 4; i++) {
		exepected[i] = rand() % 5;
		printf("%d", exepected[i]);
	}
	printf("\n\n");

	display(send);

	do {
		printf("\nEnter the 4 values\n");	
		scanf("%d %d %d %d", &send[try][0], &send[try][1], &send[try][2], &send[try][3]);
		check(send[try], exepected);
		try++;
		display(send);
	} while(red[try - 1] < 4 && try <= 10);

	if (red[try -1] == 4) printf("Bravo, you win in %d try\n", try);
	else printf("You loose\n");
	
	return 0;
}

void check(int send[], int exepected[]) {
	for (int i = 0; i < 4; i++) {
		if (exepected[i] == send[i]) {
			red[try]++;
		}
		else {
			int j = 0;
			bool find = false;
			while(j < 4 && !find) {
				if (send[i] == exepected[j]) {
					white[try]++;
					find = true;
				}
				j++;
			}
		}
	}
}

void display(int send[10][4]) {
	//system("clear");
	printf("Try                   Result\n");
	for (int i = 0; i < 10; i++) {
		if (i < try) {
			printf("%d\t|%d|%d|%d|%d|     |",i+1,send[i][0], send[i][1],send[i][2],send[i][3]);

			for (int j = white[try - 1] + red[try - 1]; j < 4; j++)
				printf(" ");

			for (int j = 0; j < white[try - 1]; j++) {
				printf("•");
			}

			printf("\033[0;31m");
			for (int j = 0; j < red[try -1]; j++){
				printf("•");			
			}
			printf("\033[0m");
			printf("|\n");
		}
		else
			printf("%d\t| | | | |     |    |\n", i+1);
	}
	printf("\n");
}