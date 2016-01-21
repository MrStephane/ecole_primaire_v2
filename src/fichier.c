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
	
	fichier = fopen(nomFichier, "a");	// Ouverture en ecriture en fin de fichier
	gestionErreurs(fichier);
	

	/*while(ecole.depart.suivant != NULL)
	{
		fprintf(fichier, "%s ; %s ; %d ; %d/%d/d ; %d ; %s ; %s \n", ecole.depart.classe.nom, ecole.depart.classe.prenom, ecole.depart.classe.age, ecole.depart.classe.dateDeNaissance, ecole.depart.classe.nomClasse, ecole.depart.classe.adresse);		// Ecriture dans le fichier
	}*/

	fclose(fichier);	// Fermeture du fichier écrit

}


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
