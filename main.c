#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Déclaration des variables globales nécessaires
int red[10];		//Contiendra les nombres bien placés pour chaque tour
int white[10];		//Contiendra les nombres mal placés pour chaque tour
int exepected[4];	//Contiendra la solution
int try = 0;		//Nombre de tentatives

//Déclaration des différentes fonctions
void check(int tab[]);
void display(int send[10][4]);

//Fonction principale
int main(int argc, char const *argv[]) {
	//Création d'un tableau à double entrée (il contiendra les différentes tentatives du joueur)
	int send[10][4];

	//Initialisaiton de la fonction random
	srand(time(NULL));

	//Initialisation de la solution
	for (int i = 0; i < 4; i++) {
		exepected[i] = rand() % 5;
	}

	//Affichage du jeu
	display(send);

	/*TODO : 
		boucle qui contient le jeu
		Afficher "you win" ou "you loose" à la fin du jeu
	*/
	
	return 0;
}

//Fonction qui calcul le score
void check(int tab[]) {
	//TODO : écrire la fonction
}

//Fonction qui affiche le jeu
void display(int send[10][4]) {
	system("clear");
	printf("Try                   Answer\n");
	for (int i = 0; i < 10; i++) {
		if (i < try) {
			printf("%d\t|%d|%d|%d|%d|     |%d|",i+1,send[i][0], send[i][1],send[i][2],send[i][3], white[i]);
			printf("\033[0;31m");
			printf("%d", red[i]);
			printf("\033[0m");
			printf("|\n");
		}
		else
			printf("%d\t| | | | |     | | |\n", i+1);
	}
	printf("\n");
}