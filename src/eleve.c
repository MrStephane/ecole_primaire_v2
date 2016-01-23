#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "eleve.h"

*********************************
//Appel de la fonction creerEleve
*********************************

void SaisirEleve(Eleve_t* ptr_eleve, char* nom, char* prenom)
{
	char* nomCategorie[5] = {"CP", "CE1", "CE2", "CM1", "CM2"};

	int categorie;
	int genre;

	
	// Si on a pas passé de nom en paramètre alors on le saisi
	if (nom == NULL)
		SaisieChaineControle(ptr_eleve->nom, "\nNom : ");
	else
		strcpy(ptr_eleve->nom, nom);

	// Si on a pas passé de prenom en paramètre alors on le saisi
	if (prenom == NULL)
		SaisieChaineControle(ptr_eleve->nom, "\nPrenom : ");
	else
		strcpy(ptr_eleve->prenom, prenom);

	NormaliserNomPrenom(NULL, ptr_eleve->nom, ptr_eleve->prenom);

    do
    {
        printf("\tDate de naissance ");
        SaisirDate(&ptr_eleve->dateDeNaissance);
    } while (ControleDate(ptr_eleve->dateDeNaissance) != 1);

	ptr_eleve->age = CalculerAge(dateJ, ptr_eleve->dateDeNaissance);
	categorie = CategorieAge(ptr_eleve->dateDeNaissance, rentreeScolaire);

	// Si l'élève a un niveau primaire alors on lui attribut un nom de classe
	if (categorie > 5 && categorie < 11)
        strcpy(ptr_eleve->nomClasse, nomCategorie[categorie-6]);
	else
        strcpy(ptr_eleve->nomClasse, "NULL");


    do
    {
    	printf("\tS'agit-il d'un garcon (0) ou d'une fille (1) : ");
    	scanf("%d", &genre);
    	ViderBuffer();

    	if (genre != 0 && genre != 1)
    		printf("\tErreur !\n");
    } while (genre != 0 && genre != 1);

    ptr_eleve->genre = genre;

    RetourLigne(1);
}



void AfficherEleve(Eleve_t eleve, char* nom, char* prenom)
{
    printf("\t| %s %s\n", eleve.nom, eleve.prenom);
    printf("\t| Ne le ");
    AfficherDate(eleve.dateDeNaissance);
    RetourLigne(2);
}



void CopieEleve(Eleve_t* eleveCopie, Eleve_t eleveACopie)
{
	eleveCopie->precedent->suivant = eleveACopie;
	eleveACopie->precedent = eleveCopie->precedent;
	eleveACopie->suivant = eleveCopie->suivant;
}



Eleve_t* ElevePosition(Eleve_t *ptr_eleveCourant, int position)
{
	int i = 1;
	
	
	if (ptr_eleveCourant == NULL)
		exit(EXIT_FAILURE);
	
	while (i < position && ptr_eleveCourant->suivant != NULL)
	{
		++i;
		ptr_eleveCourant = ptr_eleveCourant->suivant;
	}
	
	if (i == position)
		return ptr_eleveCourant;
	else
		return NULL;
}
