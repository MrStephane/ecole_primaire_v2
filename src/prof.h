#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fonctionAnnexe.h"


#ifndef PROF_H
#define PROF_H


#define TAILLECHAINE 40



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


/* Fonction : CreationProf
 * -----------------------
 * Entrée : Aucune
 * Sortie : Un pointeur sur le prof créé.
 *  Usage : ptr_prof = CreationProf();
 * -----------------------
 * Créé en mémoire une structure prof initialisé à 0.
 */
Prof_t* CreationProf(void);



/* Fonction : AfficherProf
 * -----------------------
 * Entrée : prof - Le prof dont on souhaite afficher les infos.
 * Sortie : Aucune.
 *  Usage : AfficherProf(prof);
 * -----------------------
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



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SupprimerProf(Prof_t *ptr_prof);


#endif // PROF_H

