#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

// #define cabal95 1425
#define cabalMaxim 1500
#define cabalMinim 0

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	printf("\nBENVINGUTS AL SISTEMA DE CONTROL DE L'EMBASSAMENT DE VALLFORNERS: ");
	printf("\nIvan Fernández Montalvo\n\n");

	float cabalInicial, cabalInicialRiu1, cabalInicialRiu2, cabalMax, cabalMin, nivellEmbassament, percentatge;
	float cabalNouRiu1, cabalNouRiu2, cabalTotal, percentatgeTotal;
	int valor, hora = 0;
	bool compt1 = true, compt2 = true, sortir = false;

	do
	{
		printf("Introdueix el cabal inicial de l'embassament (0-1500): \n");
		scanf("%f", &cabalInicial);
	} while (cabalInicial < cabalMinim || cabalInicial > cabalMaxim);

	do
	{
		printf("Introdueix la capacitat del riu 1 (0-400): \n");
		scanf("%f", &cabalInicialRiu1);
	} while (cabalInicialRiu1 < 0 || cabalInicialRiu1 > 400);

	do
	{
		printf("Introdueix la capacitat del riu 2 (0-400): \n");
		scanf("%f", &cabalInicialRiu2);
	} while (cabalInicialRiu2 < 0 || cabalInicialRiu2 > 400);
	printf("\n");

	printf("Hora\t");
	printf("Estat\t\t");
	printf("Percentatge\t\t");
	printf("Riu1\t");
	printf("Riu2\t");
	printf("Total\t");
	printf("Compt1\t");
	printf("Compt2");
	printf("\n");

	while (hora <= 23 && sortir==false)
	{
		if (hora == 0)
		{
			if (cabalInicial < 225)
			{
				compt1 = FALSE;
				compt2 = FALSE;
			}
			else if (cabalInicial < 1200)
			{
				compt1 = TRUE;
				compt2 = FALSE;
			}
			else
			{
				compt1 = TRUE;
				compt2 = TRUE;
			}

			if (cabalInicial < 900)
			{
				setColor(GREEN);
			}
			else if (cabalInicial > 900 && cabalInicial <= 1350)
			{
				setColor(BLUE);
			}
			else
			{
				setColor(RED);
			}

			printf("%d\t", hora);
			printf("%.2f\t\t", cabalInicial);
			percentatge = (cabalInicial / cabalMaxim) * 100;
			printf("%.2f\t\t\t", percentatge);
			printf("%.2f\t", cabalInicialRiu1);
			printf("%.2f\t", cabalInicialRiu2);
			printf("%.2f\t", cabalInicialRiu1 + cabalInicialRiu2);
			printf("%d\t", compt1);
			printf("%d\t", compt2);
			printf("\n");
			nivellEmbassament = cabalInicial;
			cabalMax = cabalInicial;
			cabalMin = cabalInicial;
		}
		else
		{
			if (compt1 == 1 && compt2 == 0)
			{
				nivellEmbassament = nivellEmbassament - (nivellEmbassament * 0.10) + cabalInicialRiu1 + cabalInicialRiu2;
			}
			else if (compt1 == 1 && compt2 == 1)
			{
				nivellEmbassament = nivellEmbassament - (nivellEmbassament * 0.20) + cabalInicialRiu1 + cabalInicialRiu2;
			}
			else if (compt1 == 0 && compt2 == 0)
			{
				nivellEmbassament = nivellEmbassament + cabalNouRiu1 + cabalNouRiu2;
			}

			if (nivellEmbassament > cabalMax)
			{
				cabalMax = nivellEmbassament;
			}
			else if (nivellEmbassament < cabalMin)
			{
				cabalMin = nivellEmbassament;
			}

			valor = rand() % 2;
			if (valor == 1)
			{
				cabalNouRiu1 = cabalInicialRiu1 + rand() % 11 * cabalInicialRiu1 / 100;
				cabalNouRiu2 = cabalInicialRiu2 + rand() % 11 * cabalInicialRiu2 / 100;
				if (cabalNouRiu1 < 0)
				{
					cabalNouRiu1 = rand() % 3;
				}
				else if (cabalNouRiu2 < 0)
				{
					cabalNouRiu2 = rand() % 3;
				}
			}
			else
			{
				cabalNouRiu1 = cabalInicialRiu1 - rand() % 11 * cabalInicialRiu1 / 100;
				cabalNouRiu2 = cabalInicialRiu2 - rand() % 11 * cabalInicialRiu2 / 100;
				if (cabalNouRiu1 < 0)
				{
					cabalNouRiu1 = rand() % 3;
				}
				else if (cabalNouRiu2 < 0)
				{
					cabalNouRiu2 = rand() % 3;
				}
			}

			if (nivellEmbassament < 225)
			{
				compt1 = FALSE;
				compt2 = FALSE;
			}
			else if (nivellEmbassament < 1200)
			{
				compt1 = TRUE;
				compt2 = FALSE;
			}
			else
			{
				compt1 = TRUE;
				compt2 = TRUE;
			}

			if (nivellEmbassament < 900)
			{
				setColor(GREEN);
			}
			else if (nivellEmbassament > 900 && nivellEmbassament <= 1350)
			{
				setColor(BLUE);
			}
			else
			{
				setColor(RED);
			}

			printf("%d\t", hora);
			printf("%.2f\t\t", nivellEmbassament);
			percentatge = (nivellEmbassament / cabalMaxim) * 100;
			printf("%.2f\t\t\t", percentatge);
			printf("%.2f\t", cabalNouRiu1);
			printf("%.2f\t", cabalNouRiu2);
			printf("%.2f\t", cabalNouRiu1 + cabalNouRiu2);
			printf("%d\t", compt1);
			printf("%d\t", compt2);
			printf("\n");
		
			cabalInicialRiu1 = cabalNouRiu1;
			cabalInicialRiu2 = cabalNouRiu2;
			cabalInicial = nivellEmbassament;
		}
		cabalTotal = cabalTotal + cabalInicial;
		percentatgeTotal=percentatgeTotal+percentatge;
		hora++;

		if(percentatge>95.00 && percentatge<100){
			printf("%c",7);
			sortir=true;
		}
		
		if(percentatge>100.00){
			printf("%c",7);
			Sleep(1000);
			printf("%c",7);
			Sleep(1000);
			printf("%c",7);
			Sleep(1000);
			printf("%c",7);
			Sleep(1000);
			printf("%c",7);
			sortir=true;
		}
	}
if(percentatge>95.00){
	setColor(RED);
	printf("\nEVACUACIÓ!");
}else if(percentatge>100){
	setColor(RED);
	printf("\nEVACUACIÓ ZONA!");
}
setColor(GREY);
printf("\n\nRESUM\n");
printf("El cabal màxim de l'embassament ha sigut: %.2f\n", cabalMax);
printf("El cabal míxim de l'embassament ha sigut: %.2f\n", cabalMin);
printf("El cabal mitjà ha sigut: %.2f\n", cabalTotal / hora);
printf("El percentatge mitjà ha sigut: %.2f\n\n", percentatgeTotal/hora);


acabament();
return 0;
}


