#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "classe.h"


Classe_t* CreationClasse(void)
{
	Classe_t *ptr_classe;
	
	ptr_classe = (Classe_t*) calloc (1, sizeof(Classe_t));
	
	if (ptr_classe == NULL)
		exit(EXIT_FAILURE);
	
	return ptr_classe;
}



void AfficherClasse(Classe_t classe)
{
	Eleve_t *ptr_eleveCourant = classe.premierEleve;
	
	
	// Si il n'y a pas d'élève dans la classe on sort de la fonction
	if (ptr_eleveCourant == NULL)
		return;
	
	while (ptr_eleveCourant->suivant != NULL)
	{
		AfficherEleve(*ptr_eleveCourant);
		ptr_eleveCourant = ptr_eleveCourant->suivant;
		
		// Tant que l'on est pas sur le dernier élève, on saute des lignes
		if (ptr_eleveCourant->suivant != NULL)
			RetourLigne(2);
	}
}



void SupprimerClasse(Classe_t *ptr_classe)
{
	free(ptr_classe);
}



Eleve_t* RechercherEleveDansClasse(Classe_t *ptr_classe, char *nom, char *prenom)
{
	Eleve_t* eleveCourant = ptr_classe->premierEleve;

	
	
	while (strcmp(eleveCourant->nom, nom) != 0 && strcmp(eleveCourant->prenom, prenom) != 0 && eleveCourant->suivant != NULL)
		eleveCourant = eleveCourant->suivant;

	if(strcmp(eleveCourant->nom, nom) == 0 && strcmp(eleveCourant->prenom, prenom) ==0)
		return eleveCourant;
	else
		return NULL;
}



void AjouterEleveDansClasse(Classe_t* ptr_classe, Eleve_t* ptr_eleve)
{
	Eleve_t *eleveCourant;

	if(ptr_classe->nbEleve >= 25)
	{
		//Ouvrir une classe
	}

	else
	{
		if (ptr_classe->premierEleve == NULL)
			ptr_classe->premierEleve = ptr_eleve;
		else
		{
			eleveCourant = ptr_classe->premierEleve;
			eleveCourant = DernierEleve(eleveCourant);
			eleveCourant->suivant = ptr_eleve;
		}
	}
	
	++ptr_classe->nbEleve;
}



void RetirerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve)
{
	// On verifie que l'élève appartient bien a cette classe
	if (RechercherEleveDansClasse(ptr_classe, ptr_eleve->nom, ptr_eleve->prenom) == NULL)
		exit(EXIT_FAILURE);
	
	// Si l'élève est le seul de la classe on le retire
	if (ptr_classe->nbEleve == 1)
		ptr_classe->premierEleve = NULL;
	// Sinon si il est le premier de la classe on modifie le premier élève de la classe
	else if (ptr_eleve->precedent == NULL)
	{
		ptr_classe->premierEleve = ptr_eleve->suivant;
		ptr_classe->premierEleve->precedent = NULL;
	}
	// Sinon si il est le dernier de la classe on le retire de la fin de classe.
	else if (ptr_eleve->suivant == NULL)
		ptr_eleve->precedent->suivant = NULL;
	// Sinon on le retire du milieu de la classe
	else
	{
		ptr_eleve->precedent->suivant = ptr_eleve->suivant;
		ptr_eleve->suivant->precedent = ptr_eleve->precedent;
	}
	
	// On enlève un élève dans le total d'élève
	--ptr_classe->nbEleve;
}



void SupprimerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve)
{
	// Si ptr_eleve vaut NULL on sort de la fonction
	if (ptr_eleve == NULL)
		return;
	
	// Si l'élève est le premier de la classe alors le champ classe de ptr_classe pointer sur le deuxième élève
	if (ptr_eleve->precedent == NULL)
		ptr_classe->premierEleve = ptr_eleve->suivant;
	
	// Si il est le dernier alors l'avant dernier eleve doit avoir son champ suivant sur NULL
	else if (ptr_eleve->suivant == NULL)
		ptr_eleve->precedent->suivant = NULL;
	
	// Si l'élève a supprimer est au milieu d'autre élève il faut l'enlever de là
	else
	{
		ptr_eleve->precedent->suivant = ptr_eleve->suivant;
		ptr_eleve->suivant->precedent = ptr_eleve->precedent;
	}
	
	SupprimerEleve(ptr_eleve);
}



