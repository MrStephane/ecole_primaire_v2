#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "date.h"





void RecupererDate(struct tm *ptr_dateJour)
{
    time_t sec;
    time(&sec);
    ptr_dateJour=localtime(&sec);

}



void AfficherDate(struct tm date)
{
    printf("%d/%d/%d", date.tm_mday, date.tm_mon+1, date.tm_year+1900);
}



void SaisirDate(struct tm *ptr_date)
{
	printf("(jj.mm.aaaa) : ");
	scanf("%d.%d.%d", &ptr_date->tm_mday, &ptr_date->tm_mon, &ptr_date->tm_year);
	ViderBuffer();
	ptr_date->tm_mday = ptr_date->tm_mday-1;
	ptr_date->tm_year = ptr_date->tm_year-1900;
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



void CalculRentreeScolaire(struct tm today, struct tm *ptr_rentreeScolaire)
{
	ptr_rentreeScolaire->tm_mday = 1;
	ptr_rentreeScolaire->tm_mon = 8; // Septembre = 9 mais -1 a cause du format d'une struct tm

	// Si le mois est inférieur à septembre alors la rentré scolaire c'est déroulé l'année précédente.
	if (today.tm_mon < 8)
		ptr_rentreeScolaire->tm_year = today.tm_year - 1;
	// Sinon la rentré c'est déroulé la même année.
	else
		ptr_rentreeScolaire->tm_year = today.tm_year;
}



int CalculerAge(struct tm dateJ, struct tm dateN)
{
	// Si l'anniversaire n'a pas encore eu lieu
	if (dateN.tm_mon > dateJ.tm_mon || (dateN.tm_mon == dateJ.tm_mon && dateN.tm_mday > dateJ.tm_mday))
		return (dateJ.tm_year - dateN.tm_year) - 1;
	else
		return (dateJ.tm_year - dateN.tm_year);
}



int CategorieAge(struct tm dateN, struct tm dateR)
{
    // Si le mois de naissance est inférieur à Septembre il faut soutraire un an à l'année de naissance pour obtenir la bonne catégorie d'age
	if (dateN.tm_mon < 8)
        return (dateR.tm_year - (dateN.tm_year - 1));

	// Sinon il suffit de soutraire année de la rentrée avec l'année de naissance tel quel
	return (dateR.tm_year - dateN.tm_year);
}
