#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "date.h"



#ifndef ELEVE_H
#define ELEVE_H




/**************
 * Structures *
 **************/


typedef struct Eleve 
{     
	char nom[TAILLECHAINE];     
	char prenom[TAILLECHAINE];     
	int age;     
	struct tm dateDeNaissance;     
	int genre; // 0 pour garcon et 1 pour fille     
	char nomClasse[5]; 
	char adresse[26];
	struct Eleve *suivant;
	struct Eleve *precedent;
}Eleve_t;




/*************
 * Fonctions *
 *************/

 
/* Fonction : CreationEleve
 * ------------------------
 * Entrée : Aucune.
 * Sortie : Un pointeur sur l'élève créé.
 *  Usage : ptr_eleve = CreationEleve();
 * ------------------------
 * Créé un élève initialisé à 0 en mémoire?
 */
 Eleve_t* CreationEleve(void);


/* Fonction : SaisirEleve
 * ----------------------
 * Entrée : ptr_eleve - Pointeur sur l'élève à saisir.
 *				  nom - Nom de l'élève. (Optionnel)
 *			   prenom - Prénom de l'élève. (Optionnel)
 * Sortie : Aucune.
 *  Usage : SaisirEleve(ptr_eleve, nom, prenom); OU SaisirEleve(ptr_eleve, NULL, NULL);
 * ----------
 * Saisie les informations d'un élève.
 */
void SaisirEleve(Eleve_t* ptr_eleve, char* nom, char* prenom);



/* Fonction : AfficherEleve
 * ------------------------
 * Entrée : eleve - Elève à afficher.
 * Sortie : Aucune.
 *  Usage : AfficherEleve(eleve);
 * ------------------------
 * Affiche les informations d'un élève.
 */
void AfficherEleve(Eleve_t eleve);



/* Fonction : SupprimerEleve
 * -------------------------
 * Entrée : ptr_eleve - Pointeur sur l'élève à supprimer.
 * Sortie : Aucune.
 *  Usage : SupprimerEleve(ptr_eleve);
 * -------------------------
 * Supprime un élève de la mémoire.
 */
void SupprimerEleve(Classe_t* ptr_eleve);



/* Fonction : ElevePosition
 * ------------------------
 * Entrée : ptr_eleveCourant - Pointeur sur un premier élève.
 *					position - Position de l'élève que l'on veut récupérer dans la classe.
 * Sortie : Pointeur sur l'élève si il existe.
 *  Usage : ptr_eleve = ElevePosition(ptr_eleveCourant, position);
 * ------------------------
 * Recupère un pointeur sur l'élève situé à une position spécifique dans la classe.
 */
Eleve_t* ElevePosition(Eleve_t *ptr_eleveCourant, int position);


/* Fonction : DernierEleve
 * -----------------------
 * Entrée : ptr_eleveCourant - Pointeur d'élève? Variable de parcours.
 * Sortie : Un pointeur sur le dernier élève. Renvoie NULL sinon.
 *  Usage : ptr_dernierEleve = DernierEleve(ptr_elveCourant);
 * -----------------------
 * Recupère un pointeur sur le dernier élève d'une classe.
 */
Eleve_t* DernierEleve(Eleve_t *ptr_eleveCourant);

#endif // ELEVE_H