Classe_t* RechercherClasseEleve(Classe_t* ptr_classeCourante, Eleve_t * ptr_eleve)
{
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



Classe_t* RechercherNiveauClasse(Classe_t *ptr_classeCourante, Eleve_t *ptr_eleve)
{
	// Si la première classe n'existe pas
	if (ptr_classeCourante == NULL)
		return NULL;
	
	while (ptr_classeCourante != NULL)
	{
		if (strncmp(ptr_classeCourante->nomClasse, ptr_eleve->nomClasse, 2) == 0)
			return ptr_classeCourante;
		
		ptr_classeCourante = ptr_classeCourante->suivant;
	}
	
	return NULL;
}



void RepartitionEleveDansClasse(Classe_t *ptr_classe)
{
	Eleve_t *ptr_eleve, *ptr_dernierEleve;
	
	char typeClasse[3]; // 'C' 'P' '\0', ou 'C' 'E' '\0', etc
	
	int nbEleveATranferer = 0;
	
	
	
	// Si ptr_classe est NULL on sort du programme.
	if (ptr_classe == NULL)
		exit(EXIT_FAILURE);
	
	strncpy(typeClasse, ptr_classe->nomClasse, 2);
	
	// Si la classe suivant existe et est une classe de même niveau
	if (ptr_classe->suivant == NULL || strstr(ptr_classe->suivant->nomClasse, typeClasse) == NULL)
		return;
	
	// Si la classe depasse le seuil
	if (ptr_classe->nbEleve > SEUIL)
	{
		// On calcule combien d'élève vont devoir etre transféré dans l'autre classe
		nbEleveATranferer = ptr_classe->nbEleve + ptr_classe->suivant->nbEleve;
		nbEleveATranferer /= 2;
		
		// Si la classe a plus d'élève que la classe suivante
		if (ptr_classe->nbEleve > ptr_classe->suivant->nbEleve)
		{
			// Tant qu'on a pas atteint le premier eleve de la liste d'élève à tranférer on passe au suivant
			ptr_eleve = ElevePosition(ptr_classe->premierEleve, ptr_classe->nbEleve - nbEleveATranferer);
			
			// On recupère le dernier élève de la classe suivante
			ptr_dernierEleve = DernierEleve(ptr_classe->suivant->premierEleve);
			
			// Puis on transfère les élève dans l'autre classe.
			ptr_dernierEleve->suivant = ptr_eleve;
			
			ptr_eleve->precedent->suivant = NULL;
			ptr_eleve->precedent = ptr_dernierEleve;
			
			ptr_classe->nbEleve -= nbEleveATranferer;
			ptr_classe->suivant->nbEleve += nbEleveATranferer;
		}
		else
		{
			// Tant qu'on a pas atteint le premier eleve de la liste d'élève à tranférer on passe au suivant
			ptr_eleve = ElevePosition(ptr_classe->suivant->premierEleve, ptr_classe->suivant->nbEleve - nbEleveATranferer);
			
			// On recupère le dernier élève de la classe
			ptr_dernierEleve = DernierEleve(ptr_classe->premierEleve);
			
			// Puis on transfère les élève dans l'autre classe.
			ptr_dernierEleve->suivant = ptr_eleve;
			
			ptr_eleve->precedent->suivant = NULL;
			ptr_eleve->precedent = ptr_dernierEleve;
			
			ptr_classe->nbEleve += nbEleveATranferer;
			ptr_classe->suivant->nbEleve -= nbEleveATranferer;
		}
	}
	// Sinon si la classe suivante depasse le seuil
	else if (ptr_classe->suivant->nbEleve > SEUIL)
	{
		// On calcule combien d'élève vont devoir etre transféré dans l'autre classe
		nbEleveATranferer = ptr_classe->nbEleve + ptr_classe->suivant->nbEleve;
		nbEleveATranferer /= 2;
		
		// Tant qu'on a pas atteint le premier eleve de la liste d'élève à tranférer on passe au suivant
		ptr_eleve = ElevePosition(ptr_classe->suivant->premierEleve, ptr_classe->suivant->nbEleve - nbEleveATranferer);
		
		// On recupère le dernier élève de la classe
		ptr_dernierEleve = DernierEleve(ptr_classe->premierEleve);
		
		// Puis on transfère les élève dans l'autre classe.
		ptr_dernierEleve->suivant = ptr_eleve;
		
		ptr_eleve->precedent->suivant = NULL;
		ptr_eleve->precedent = ptr_dernierEleve;
		
		ptr_classe->nbEleve += nbEleveATranferer;
		ptr_classe->suivant->nbEleve -= nbEleveATranferer;
	}
}



void AfficherListeClasse(Classe_t *ptr_classeCourante)
{
	int i = 1;
	
	
	if (ptr_classeCourante == NULL)
		return;
	
	while(ptr_classeCourante != NULL)
	{
		printf("%d - %s\n", i, ptr_classeCourante->nomClasse);
		ptr_classeCourante = ptr_classeCourante->suivant;
		++i;
	}
}
