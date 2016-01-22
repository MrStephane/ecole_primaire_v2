#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fonctionAnnexe.h"

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
	int nbPers = 0;
}Personnel_t;



/*************
 * Fonctions *
 *************/


/* Fonction :
 * ----------
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void AfficherPersonnel(Personnel_t personnel);



/* Fonction :
 * ----------
 * Entrée :
 *  Usage :
 * ----------
 * *Description*
 */
void SaisirPersonnel(Personnel_t * ptr_personnel);


#endif // PERSONNEL_H
