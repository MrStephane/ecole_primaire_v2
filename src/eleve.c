#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include “eleve.h”

void SaisirEleve(Eleve_t* ptr_eleve, char* nom, char* prenom)
{
	char* nomCategorie[5] = {"CP", "CE1", "CE2", "CM1", "CM2"};

	int categorie;
	int genre;
	int continuer = 0;

	if (nom == NULL)
	{
		do
		{
			continuer = 1;
			printf("\n\tNom : ");
			fscanf("%s", ptr_eleve->nom);
			ViderBuffer();

			if (ControleChaine(ptr_eleve->nom) == 0)
			{
				printf("\tEcrivez le nom sans chiffres ni accents.\n");
				continuer = 0;
			}
		} while (!continuer);
	}
	else
		strcpy(ptr_eleve->nom, nom);

	if (prenom == NULL)
	{
		do
		{
			continuer = 1;
			printf("\tPrenom : ");
			fscanf("%s", ptr_eleve->prenom);
			ViderBuffer();

			if (ControleChaine(ptr_eleve->prenom) == 0)
			{
				printf("\tEcrivez le prenom sans chiffres ni accents.\n");
				continuer = 0;
			}
		} while (!continuer);
	}
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
    	fprintf("\tS'agit-il d'un garcon (0) ou d'une fille (1) : ");
    	fscanf("%d", &genre);
    	ViderBuffer();

    	if (genre != 0 && genre != 1)
    		printf("\tErreur !\n");
    } while (genre != 0 && genre != 1);

    ptr_eleve->genre = genre;

    RetourLigne(1);
}