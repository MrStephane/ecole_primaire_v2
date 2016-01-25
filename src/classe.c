#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "classe.h"




void AfficherClasse(Classe_t classe)
{
	Eleve_t *ptr_eleveCourant = classe->classe;
	
	
	// Si il n'y a pas d'élève dans la classe on sort de la fonction
	if (ptr_eleveCourant == NULL)
		return;
	
	while (ptr_eleveCourant->suivant != NULL)
	{
		AfficherEleve(*ptr_eleveCourant);
		ptr_eleveCourant = ptr_eleveCourant->suivant;
		
		// Tant que l'on est pas sur le dernier élève, on saute des lignes
		if (ptr_eleveCourant->suivant != NULL)
			SautLigne(2);
	}
}



void SupprimerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve)
{
	// Si ptr_eleve vaut NULL on sort de la fonction
	if (ptr_eleve == NULL)
		return;
	
	// Si l'élève est le premier de la classe alors le champ classe de ptr_classe pointer sur le deuxième élève
	if (ptr_eleve->precedent == NULL)
		ptr_classe->classe = ptr_eleve->suivant;
	
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
			ptr_eleve = ElevePosition(ptr_classe->classe, ptr_classe->nbEleve - somme);
			
			// On recupère le dernier élève de la classe suivante
			ptr_dernierEleve = DernierEleve(ptr_classe->suivant->classe);
			
			// Puis on transfère les élève dans l'autre classe.
			ptr_dernierEleve->suivant = ptr_eleve;
			
			ptr_eleve->precedent->suivant = NULL;
			ptr_eleve->precedent = ptr_dernierEleve;
			
			ptr_classe->nbEleve -= somme;
			ptr_classe->suivant->nbEleve += somme;
		}
		else
		{
			// Tant qu'on a pas atteint le premier eleve de la liste d'élève à tranférer on passe au suivant
			ptr_eleve = ElevePosition(ptr_classe->suivant->classe, ptr_classe->suivant->nbEleve - somme);
			
			// On recupère le dernier élève de la classe
			ptr_dernierEleve = DernierEleve(ptr_classe->classe);
			
			// Puis on transfère les élève dans l'autre classe.
			ptr_dernierEleve->suivant = ptr_eleve;
			
			ptr_eleve->precedent->suivant = NULL;
			ptr_eleve->precedent = ptr_dernierEleve;
			
			ptr_classe->nbEleve += somme;
			ptr_classe->suivant->nbEleve -= somme;
		}
	}
	// Sinon si la classe suivante depasse le seuil
	else if (ptr_classe->suivant->nbEleve > SEUIL)
	{
		// On calcule combien d'élève vont devoir etre transféré dans l'autre classe
		nbEleveATranferer = ptr_classe->nbEleve + ptr_classe->suivant->nbEleve;
		nbEleveATranferer /= 2;
		
		// Tant qu'on a pas atteint le premier eleve de la liste d'élève à tranférer on passe au suivant
		ptr_eleve = ElevePosition(ptr_classe->suivant->classe, ptr_classe->suivant->nbEleve - somme);
		
		// On recupère le dernier élève de la classe
		ptr_dernierEleve = DernierEleve(ptr_classe->classe);
		
		// Puis on transfère les élève dans l'autre classe.
		ptr_dernierEleve->suivant = ptr_eleve;
		
		ptr_eleve->precedent->suivant = NULL;
		ptr_eleve->precedent = ptr_dernierEleve;
		
		ptr_classe->nbEleve += somme;
		ptr_classe->suivant->nbEleve -= somme;
	}
}



/********************************************
 *  vvvvvv Fonction a modifier ou supprimer *
 ********************************************/



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
	    CopieEleve(&e, *ptr_e);

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

void RepartEleve(Classe* ecole)
{
	int i;


	for (i=0; i<NBCLASSEMAX; i=i+2)
    {
        // Si la première classe dépasse le seuil d'élève
        if (ecole[i].nbEleve > SEUIL)
        {
            while(ecole[i].nbEleve > ecole[i+1].nbEleve+1)
            {
                CopieEleve(&ecole[i+1].classe[ecole[i+1].nbEleve], ecole[i].classe[ecole[i].nbEleve-1]);
                --ecole[i].nbEleve;
                ++ecole[i+1].nbEleve;
            }
        }
        else if (ecole[i+1].nbEleve > SEUIL)
        {
            while(ecole[i].nbEleve < ecole[i+1].nbEleve)
            {
                CopieEleve(&ecole[i].classe[ecole[i].nbEleve], ecole[i+1].classe[ecole[i+1].nbEleve-1]);
                --ecole[i+1].nbEleve;
                ++ecole[i].nbEleve;
            }
        }
    }
}

**********************************************************************************************************
**********************************************************************************************************
*********************************A MODIFIER AjouterEleveDansClasse****************************************
**********************************************************************************************************
**********************************************************************************************************

void AjouterEleveDansClasse(Classe_t* ptr_classe, Eleve_t* ptr_eleve)
{
	Eleve_t *eleveCourant;

	


	if(ptr_classe->nbeleve >= 25)
	{
		//Ouvrir une classe
	}

	else
	{
		eleveCourant = ptr_classe->classe;
		eleveCourant = DernierEleve(eleveCourant);
		eleveCourant->suivant = ptr_eleve;
	}
}