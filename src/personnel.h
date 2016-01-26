#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "fonctionAnnexe.h"

#ifndef PERSONNEL_H
#define PERSONNEL_H


#define TAILLECHAINE 40


/**************
 * Structures *
 **************/


typedef struct Personnel
{
	char civilite[13];
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	char metier[TAILLECHAINE];
	int nbPers;
}Personnel_t;



/*************
 * Fonctions *
 *************/

Personnel_t* CreationPersonnel(void);

/* Fonction : AfficherPersonnel()
 * ----------
 *  Usage : afficher un membre du personnel voulu
 * ----------
 * *Description*
 */
void AfficherPersonnel(Personnel_t personnel);



/* Fonction : SaisirPersonnel()
 * ----------
 *  Usage : enregistrer du personnel dans l'ecole
 * ----------
 * *Description*
 */
void SaisirPersonnel(Personnel_t * ptr_personnel);

/* Fonction : SupprimerPersonnel()
 * ----------
 *  Usage : supprimer un membre du personnel
 * ----------
 * *Description*
 */

void SupprimerPersonnel(Personnel_t *ptr_personnel);
#endif // PERSONNEL_H
