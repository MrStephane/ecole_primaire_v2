#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fonctionAnnexe.h"


#ifndef PROF_H
#define PROF_H



/**************
 * Structures *
 **************/


typedef struct Prof 
{     
	char civilite[13]; // max ==> 'Mademoiselle' - 12 lettres + '\0'     
	char nom[TAILLECHAINE];     
	char prenom[TAILLECHAINE];     
	int age; 
}Prof_t;




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
void AfficherProf(Prof_t prof);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SaisirProf(Prof_t* ptr_prof);


#endif // PROF_H

