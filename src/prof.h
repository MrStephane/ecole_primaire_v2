#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
 *  Usage : AfficherProf(professeur);
 * -----------------------
 * Affiche les informations d'un prof.
 */
void AfficherProf(Prof_t prof);



/* Fonction : SaisirProf
 * ---------------------
 * Entrée : ptr_prif - Pointeur sur le prof à saisir.
 * Sortie : Aucune
 *  Usage : SaisirProf(ptr_prof);
 * ---------------------
 * Saisie les informations d'un professeur.
 */
void SaisirProf(Prof_t* ptr_prof);



/* Fonction : SupprimerProf
 * ------------------------
 * Entrée : ptr_prof - Pointeur sur le prof à supprimer.
 * Sortie : Aucune
 *  Usage : SupprimerProf(ptr_prof);
 * ------------------------
 * Supprime le prof de la mémoire.
 */
void SupprimerProf(Prof_t *ptr_prof);


#endif // PROF_H

