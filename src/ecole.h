#include "classe.h"


#ifndef ECOLE_H
#define ECOLE_H



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


/* Fonction : AjouterEleveDansEcole
 * --------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on veut ajouter l'élève.
 * Sortie : Aucune.
 *  Usage : AjouterEleveDansEcole(ptr_ecole);
 * --------------------------------
 * Ajoute un élève dans l'école si c'est possible.
 */
void AjouterEleveDansEcole(Ecole_t *ptr_ecole);


/* Fonction : RechercherEleveDansEcole
 * -----------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on recherche l'élève.
 * Sortie : Un pointeur sur l'élève si il est trouvé. Renvoie NULL sinon.
 *  Usage : ptr_eleveRecherche = RechercherEleveDansEcole(ptr_ecole);
 * -----------------------------------
 * Recherche un élève dans l'école.
 */
Eleve* RechercherEleveDansEcole(Ecole_t *ptr_ecole);



/* Fonction : SupprimerEleveDansEcole
 * ----------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on veut supprimer l'élève.
 * Sortie : Aucune.
 *  Usage : SupprimerEleveDansEcole(ptr_ecole);
 * ----------------------------------
 * Supprime un élève de l'école.
 */
void SupprimerEleveDansEcole(Ecole_t *ptr_ecole);



#endif
