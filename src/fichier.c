#include <stdio.h>
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
	
		fichier = fopen(nomFichier, "a");	// Ouverture en ecriture en fin de fichier
		gestionErreurs(fichier);
	
	while(positionClasse->suivant != NULL)
	{
		fprintf(fichier, "Classe de %s :", positionClasse->nomClasse);
		while(positionClasse.classe.positionEleve->suivant != NULL)
		{
			fprintf(fichier, "test\n");		// Ecriture dans le fichier
			positionClasse.classe.positionEleve = positionClasse.classe.positionEleve->suivant;
		}
	positionClasse = positionClasse->suivant;
	}

	fclose(fichier);	// Fermeture du fichier écrit

}

/*
void lireBaseEleve(char *nomFichier, Ecole_t *ptr_ecole)
{
	FILE * fichier;
	
	fichier = fopen(nomFichier, "r");	// Ouverture du fichier de sauvegarde en lecture seule
	gestionErreurs(fichier);
	
	while(!feof(fichier));
	{
		fscanf(fichier, "%s ; %s \n", ptr_ecole->depart.classe.nom, ptr_ecole->depart.classe.prenom);
		printf("%s ; %s \n", ptr_ecole->depart.classe.nom, ptr_ecole->depart.classe.prenom);
	}
	fclose(fichier);
}

*/
