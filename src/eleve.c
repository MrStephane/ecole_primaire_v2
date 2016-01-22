#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include “eleve.h”

*********************************
//Appel de la fonction creerEleve
*********************************

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
			scanf("%s", ptr_eleve->nom);
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
			scanf("%s", ptr_eleve->prenom);
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
    	printf("\tS'agit-il d'un garcon (0) ou d'une fille (1) : ");
    	scanf("%d", &genre);
    	ViderBuffer();

    	if (genre != 0 && genre != 1)
    		printf("\tErreur !\n");
    } while (genre != 0 && genre != 1);

    ptr_eleve->genre = genre;

    RetourLigne(1);
}

void AfficherEleve(Eleve_t eleve, char* nom, char* prenom);
{
    printf("\t| %s %s\n", eleve.nom, eleve.prenom);
    printf("\t| Ne le ");
    AfficherDate(eleve.dateDeNaissance);
    RetourLigne(2);
}

void SupprimerEleve(Classe_t* tete)
{
	Classe_t* ptr_c;

	Eleve_t* ptr_e;

	Eleve_t* eleveCourant;

	eleveCourant = tete->classe;

	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];

	Classe_t *classeCourant;

    classeCourant = tete;
       
	printf("\n\tNom prenom : ");
	scanf("%s %s", nom, prenom);
	ViderBuffer();

	NormaliserNomPrenom(NULL, nom, prenom);

	ptr_e = RechercherEcole(nom, prenom, ecole);
	
	while(courant != NULL)
	{
		if (ptr_e != NULL)
		{
			ptr_c = RechercherClasse(ptr_e->nomClasse, ecole);

			if (ptr_c->nbEleve > 0)
			{
				eleveCourant = classeCourant->classe;
				while(eleveCourant->suivant !=NULL)
					{
						eleveCourant = eleveCourant->suivant;
					}

				CopieEleve(ptr_e, eleveCourant);
				(ptr_c->nbEleve)--;
				printf("\n\tEleve supprime.\n");
			}
		}
		else
			printf("\n\tCet eleve n'existe pas.\n");
	}
	classeCourant = classeCourant->suivant;
}

******************************************************************
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
*****************************************************************

void AjouterEleve(Classe_t* ecole, int* nbClasses, Eleve* listeAttente, int* nbEleveListe, char* nom, char* prenom)
{
	Eleve e;	// Structure d'élève provisoire

	Classe_t * classeDispo;	// Pointeur sur une classe s'il y en a une de disponible


	SaisirEleve(&e, nom, prenom);

	// Si l'élève existe déja alors on ne l'enregistre pas
	if (RechercherEcole(e.nom, e.prenom, ecole) != NULL)
	{
		printf("\n\tCet eleve existe deja.\n");
		RetourLigne(1);
		return;
	}

	// Si l'enfant saisi n'a pas le niveau de l'école primaire on ne l'enregistre pas.
	if (strcmp(e.nomClasse, "NULL") == 0)
	{
        printf("\n\tCet enfant n'a pas l'age requit pour l'ecole primaire.\n");
		return;
	}

	classeDispo = RechercherClasseDispo(e.nomClasse, ecole);

	// Si il y a une classe disponible dans le niveau de l'élève alors on l'enregistre dans la classe et on augmente le nombre d'élève de celle-ci
	if (classeDispo != NULL)
	{
		// Si il s'agit d'une nouvelle classe alors on incrémente le nombre de classes
		if (classeDispo->nbEleve == 0)
        {
            printf("\n\tUne nouvelle classe vient d'etre ouverte.\n");
			RetourLigne(2);
			printf("\tVeuillez saisir le nouveau professeur :\n");
            SaisirProf(&classeDispo->professeur);
            ++(*nbClasses);
        }

		strcpy(e.nomClasse, classeDispo->nomClasse);

		// On enregistre définitivement l'élève dans la première place disponible dans la classe.

		while(classeCourant->suivant !=NULL)
					{
						eleveCourant = eleveCourant->suivant;
					}

		CopieEleve(&classeDispo->classe[classeDispo->nbEleve], e);
		++(classeDispo->nbEleve);
		RepartEleve(ecole);

		ClasserEleve(classeDispo);
	}

	else
	{
		printf("\tIl n'y a plus de place disponible en %s.\n\tCet eleve est place sur liste d'attente\n", e.nomClasse);
        CopieEleve(&listeAttente[*nbEleveListe], e);
		++*nbEleveListe;
		//printf("\n\tIl n'y a plus de classe disponible en %s.\n\n\n", e.nomClasse);
	}

    RetourLigne(2);
}



//FINI
Eleve* RechercherEleve(char* nom, char* prenom, Classe_t* c)
{
	int i;

	Eleve_t *courant;

	courant = c->classe;

	// Si il n'y a pas d'élève dans la classe pas besoin de chercher
	if (c->nbEleve == 0)
		return NULL;

	while(courant != NULL)
    {
		// Si le nom correspond on teste le prénom sinon on passe au suivant
		if (strcmp(nom, courant->nom) == 0)
			// Si le prénom correspond alors on a trouvé l'élève et on retourne l'adresse de la structure Eleve
			if (strcmp(prenom, courant->prenom) == 0)
                return courant;

	courant = courant->suivant;
    }

	return NULL;
}

******************************************************************
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
*****************************************************************


