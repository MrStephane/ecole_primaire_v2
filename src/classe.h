#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "prof.h"
#include "eleve.h"


#ifndef CLASSE_H
#define CLASSE_H


#define SEUIL 15



/**************
 * Structures *
 **************/


typedef struct Classe
{
	char nomClasse[5];
	Prof* professeur;
	int nbEleve;
	Eleve* premierEleve;
	struct Classe *suivant;
}Classe_t;




/*************
 * Fonctions *
 *************/


/* Fonction : AfficherClasse
 * -------------------------
 * Entrée : classe - Classe que l'on souhaite afficher.
 * Sortie : Aucune
 *  Usage : AfficherClasse(classe);
 * -------------------------
 * Affiche les infos de la classe ainsi que la liste d'élève.
 */
void AfficherClasse(Classe_t classe);



/* Fonction : RechercherEleveDansClasse
 * ------------------------------------
 * Entrée : ptr_classe - Pointeur de la classe ou on cherche l'élève.
 * 				   nom - Nom de l'élève recherché.
 *				prenom - Prénom de l'élève recherché.
 * Sortie : Un pointeur sur l'élève si il a été trouvé. Renvoie NULL sinon.
 *  Usage : ptr_eleveRecherche = RechercherEleveDansClasse(ptr_classe, nom, prenom);
 * ------------------------------------
 * Recherche un élève dans une classe et retourne un pointeur sur celui-ci si il existe.
 */
Eleve_t* RechercherEleveDansClasse(Classe_t *ptr_classe, char *nom, char *prenom);



/* Fonction : AjouterEleveDansClasse
 * ---------------------------------
 * Entrée : ptr_classe - Pointeur sur la classe ou l'on souhaite ajouter l'élève.
 *			 ptr_eleve - Pointeur sur l'léève à ajouter.
 * Sortie : Aucune.
 *  Usage : AjouterEleveDansClasse(ptr_classe, ptr_eleve);
 * ---------------------------------
 * Ajoute un élève dans la classe quand c'est possible.
 */
void AjouterEleveDansClasse(Classe_t* ptr_classe, Eleve_t* ptr_eleve);



/* Fonction : RetirerEleveDansClasse
 * ---------------------------------
 * Entrée : ptr_classe - Pointeur sur la classe ou l'on souhaite retirer l'élève.
 *			 ptr_eleve - Pointeur sur l'léève à retirer.
 * Sortie : Aucune.
 *  Usage : RetirerEleveDansClasse(ptr_classe, ptr_eleve);
 * ---------------------------------
 * Retire un élève de la classe quand c'est possible sans le supprimer de la mémoire.
 */
void RetirerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve);



/* Fonction : SupprimerEleveDansClasse
 * -----------------------------------
 * Entrée : ptr_classe - Pointeur sur la classe qui contient l'élève à supprimer.
 * 			 ptr_eleve - Pointeur sur l'élève à supprimer.
 * Sortie : Aucune.
 *  Usage : SupprimerEleveDansClasse(ptr_classe, ptr_eleve);
 * -----------------------------------
 * Supprime un élève de la classe passé en paramètre.
 */
void SupprimerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve);



/* Fonction : RechercherClasseEleve
 * --------------------------------
 * Entrée : ptr_classeCourante - Pointeur sur la première classe à parcourir.
 *					 ptr_eleve - Pointeur sur l'élève dont on recherche la classe.
 * Sortie : Un pointeur sur la classe de l'élève si il y en à une. Renvoie NULL sinon.
 *  Usage : ptr_classeEleve = RechercherClasseEleve(ptr_premiereClasse, ptr_eleve);
 * --------------------------------
 * Récupère le pointeur de la classe à laquelle l'élève appartient.
 */
Classe_t* RechercherClasseEleve(Classe_t* ptr_classeCourante, Eleve_t * ptr_eleve);



/* Fonction : RechercherNiveauClasse
 * ---------------------------------
 * Entrée : ptr_classeCourante - Pointeur sur la première classe à parcourir.
 *					 ptr_eleve - Pointeur sur l'élève dont on recherche le niveau de classe.
 * Sortie : Un pointeur sur la classe de l'élève si il y en à une. Renvoie NULL sinon.
 *  Usage : ptr_niveauClasse = RechercherNiveauClasse(ptr_premiereClasse, ptr_eleve);
 * ---------------------------------
 * Récupère le pointeur de la classe de niveau correspondant à l'élève.
 */
Classe_t* RechercherNiveauClasse(Classe_t *ptr_classeCourante, Eleve_t *ptr_eleve);



/* Fonction : RepartitionEleveDansClasse
 * -------------------------------------
 * Entrée : ptr_classe - Pointeur sur la classe qu'il faut répartir équitablement.
 * Sortie : Aucune.
 *  Usage : RepartitionEleveDansClasse(ptr_classe);
 * -------------------------------------
 * Répartie équitablement les élève dans les classes si c'est nécéssaire.
 */
void RepartitionEleveDansClasse(Classe_t *ptr_classe);


#endif // CLASSE_H
