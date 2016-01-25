#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "classe.h"




void AjouterEleveDansEcole(Ecole_t *ptr_ecole)
{
	Classe_t *ptr_classeCourante = ptr_ecole->premiereClasse;
	Eleve_t *ptr_eleve; 
	
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	
	// Demande le nom et prenom de l'élève
	SaisieChaineControle(nom, "Veuillez saisir le nom de l'eleve : ");
	SaisieChaineControle(prenom, "Veuillez saisir le prenom de l'eleve : ");
	
	// Appel a CreationEleve pour créer l'espace d'un eleve en memoire
	ptr_eleve = CreationEleve();
	
	// Appel a SaisirEleve avec le nom et prenom precedement saisie pour remplir les autre champs (age, etc...)
	SaisirEleve(ptr_classe, nom, prenom);
	
	// Recherche de la classe qui correspond au niveau de l'élève
	while(ptr_classeCourante != NULL)
	{
		// Si on la trouve alors on fait appel a AjouterEleveDansClasse
		if(strncmp(ptr_classe->nomClasse, ptr_eleve->nomClasse, 2) == 0)
			AjouterEleveDansClasse(ptr_classeCourante, ptr_eleve);

		ptr_classeCourante = ptr_classeCourante->suivant;
	}
		
	// Si on l'a trouve pas on supprime l'élève de la mémoire
	if(ptr_classeCourante == 0)
	SupprimerEleve(ptr_eleve);

	//Liste d'attente.
}



Eleve* RechercherEleveDansEcole(Ecole_t *ptr_ecole)
{
	Classe_t* ptr_classeCourante;
	ptr_classeCourante = ptr_ecole->premiereClasse;

	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];

	SaisieChaineControle(nom, "Veuillez saisir le nom de l'eleve : ");
	SaisieChaineControle(prenom, "Veuillez saisir le prenom de l'eleve : ");

	// Tant qu'on a pas parcouru toute les classes
	while (ptr_classeCourante->suivant != NULL)
	{
		// Si l'élève est dans cette classe alors on retourne le pointeur de la classe
		if (RechercherEleveDansClasse(ptr_classeCourante, ptr_eleve->nom, ptr_eleve->prenom) != NULL)
			return ptr_classeCourante;
		
		ptr_classeCourante = ptr_classeCourante->suivant;
	}
	
	return NULL;
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