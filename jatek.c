#include "Header.h"
#include <stdlib.h>
#include <stdio.h>

void kirajzolPalya(char** palya, int hossz, int szel)
{
	int i, j;
	for (i = 0; i < hossz; ++i) {
		for (j = 0; j < szel; ++j) {
			if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
				printf("-");
			}
			else if (palya[i][j] == '3') {
				printf("|");
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("|");
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				printf("P");
			}
		}
		printf("\n");
	}
	system("pause");
}

char** beolvasPalya(const char* fajlNev, int hossz, int szel)
{
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	//ellenorzes
	int i, j;
	for (i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}

	for (i = 0; i < hossz; ++i) {
		for (j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
		}
	}
	return palya;
}

