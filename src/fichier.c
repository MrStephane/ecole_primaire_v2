#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fichier.h"

void gestionErreurs(FILE * fichier)
{
	if(!fichier)
	{
		perror("Operation impossible");
		exit(EXIT_FAILURE);
	}
}

void ecrireBaseEleve(char *nomFichier, Ecole_t ecole)
{
	FILE * fichier;

	Classe_t *positionClasse = ecole.depart;
	Eleve_t *positionEleve = positionClasse->classe;
	
		fichier = fopen(nomFichier, "a");	// Ouverture en ecriture en fin de fichier
		gestionErreurs(fichier);
	
	while(positionClasse->suivant != NULL)
	{
	positionEleve = positionClasse->classe;
		while(positionEleve->suivant != NULL)
		{
			fprintf(fichier, "%s %s %d\n", positionEleve->prenom, positionEleve->nom, positionEleve->age);		// Ecriture dans le fichier
			positionEleve = positionEleve->suivant;
		}
	positionClasse = positionClasse->suivant;
	}

	fclose(fichier);	// Fermeture du fichier écrit

}


void lireBaseEleve(char *nomFichier, Ecole_t *ptr_ecole)
{
	FILE * fichier;
	
	Classe_t * positionClasse = ptr_ecole->depart;
	Eleve_t * positionEleve = positionClasse->classe;
	
	fichier = fopen(nomFichier, "r");	// Ouverture du fichier de sauvegarde en lecture seule
	gestionErreurs(fichier);
	
	while(positionClasse->suivant != NULL)
	{
	positionEleve = positionClasse->classe;
		while(positionEleve->suivant != NULL)
		{
			fscanf(fichier, "%s %s %d\n", positionEleve->nom, positionEleve->prenom, &positionEleve->age);
			positionEleve = positionEleve->suivant;
		}
	positionClasse = positionClasse->suivant;
	}
	fclose(fichier);
}
