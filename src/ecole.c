#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "ecole.h"




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
		AfficherClasse(*ptr_classeCourante);
		ptr_classeCourante = ptr_classeCourante->suivant;
	}
}



void AjouterEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char *prenom)
{
	Classe_t *ptr_classe;
	
	Eleve_t *ptr_eleve; 
	
	
	
	// Appel a CreationEleve pour créer l'espace d'un eleve en memoire
	ptr_eleve = CreationEleve();
	
	// Appel a SaisirEleve avec le nom et prenom precedement saisie pour remplir les autre champs (age, etc...)
	SaisirEleve(ptr_eleve, nom, prenom);
	
	// Recherche de la classe qui correspond au niveau de l'élève
	ptr_classe = RechercherNiveauClasse(ptr_ecole->premiereClasse, ptr_eleve);
	
	if (ptr_classe != NULL)
		AjouterEleveDansClasse(ptr_classe, ptr_eleve);
	else
		SupprimerEleve(ptr_eleve);
	

	//Liste d'attente.
}



Eleve_t* RechercherEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char* prenom)
{
	Classe_t* ptr_classeCourante = ptr_ecole->premiereClasse;
	
	Eleve_t *ptr_eleve;
	
	
	// Tant qu'on a pas parcouru toute les classes
	while (ptr_classeCourante->suivant != NULL)
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
		printf("Erreur dans la recherche de la classe");
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
