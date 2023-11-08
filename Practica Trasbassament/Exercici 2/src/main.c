#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));
	
	printf("BENVINGUTS AL SISTEMA DE REPRESENTACIO DELS RIUS DE VALLFORNERS:\n");
	printf("Ivan Fernández Montalvo\n");

	int cabalInicialRiu1, cabalNouRiu1,valor, hora=0;
	
	do{
		printf("Introdueix la cabalInicialRiu1 inicial del riu:\n");
		scanf("%d",&cabalInicialRiu1);
	}while(cabalInicialRiu1<0 || cabalInicialRiu1>30);

	printf("\n");

	for(int i=30;i>=0;i--)
	{
		printf("%2d|\n",i);
	}

	int x=4, y=36;

	for(int j=1; j<=23;j++)
	{
		gotoxy(x,y);
		printf("--|");
		x=x+3;
	}

	x=3,y=37;
	for(int k=0;k<=23;k++)
	{
		gotoxy(x,y);
		printf("%d",k);
		x=x+3;
	}

	x=4;
	y=36-cabalInicialRiu1;
	gotoxy(x,y);
	printf("%2d",cabalInicialRiu1);
	
	
	while(hora<=21){
		valor = rand() % 2;
			if (valor == 1)
			{
				cabalNouRiu1 = (float)cabalInicialRiu1 + rand() % 11 * (float)cabalInicialRiu1 / 100;
				
				if (cabalNouRiu1 <= 0)
				{
					cabalNouRiu1 = rand() % 3;
				}
			}
			else
			{
				cabalNouRiu1 = (float)cabalInicialRiu1 - rand() % 11 * (float)cabalInicialRiu1 / 100;
				if (cabalNouRiu1 <= 0)
				{
					cabalNouRiu1 = rand() % 3;
				}
			}
			x=x+3;
			y=36-cabalNouRiu1;
			gotoxy(x,y);
			printf("%2d",cabalNouRiu1);
		cabalInicialRiu1=cabalNouRiu1;
		hora++;
		
	}
        
	

	gotoxy(1, 45);
	acabament();
	return 0;
}