//FINI
Eleve* RechercherEcole(char *nom, char *prenom, Classe_t *courant)
{
    int i;
    Eleve_t* ptr_eleve;

    Classe_t *courant;

    while(courant != NULL)
    {
        ptr_eleve = RechercherEleve(nom, prenom, courant);

        if(ptr_eleve != NULL)
        {
            return ptr_eleve;
        }

        courant = courant->suivant;
    }

    return 0;
}


******************************************************************
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
*****************************************************************

void MiseAJourEleve(Classe_t* ecole, int* nbClasses)
{
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	char caract;

	Eleve_t* ptr_e;
	Eleve_t e;
	Eleve_t *eleveCourant;

	eleveCourant = classeCourant->classe;

	Classe_t *ptr_c, *ptr_classeDispo;
	Classe_t *classeCourant;

	int min = 0, max = NBCLASSEMAX;
	int i, j;
	int continuer = 0;


	do
	{
		continuer = 1;
		printf("\tEntrez son nom et son prenom : ");
		scanf("%s %s", nom, prenom);
		ViderBuffer();

		if (ControleChaine(nom) == 0 || ControleChaine(prenom) == 0)
		{
			printf("\n\tEcrivez le nom et le prenom sans chiffres ni accents !\n");
			continuer = 0;
		}
	} while (!continuer);


	NormaliserNomPrenom(NULL, nom, prenom);

	ptr_e = RechercherEcole(nom, prenom, classeCourant);

	// Si l'élève existe alors le mettre a jour
	if (ptr_e != NULL)
	{
        RetourLigne(1);
		printf("\n\tVeuillez corriger les informations :\n");
		RetourLigne(1);
        SaisirEleve(ptr_e,NULL, NULL);
    }
    else
    {
        printf("\n\tCet eleve n'existe pas dans cette ecole.\n");
        return;
    }

    printf("\n\tVoulez-vous replacer l'eleve dans la bonne classe ? (o/n)\n");
    continuer = 0;
	do
    {
    	printf("\tVotre choix : ");
    	scanf("%c", &caract);
    	ViderBuffer();

    	switch (caract)
    	{
    		case 'O':
    		case 'o':
    			continuer = 1;
    			break;
    		case 'N':
    		case 'n':
    			// On sort de la fonction
    			return;
    			break;
    		default :
    			printf("\tErreur !\n");
    	}
    }while (!continuer);

    // Si l'enfant saisi n'a pas le niveau de l'école primaire on ne l'enregistre pas.
	if (strcmp(ptr_e->nomClasse, "NULL") == 0)
	{
        printf("\n\tCet enfant n'a pas l'age requit pour l'ecole primaire.\n");
		return;
	}

    // On recherche si il y a une classe disponible pour l'élève modifié
    ptr_classeDispo = RechercherClasseDispo(ptr_e->nomClasse, classeCourant);

	// Si il y a une classe disponible dans le niveau de l'élève alors on l'enregistre dans la classe et on augmente le nombre d'élève de celle-ci
	if (ptr_classeDispo != NULL)
	{


	    LimiteParcours(ptr_e->nomClasse, &min, &max);

	    while(classeCourant != NULL)
    	{

		    // Boucle pour récupérer la classe de l'élève
			for (i=min; i<max; ++i)
		    {
		        j = 0;
		        // Tant que on est pas sur le bon élève
		        while (j < classeCourant.nbEleve && eleveCourant != ptr_e)
		        {
		        	eleveCourant = eleveCourant->suivant;
		            ++j;
		        }

		        if (j < classeCourant.nbEleve)
		            if (eleveCourant == ptr_e)
		                ptr_c = classeCourant;
		    }

	    classeCourant = classeCourant->suivant;
		}

	    // On copie l'élève modifier dans une struct Eleve provisoire
	    CopieEleve(e, *ptr_e);

	    // On copie le dernier élève de la classe a la place de l'élève modifier
	    CopieEleve(ptr_e, ptr_c->classe[ptr_c->nbEleve-1]);

	    // On reduit le nombre d'élève de cette classe
	    --ptr_c->nbEleve;

		// Si il s'agit d'une nouvelle classe alors on incrémente le nombre de classes
		if (ptr_classeDispo->nbEleve == 0)
        {
            SaisirProf(&ptr_classeDispo->professeur);
            ++(*nbClasses);
        }

        strcpy(e.nomClasse, ptr_classeDispo->nomClasse);

		// On enregistre définitivement l'élève dans la première place disponible dans la classe.
		CopieEleve(&ptr_classeDispo->classe[ptr_classeDispo->nbEleve], e);
		++(ptr_classeDispo->nbEleve);

		ClasserEleve(ptr_classeDispo);
	}
	else
	{
        printf("\tIl n'y a plus de classe disponible en %s.\n", ptr_e->nomClasse);
    }
}

void CopieEleve(Eleve* eleveCopie, Eleve eleveACopie)
{
	eleveCopie->precedent->suivant = eleveACopie;
	eleveACopie->precedent = eleveCopie->precedent;
	eleveACopie->suivant = eleveCopie->suivant;
}



Eleve_t* DernierEleve(Eleve_t *courant)
{
	if (courant == NULL)
		return NULL;
	
	while (courant->suivant != NULL)
	{
		courant = courant->suivant
	}
	
	return courant;
}