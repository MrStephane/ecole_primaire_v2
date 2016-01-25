#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifndef FONCTIONANNEXE_H
#define FONCTIONANNEXE_H



/*************
 * Fonctions *
 *************/


/* Fonction : ViderBuffer
 * ----------------------
 * Entrée : Aucune
 * Sortie : Aucune
 *  Usage : ViderBuffer();
 * ----------------------
 * Vide le buffer pour éviter le bug de saisie.
 */
void ViderBuffer(void);



/* Fonction : RetourLigne
 * ----------------------
 * Entrée : nb - Nombre de ligne à sauter.
 * Sortie : Aucune
 *  Usage : RetourLigne(nombreLigne);
 * ----------------------
 * Saute un nombre choisie de ligne dans l'affichage console.
 */
void RetourLigne(int nb);



/* Fonction : NormaliserNomPrenom
 * ------------------------------
 * Entrée : civilite - Civilite de la personne.
 * 			nom - Nom de la personne.
 * 			prenom - Prenom de la personne.
 * Sortie : Aucune.
 *  Usage : NormaliserNomPrenom(civilite, nom, prenom);
 * ------------------------------
 * Permet de normaliser la civilité, le nom et le prémon avec une majuscule au début et le reste en minuscule.
 */
void NormaliserNomPrenom(char * civilite, char * nom, char * prenom);



/* Fonction : ControleChaine
 * -------------------------
 * Entrée : ch - Chaine à controler.
 * Sortie : Un entier qui vaut 1 si la chaine est valide, 0 sinon.
 *  Usage : estValide = ControleChaine(ptr_chaine);
 * -------------------------
 * Controle qu'une chaine ne contient pas d'accent ni de chiffre.
 */
int ControleChaine(char* ch);



/* Fonction : SaisieChaineControle
 * -------------------------------
 * Entrée : ptr_chaine - Pointeur sur la chaine a saisir.
 * 			message - Message a afficher avant la saisie.
 * Sortie : Aucune.
 *  Usage : SaisieChaineControle(ptr_chaine, message);
 * -------------------------------
 * Fait une saisie tant que la chaine ne valide pas le contrôle.
 */
void SaisieChaineControle(char *ptr_chaine, char *message);


#endif
