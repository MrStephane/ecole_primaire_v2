#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "prof.h"


void AfficherProf(Prof_t p)
{
	printf("%s %s %s", p.civilite, p.nom, p.prenom);
}




void SaisirProf(Prof_t *ptr_p)
{
    int continuer;


	do
	{
		continuer = 1;
		printf("\n\tSaisir la civilite du professeur ( Monsieur, Madame, Mademoiselle ) : ");
		scanf("%s", ptr_p->civilite);
		ViderBuffer();
		printf("\tEntrez le nom du professeur : ");
		scanf("%s", ptr_p->nom);
		ViderBuffer();
		printf("\tEntrez le prenom du professeur : ");
		scanf("%s", ptr_p->prenom);
		ViderBuffer();

		if (ControleChaine(ptr_p->civilite)==0 || ControleChaine(ptr_p->nom) == 0 || ControleChaine(ptr_p->prenom) == 0)
		{
			printf("\n\tEcrivez le nom, le prenom et la civilite sans chiffres ni accents.\n");
			continuer = 0;
		}
	} while (!continuer);

	NormaliserNomPrenom(ptr_p->civilite, ptr_p->nom, ptr_p->prenom);

    RetourLigne(1);
}
