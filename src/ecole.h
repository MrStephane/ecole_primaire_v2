#include "classe.h"


#ifndef ECOLE_H
#define ECOLE_H


#define TAILLECHAINE 40



/**************
 * Structures *
 **************/


typedef struct Ecole
{
	char nomEcole[TAILLECHAINE];
	int nbClasse;
	Classe_t *premiereClasse;	// Pointeur sur la première classe.
} Ecole_t;




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
void AjouterEleveDansEcole(Ecole_t *ptr_ecole);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SupprimerEleveDansEcole(Ecole_t *ptr_ecole);



#endif