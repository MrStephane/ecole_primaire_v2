#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "prof.h"



Prof_t* CreationProf(void)
{
	Prof_t *ptr_prof;
	
	ptr_prof = (Prof_t*) calloc(sizeof(Prof_t));
	
	if (ptr_prof == NULL)
		exit(EXIT_FAILURE);
	
	return ptr_prof;
}



void AfficherProf(Prof_t p)
{
	printf("%s %s %s", p.civilite, p.nom, p.prenom);
}




void SaisirProf(Prof_t *ptr_p)
{
    int continuer = 0;


	do
	{
		printf("Saisir la civilite du professeur ( Monsieur, Madame, Mademoiselle ) : ");
		scanf("%s", ptr_p->civilite);
		ViderBuffer();
		printf("Entrez le nom du professeur : ");
		scanf("%s", ptr_p->nom);
		ViderBuffer();
		printf("Entrez le prenom du professeur : ");
		scanf("%s", ptr_p->prenom);
		ViderBuffer();

		if (ControleChaine(ptr_p->civilite)==0 || ControleChaine(ptr_p->nom) == 0 || ControleChaine(ptr_p->prenom) == 0)
		{
			RetourLigne(1);
			printf("Ecrivez le nom, le prenom et la civilite sans chiffres ni accents.\n");
			RetourLigne(1);
		}
		else
			continuer = 1;
	} while (!continuer);

	NormaliserNomPrenom(ptr_p->civilite, ptr_p->nom, ptr_p->prenom);
}



void SupprimerProf(Prof_t *ptr_prof)
{
	free(ptr_prof);
}
