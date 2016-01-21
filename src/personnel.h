#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#ifndef PERSONNEL_H
#define PERSONNEL_H


/**************
 * Structures *
 **************/


typedef struct Personnel  
{     
	char civilite[13];     
	char nom[TAILLECHAINE];     
	char prenom[TAILLECHAINE];     
	char metier[TAILLECHAINE];
}Personnel_t;



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
void AfficherPersonnel(Personnel_t personnel);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SaisirPersonnel(Personnel_t * ptr_personnel);


#endif // PERSONNEL_H
