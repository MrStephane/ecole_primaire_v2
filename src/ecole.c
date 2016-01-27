#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "ecole.h"
extern struct tm dateJ;



void InitEcole(Ecole_t *ptr_ecole)
{
	memset(ptr_ecole, 0, sizeof(Ecole_t));
}



void AfficherEcole(Ecole_t ecole)
{
	Classe_t *ptr_classeCourante = ecole.premiereClasse;
	
	
	
	printf("Ecole : %s\n", ecole.nomEcole);
	
	RetourLigne(2);
	
	while (ptr_classeCourante != NULL)
	{
		printf("Classe de %s\n", ptr_classeCourante->nomClasse);
		RetourLigne(1);
		AfficherClasse(*ptr_classeCourante);
		
		if (ptr_classeCourante->suivant != NULL)
			RetourLigne(2);
		
		ptr_classeCourante = ptr_classeCourante->suivant;
	}
}



void AjouterEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char *prenom)
{
	Classe_t *ptr_classe;
	
	Eleve_t *ptr_eleve;
	
	int estNouvelleClasse = 0;
	
	
	
	// Appel a CreationEleve pour créer l'espace d'un eleve en memoire
	ptr_eleve = CreationEleve();
	
	// Appel a SaisirEleve avec le nom et prenom precedement saisie pour remplir les autre champs (age, etc...)
	SaisirEleve(ptr_eleve, nom, prenom);
	
	// Si l'élève n'a pas le niveau alors on le supprime.
	if (strcmp(ptr_eleve->nomClasse, "NULL") == 0)
	{
		printf("Cet eleve n'a pas le niveau primaire.\n");
		SupprimerEleve(ptr_eleve);
		return;
	}
	
	// Recherche de la classe qui correspond au niveau de l'élève
	ptr_classe = RechercherNiveauClasse(ptr_ecole->premiereClasse, ptr_eleve);
	
	
	
	if (ptr_classe != NULL)
		estNouvelleClasse = AjouterEleveDansClasse(ptr_classe, ptr_eleve);
		if (estNouvelleClasse == 1)
			++ptr_ecole->nbClasse;
	else
	{
		// Il faut crer une classe
		ptr_classe = CreationClasse();
		
		strcpy(ptr_classe->nomClasse, ptr_eleve->nomClasse);
		
		AjouterClasse(ptr_ecole, ptr_classe);
		
		AjouterEleveDansClasse(ptr_classe, ptr_eleve);
		
		//SupprimerEleve(ptr_eleve);
	}
	

	//Liste d'attente.
}



Eleve_t* RechercherEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char* prenom)
{
	Classe_t* ptr_classeCourante = ptr_ecole->premiereClasse;
	
	Eleve_t *ptr_eleve;
	
	
	// Tant qu'on a pas parcouru toute les classes
	while (ptr_classeCourante != NULL)
	{
		ptr_eleve = RechercherEleveDansClasse(ptr_classeCourante, nom, prenom);
		// Si l'élève est dans cette classe alors on retourne le pointeur de la classe
		if (ptr_eleve != NULL)
			return ptr_eleve;
		
		ptr_classeCourante = ptr_classeCourante->suivant;
	}
	
	return NULL;
}



void SupprimerEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char *prenom)
{
	Classe_t *ptr_classe;
	
	Eleve_t *ptr_eleve;
	
	
	
	ptr_eleve = RechercherEleveDansEcole(ptr_ecole, nom, prenom);
	
	if (ptr_eleve == NULL)
	{
		printf("Cet eleve n'exite pas.\n");
		return;
	}
	
	ptr_classe = RechercherClasseEleve(ptr_ecole->premiereClasse, ptr_eleve);
	if (ptr_classe == NULL)
		printf("Erreur dans la recherche de la classe.\n");
	else
		SupprimerEleveDansClasse(ptr_classe, ptr_eleve);
}



void ModificationEleve(Ecole_t *ptr_ecole, Eleve_t *ptr_eleve)
{
	Classe_t *ptr_classe, *ptr_ancienneClasse;
	
	char choix;
	
	int continuer = 0;
	
	
	
	// On recupère sa classe pour plus tard
	ptr_ancienneClasse = RechercherClasseEleve(ptr_ecole->premiereClasse, ptr_eleve);
	
	printf("Modification de l'eleve :\n\n");
	
	SaisirEleve(ptr_eleve, NULL, NULL);
	
	RetourLigne(2);
	
	do
	{
		printf("Voulez-vous modifier l'emplacement de l'élève ? (O/n) ");
		scanf("%c", &choix);
		ViderBuffer();
		
		switch(choix)
		{
			case 'O':
			case 'o':
				// On recherche une classe corespondant à son nouveau niveau
				ptr_classe = RechercherNiveauClasse(ptr_ecole->premiereClasse, ptr_eleve);
				
				// Si on l'a trouvé alors on l'ajoute dans la nouvelle classe
				if (ptr_classe != NULL)
				{
					// On retire l'élève de son ancienne classe
					RetirerEleveDansClasse(ptr_ancienneClasse, ptr_eleve);
					// On l'ajoute dans la nouvelle
					AjouterEleveDansClasse(ptr_classe, ptr_eleve);
				}
				// Sinon on le laisse ou il est.
				else
					printf("L'eleve ne peux pas aller dans une autre classe");
					// Eventuellement proposer de le supprimer
				
				continuer = 1;
				break;
			case 'N':
			case 'n':
				continuer = 1;
				break;
			default:
				printf("Choix non valide !\n");
		}
	} while (!continuer);
}



void AjouterClasse(Ecole_t *ptr_ecole, Classe_t *ptr_classeAAjouter)
{
	Classe_t *ptr_classeCourante = ptr_ecole->premiereClasse;
	
	char* classe[5] = {"CP", "CE1", "CE2", "CM1", "CM2"};
	
	int i = 0, j = 0;
	
	
	
	// Si il n'y a aucune classe alors on l'ajoute.
	if (ptr_ecole->nbClasse == 0)
	{
		ptr_ecole->premiereClasse = ptr_classeAAjouter;
		++ptr_ecole->nbClasse;
		return;
	}
	
	if (i == 5)
		exit(EXIT_FAILURE);
	
	while (strcmp(classe[i], ptr_classeAAjouter->nomClasse) != 0)
		++i;
	
	// On ce place au bon endroit
	while (j < i && ptr_classeCourante->suivant != NULL)
	{
		ptr_classeCourante = ptr_classeCourante->suivant;
		++j;
	}
	
	if (ptr_classeCourante->precedent == NULL)
	{
		ptr_ecole->premiereClasse = ptr_classeAAjouter;
		ptr_classeCourante->precedent = ptr_classeAAjouter;
		ptr_classeAAjouter->suivant = ptr_classeCourante;
	}
	else
	{
		ptr_classeAAjouter->suivant = ptr_classeCourante;
		ptr_classeAAjouter->precedent = ptr_classeCourante->precedent;
		ptr_classeCourante->precedent->suivant = ptr_classeAAjouter;
		ptr_classeCourante->precedent = ptr_classeAAjouter;
	}
	
	++ptr_ecole->nbClasse;
}
