#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "Header.h"



int hossz, szel;

int main()
{
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	printf("konnyu: e\nkozepes: m\nnehez: h\n");
	char option1 = getch();
	char* palyaNev = "";
	
	switch (option1) {
	case 'e': palyaNev = "be2.txt"; break;
	case 'm': palyaNev = "be1.txt"; break;
	case 'h': palyaNev = "be.txt"; break;
	}

	palya = beolvasPalya(palyaNev,hossz,szel);

	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya,hossz,szel);
	while (palya[jatekosX][jatekosY] != 'R') {
		currentTime = time(NULL);
		kirajzolPalya(palya,hossz,szel);
		printf("jobb: j\nle: l\nbal: b\nfel: f\n");
		
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		switch (option) {
		case 'j': jatekosY++; break;
		case 'l': jatekosX++; break;
		case 'b': jatekosY--; break;
		case 'f': jatekosX--; break;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		else if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3') {
			palya[jatekosX][jatekosY] = palya[elozoX][elozoY];
			palya[elozoX][elozoY] = "|";
		}
		Sleep(300);
		system("CLS");
		if (currentTime - startTime > 10) {
				printf("Time limit exceeded!\n Game over\n");
				break;
		}
	}
	if (palya[jatekosX][jatekosY] == 'R') {
		printf("Congratulations on getting out of the maze");
	}
	getch();
	return(0);
}
