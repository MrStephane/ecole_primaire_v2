#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fichier.h"

int comptedonnees(FILE * fichier)
{
	char lignes[100];
	char c;
	int compteur = 0;
	
	while((c=fgetc(fichier)) != EOF) // Tant qu'on parcours le fichier sans en trouver la fin
	{
		if(c == '\n')
			compteur++;	// on incrémente le compteur a chaque saut de ligne
	}
	printf("\n\t Le fichier contient %d lignes\n", compteur);	// puis affichage de celui ci
	
	return compteur;	// on renvoie le nombre de lignes
}


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
			fprintf(fichier, " %s ; %s ; %d ; %d/%d/%d ; %d ; %s ; %s ;\n",
				positionEleve->nom, positionEleve->prenom,
				positionEleve->age,
				positionEleve->dateDeNaissance.tm_mday,
				positionEleve->dateDeNaissance.tm_mon,
				positionEleve->dateDeNaissance.tm_myear,
				positionEleve->genre,
				positionEleve->nomClasse,
				positionEleve->adresse);		// Ecriture dans le fichier
				
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
			fscanf(fichier, " %s ; %s ; %d ; %d/%d/%d ; %d ; %s ; %s ;\n",
				positionEleve->nom, positionEleve->prenom,
				&positionEleve->age,
				&positionEleve->dateDeNaissance.tm_mday,
				&positionEleve->dateDeNaissance.tm_mon,
				&positionEleve->dateDeNaissance.tm_myear,
				&positionEleve->genre,
				positionEleve->nomClasse,
				positionEleve->adresse);

			positionEleve = positionEleve->suivant;
		}
	positionClasse = positionClasse->suivant;
	}
	fclose(fichier);
}
