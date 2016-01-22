#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include “date.h”


#ifndef ELEVE_H
#define ELEVE_H

#define TAILLECHAINE 50



/**************
 * Structures *
 **************/


typedef struct Eleve 
{     
	char nom[TAILLECHAINE];     
	char prenom[TAILLECHAINE];     
	int age;     
	struct tm dateDeNaissance;     
	int genre; // 0 pour garcon et 1 pour fille     
	char nomClasse[5]; 
	char adresse[26];
	struct Eleve *suivant;
	struct Eleve *precedent;
}Eleve_t;




/*************
 * Fonctions *
 *************/


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SaisirEleve(Eleve_t* ptr_eleve);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void AfficherEleve(Eleve_t eleve);

/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SupprimerEleve(Classe_t* tete);


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void AjouterEleve(Classe_t* ecole, int* nbClasses, Eleve* listeAttente, int* nbEleveListe, char* nom, char* prenom)


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
Eleve* RechercherEleve(char* nom, char* prenom, Classe_t* c)


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void MiseAJourEleve(Classe_t* ecole, int* nbClasses)


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void CopieEleve(Eleve* eleveCopie, Eleve eleveACopie)


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
Eleve_t* DernierEleve(Eleve_t *courant)

#endif // ELEVE_H
