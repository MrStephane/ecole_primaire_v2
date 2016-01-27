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
	Eleve_t *positionEleve = positionClasse->premierEleve;
	
	fichier = fopen(nomFichier, "w");	// Ouverture en ecriture, écrasement si fichier deja existant
	gestionErreurs(fichier);
		
		
	// infos de l'ecole
	fprintf(fichier, "%s;%d;\n", ecole.nomEcole, ecole.nbClasse);
		do
		{	// infos de la classe
		fprintf(fichier, "%s;%d;%s;%s;%s;\n",
		positionClasse->nomClasse, 
		positionClasse->nbEleve,
		positionClasse->professeur->civilite, 
		positionClasse->professeur->nom, 
		positionClasse->professeur->prenom);
		
		positionEleve = positionClasse->premierEleve;
			
			while(positionEleve != NULL)
			{	//infos de l'eleve
				fprintf(fichier, "%s;%s;%d;%d;%d;%d;%d;%s;%s;\n",
				positionEleve->nom,
				positionEleve->prenom,
				positionEleve->age,
				positionEleve->dateDeNaissance.tm_mday,
				positionEleve->dateDeNaissance.tm_mon-1,
				positionEleve->dateDeNaissance.tm_year-1900,
				positionEleve->genre,
				positionEleve->nomClasse,
				positionEleve->adresse);		// Ecriture dans le fichier
					
			  positionEleve = positionEleve->suivant;
			}
			
		  positionClasse = positionClasse->suivant;
		} while(positionClasse != NULL);
			
	fclose(fichier);	// Fermeture du fichier écrit

}


void lireBaseEleve(const char *nomFichier, Ecole_t *ptr_ecole)
{
	FILE * fichier;
	
	Classe_t * ptr_classe, ptr_classePrecedente = NULL;
	
	Eleve_t * ptr_eleve, ptr_elevePrecedent = NULL;
	
	char *chaine;
	
	char ligne[200];
	
	int i; // Compteur de boucle sur Classe
	int j; // Compteur de boucle sur Eleve
	
	
	
	
	fichier = fopen(nomFichier, "r");	// Ouverture du fichier de sauvegarde en lecture seule
	
	if(!fichier)
	{
		printf("\n\n\t  Aucune ecole, veuillez la creer.\n\n");
		return;
	}
	else
	{
		// recuperation de la ligne permettant de connaitre le nombre de classes dans l'école
		fscanf(fichier, "%s %d\n", ptr_ecole->nomEcole, &ptr_ecole->nbClasse);
	
		//printf("\n\tEcole: %s\n\tclasse: %d\n", ptr_ecole->nomEcole, ptr_ecole->nbClasse);
	
		/*for(i = 0; i < ptr_ecole->nbClasse-1; i++)
		{				
			fscanf(fichier, "%s;%d;%s;%s;%s\n",
			positionClasse->nomClasse, 
			&positionClasse->nbEleve,	// Recup du nombre d'eleves sur les lignes suivantes du fichier
			positionClasse->professeur->civilite, 
			positionClasse->professeur->nom, 
			positionClasse->professeur->prenom);
		
			positionClasse->premierEleve = positionEleve;
			
			for(j = 0; j < positionClasse->nbEleve-1; j++)
			{						
				fscanf(fichier, "%s;%s;%d;%d;%d;%d;%d;%s;%s\n",
				positionEleve->nom,
				positionEleve->prenom,
				&positionEleve->age,
				&positionEleve->dateDeNaissance.tm_mday,
				&positionEleve->dateDeNaissance.tm_mon+1,
				&positionEleve->dateDeNaissance.tm_year+1900,
				&positionEleve->genre,
				positionEleve->nomClasse,
				positionEleve->adresse);
				
				positionEleve = positionEleve->suivant;
			}
			positionClasse = positionClasse->suivant;
		}*/
		
		for(i = 0; i < ptr_ecole->nbClasse-1; i++)
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
			ptr_classe->nbEleve = strtok(NULL, ";");
			
			
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
				
				chaine = strtok(NULL, ";");
				
				switch(j)
				{
					case 0:
						strcpy(ptr_eleve->nom, chaine);
						break;
					case 1:
						strcpy(ptr_eleve->prenom, chaine);
						break;
					case 2:
						ptr_eleve->age = atoi(chaine);
						break;
					case 3:
						ptr_eleve->dateDeNaissance.tm_mday = atoi(chaine);
						break;
					case 4:
						ptr_eleve->dateDeNaissance.tm_mon = atoi(chaine) - 1;
						break;
					case 5:
						ptr_eleve->dateDeNaissance.tm_year = atoi(chaine) - 1900;
						break;
					case 6:
						ptr_eleve->genre = atoi(chaine);
						break;
					case 7:
						strcpy(ptr_eleve->nomClasse, chaine);
						break;
					case 8:
						strcpy(ptr_eleve->adresse, chaine);
						break;
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

