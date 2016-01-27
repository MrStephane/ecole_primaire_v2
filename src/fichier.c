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



void ecrireBaseEleve(const char *nomFichier, Ecole_t ecole)
{
	FILE * fichier;

	Classe_t *positionClasse = ecole.premiereClasse;
	
	Eleve_t *positionEleve;
	
	fichier = fopen(nomFichier, "w");	// Ouverture en ecriture, écrasement si fichier deja existant
	gestionErreurs(fichier);
		
		
	// infos de l'ecole
	fprintf(fichier, "%s;%d;\n", ecole.nomEcole, ecole.nbClasse);
	do
	{	// infos de la classe
		fprintf(fichier, "%s;%d;\n",
		positionClasse->nomClasse, 
		positionClasse->nbEleve);
		
		if (positionClasse != NULL)
			positionEleve = positionClasse->premierEleve;
			
		while(positionEleve != NULL)
		{	//infos de l'eleve
			fprintf(fichier, "%s;%s;%d;%d;%d;%d;%d;%s;\n",
			positionEleve->nom,
			positionEleve->prenom,
			positionEleve->age,
			positionEleve->dateDeNaissance.tm_mday,
			positionEleve->dateDeNaissance.tm_mon+1,
			positionEleve->dateDeNaissance.tm_year+1900,
			positionEleve->genre,
			positionEleve->nomClasse);
				
		  	positionEleve = positionEleve->suivant;
		}
			
		positionClasse = positionClasse->suivant;
	} while(positionClasse != NULL);
			
	fclose(fichier);	// Fermeture du fichier écrit
}


void lireBaseEleve(const char *nomFichier, Ecole_t *ptr_ecole)
{
	FILE * fichier;
	
	Classe_t *ptr_classe, *ptr_classePrecedente = NULL;
	
	Eleve_t *ptr_eleve, *ptr_elevePrecedent = NULL;
	
	char *chaine;
	
	char ligne[200];
	
	int i; // Compteur de boucle sur Classe
	int j; // Compteur de boucle sur Eleve
	int k;
	
	
	
	
	fichier = fopen(nomFichier, "r");	// Ouverture du fichier de sauvegarde en lecture seule
	
	if(!fichier)
		return;
	else
	{
		fgets(ligne, 200, fichier);
		strcpy(ptr_ecole->nomEcole, strtok(ligne, ";"));
		ptr_ecole->nbClasse = atoi(strtok(NULL, ";"));
	
		for(i = 0; i < ptr_ecole->nbClasse; i++)
		{
			ptr_classe = CreationClasse();
			
			// Si il s'agit de la première classe on l'ajoute en tete de l'école
			if (i == 0)
				ptr_ecole->premiereClasse = ptr_classe;
			
			// Si il y a une classe precedent on la lie à la nouvelle
			if (ptr_classePrecedente != NULL)
				ptr_classePrecedente->suivant = ptr_classe;
			
			fgets(ligne, 200, fichier);
			strcpy(ptr_classe->nomClasse, strtok(ligne, ";"));
			ptr_classe->nbEleve = atoi(strtok(NULL, ";"));
			
			
			fgets(ligne, 200, fichier);
			
			for (j = 0; j < ptr_classe->nbEleve; ++j)
			{
				ptr_eleve = CreationEleve();
				
				// Si il s'agit du premier élève on l'ajoute en tete de classe
				if (i == 0)
					ptr_classe->premierEleve = ptr_eleve;
				
				// Si il y a un eleve précedent on le lie au nouveau
				if (ptr_elevePrecedent != NULL)
					ptr_elevePrecedent->suivant = ptr_eleve;
				
				chaine = strtok(ligne, ";");
				strcpy(ptr_eleve->nom, chaine);
				
				for (k = 0; k < 8; ++k)
				{
					chaine = strtok(NULL, ";");
					
					switch(k)
					{
						case 0:
							strcpy(ptr_eleve->prenom, chaine);
							break;
						case 1:
							ptr_eleve->age = atoi(chaine);
							break;
						case 2:
							ptr_eleve->dateDeNaissance.tm_mday = atoi(chaine);
							break;
						case 3:
							ptr_eleve->dateDeNaissance.tm_mon = atoi(chaine) - 1;
							break;
						case 4:
							ptr_eleve->dateDeNaissance.tm_year = atoi(chaine) - 1900;
							break;
						case 5:
							ptr_eleve->genre = atoi(chaine);
							break;
						case 6:
							strcpy(ptr_eleve->nomClasse, chaine);
							break;
						case 7:
							strcpy(ptr_eleve->adresse, chaine);
							break;
					}
				}
				
				ptr_eleve->precedent = ptr_elevePrecedent;
				ptr_elevePrecedent = ptr_eleve;
			}
			
			ptr_classe->precedent = ptr_classePrecedente;
			ptr_classePrecedente = ptr_classe;
		}
	}
	
	fclose(fichier);
}

