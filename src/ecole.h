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


/* Fonction : InitEcole
 * --------------------
 * Entrée : ptr_ecole - Un pointeur sur l'école à initialiser.
 * Sortie : Aucune.
 *  Usage : InitEcole(ptr_ecole);
 * --------------------
 * Initialise les champs d'une école.
 */
void InitEcole(Ecole_t *ptr_ecole);

 
 
/* Fonction : AfficherEcole
 * -------------------------
 * Entrée : ecole - Ecole que l'on veut afficher.
 * Sortie : Aucune.
 *  Usage : AfficherEcole(ecole);
 * -------------------------
 * Affiche la totalité d'une école.
 */
void AfficherEcole(Ecole_t ecole);
 
 
 
/* Fonction : AjouterEleveDansEcole
 * --------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on veut ajouter l'élève.
 *				  nom - Nom de l'élève.
 *			   prenom - Prénom de l'élève.
 * Sortie : Aucune.
 *  Usage : AjouterEleveDansEcole(ptr_ecole);
 * --------------------------------
 * Ajoute un élève dans l'école si c'est possible.
 */
void AjouterEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char *prenom);


/* Fonction : RechercherEleveDansEcole
 * -----------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on recherche l'élève.
 *				  nom - Nom de l'élève.
 *			   prenom - Prénom de l'élève.
 * Sortie : Un pointeur sur l'élève si il est trouvé. Renvoie NULL sinon.
 *  Usage : ptr_eleveRecherche = RechercherEleveDansEcole(ptr_ecole, nom, prenom);
 * -----------------------------------
 * Recherche un élève dans l'école.
 */
Eleve* RechercherEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char* prenom);



/* Fonction : SupprimerEleveDansEcole
 * ----------------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on veut supprimer l'élève.
 *				  nom - Nom de l'élève.
 *			   prenom - Prénom de l'élève.
 * Sortie : Aucune.
 *  Usage : SupprimerEleveDansEcole(ptr_ecole);
 * ----------------------------------
 * Supprime un élève de l'école.
 */
void SupprimerEleveDansEcole(Ecole_t *ptr_ecole, char *nom, char *prenom);



/* Fonction : ModificationEleve
 * ----------------------------
 * Entrée : ptr_ecole - Pointeur sur l'école dans laquelle on veut modifier l'élève.
 *			ptr_eleve - Pointeur sur l'élève à modifier.
 * Sortie : Aucune.
 *  Usage : ModificationEleve(ptr_ecole, ptr_eleve);
 * ----------------------------
 * Modifie les informations d'un élève et propose de le replacer.
 */
void ModificationEleve(Ecole_t *ptr_ecole, Eleve_t *ptr_eleve)



#endif
