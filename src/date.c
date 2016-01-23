#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "date.h"





void RecupererDate(struct tm *ptr_d)
{
    time_t sec;
    time(&sec);
    ptr_d=localtime(&sec);

}



void AfficherDate(struct tm ptr_d)
{
    printf("%d/%d/%d", ptr_d.tm_mday, ptr_d.tm_mon, ptr_d.tm_year);
}



void SaisirDate(struct tm *ptr_d)
{
	printf("(jj.mm.aaaa) : ");
	scanf("%d.%d.%d", &ptr_d->tm_mday, &ptr_d->tm_mon, &ptr_d->tm_year);
	ViderBuffer();
	ptr_d->tm_mday = ptr_d->tm_mday-1;
	ptr_d->tm_year = ptr_d->tm_year-1900;
}



int ControleDate(struct tm d)
{
    int estBissextile = 0;
	int dateValide = 0;


	
	// On modifie la date qui est formaté de manière spéciale avant de faire les tests
	d.tm_year += 1900;
	d.tm_mon += 1;
	
	if (d.tm_year < 1881) // Date vérifié par Redha au telephone. (François Hollande)
	{
		printf("\tErreur !\n");
		return 0;
	}

	// on teste si il s'agit d'une année bissextile
	if ((d.tm_year % 4 == 0 && d.tm_year % 100 != 0) || d.tm_year % 400 == 0)
		estBissextile = 1;

	switch(d.tm_mon)
	{
		// Pour les mois de 31 jours
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			// Si il y a jour improbable
			if (d.tm_mday > 31 || d.tm_mday < 1)
				printf("\tErreur !\n");
			else
				dateValide = 1;
			break;
		// Pour les mois de 30 jours
		case 4:
		case 6:
		case 9:
		case 11:
			// Si il y a jour improbable
			if (d.tm_mday > 30 || d.tm_mday < 1)
				printf("Erreur !\n");
			else
				dateValide = 1;
			break;
		// Pour février
		case 2:
			if (d.tm_mday < 1)
				printf("Erreur !\n");
			else if (estBissextile && d.tm_mday > 29)
				printf("Erreur !\n");
			else if (!estBissextile && d.tm_mday > 28)
				printf("Erreur !\n");
			else
				dateValide = 1;
			break;
		// Si on rentre un mois qui n'existe pas
		default :
			printf("Erreur !\n");
	}

	return dateValide;
}
