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
	struct Eleve * suivant;
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
//void SupprimerEleve(Classe_t* ptr_eleve);

#endif // ELEVE_H
