#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "personnel.h"

Personnel_t* CreationPersonnel(void)
{
	Personnel_t *ptr_personnel;

	ptr_personnel = (Personnel_t*) calloc(sizeof(Personnel_t));

	if (ptr_personnel == NULL)
		exit(EXIT_FAILURE);

	return ptr_personnel;
}

void SaisirPersonnel(Personnel_t * ptr_personnel)
{
    int i;
	int continuer;
	int* nbPers;

    do
	{
		continuer = 1;
		printf("\n\tCombien voulez vous saisir de personnels ? ");
		scanf("%d", &nbPers);
		ViderBuffer();

		if (*nbPers <= 0 || *nbPers > 20)
		{
			printf("\tErreur !");
			continuer = 0;
		}
	} while (!continuer);

    for(i=0; i<*nbPers; i++)
    {
        do
		{
			continuer = 1;
			printf("\n\tSaisir la civilite du personnel ( Monsieur, Madame, Mademoiselle ) : ");
			scanf("%s", ptr_personnel[i].civilite);
			ViderBuffer();

			if (!ControleChaine(ptr_personnel[i].civilite))
			{
				printf("\n\tEcrivez les informations sans chiffres ni accents !\n");
				continuer = 0;
			}
		} while (!continuer);

		do
		{
			continuer = 1;
			printf("\tEntrez le nom du personnel : ");
			scanf("%s", ptr_personnel[i].nom);
			ViderBuffer();

			if (!ControleChaine(ptr_personnel[i].nom))
			{
				printf("\n\tEcrivez les informations sans chiffres ni accents !\n");
				continuer = 0;
			}
		} while (!continuer);

		do
		{
			continuer = 1;
			printf("\tEntrez le prenom du personnel : ");
			scanf("%s", ptr_personnel[i].prenom);
			ViderBuffer();

			if (!ControleChaine(ptr_personnel[i].prenom))
			{
				printf("\n\tEcrivez les informations sans chiffres ni accents !\n");
				continuer = 0;
			}
		} while (!continuer);

		do
		{
			continuer = 1;
			printf("\n\tVeuillez saisir sa fonction ( Directeur, CPE, Surveillant, Entretient ) :");
			scanf("%s", ptr_personnel[i].metier);
			ViderBuffer();

			if (!ControleChaine(ptr_personnel[i].metier))
			{
				printf("\n\tEcrivez les informations sans chiffre(s) ni accent(s).\n");
				continuer = 0;
			}
		} while (!continuer);

		NormaliserNomPrenom(NULL,ptr_personnel[i].nom,ptr_personnel[i].prenom);
		NormaliserNomPrenom(NULL,ptr_personnel[i].metier,ptr_personnel[i].civilite);
    }

    RetourLigne(1);
}



void AfficherPersonnel(Personnel_t personnel)
{
	printf("\t%s : %s %s %s", personnel.metier, personnel.civilite, personnel.nom, personnel.prenom);
}

void SupprimerPersonnel(Personnel_t *ptr_personnel)
{
	free(ptr_personnel);
}


// Clement et Vincent
/*void ListePersonnel(Personnel_t* ecole, int nbPers)
{
    int i;

    if(nbPers)
	{
		printf("\n\tVoici la liste du personnel de l'ecole :\n");

		for(i=0; i<nbPers; i++)
			AfficherPersonnel(ecole[i]);
	}
    else
		printf("\n\tIl n'y a pas encore de personnel dans l'ecole\n");
}*/
