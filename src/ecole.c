#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "classe.h"




void AjouterEleveDansEcole(Ecole_t *ptr_ecole)
{
	Classe_t *ptr_classe;
	
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	
	
	
	// Demande le nom et prenom de l'élève
	
	// Appel a CreationEleve pour créer l'espace d'un eleve en memoire
	
	// Appel a SaisirEleve avec le nom et prenom precedement saisie pour remplir les autre champs (age, etc...)
	
	// Recherche de la classe qui correspond au niveau de l'élève
		// Si on la trouve alors on fait appel a AjouterEleveDansClasse
		
		// Si on l'a trouve pas on supprime l'élève de la mémoire
}



void SupprimerEleveDansEcole(Ecole_t *ptr_ecole)
{
	Eleve_t *ptr_eleve;
	Classe_t *ptr_classe;
	
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	
	
	
	printf("\n\tNom prenom : ");
	scanf("%s %s", nom, prenom);
	ViderBuffer();

	NormaliserNomPrenom(NULL, nom, prenom);
	
	ptr_eleve = RechercherEleveDansEcole(ptr_ecole);
	
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
