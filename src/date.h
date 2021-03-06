#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "fonctionAnnexe.h"


#ifndef DATE_H
#define DATE_H


/* Fonction : RecupererDate
 * ------------------------
 * Entrée : ptr_dateJour - Pointeur sur la structure date à récupérer.
 * Sortie : Aucune.
 *  Usage : RecupererDate(ptr_dateDuJour);
 * ------------------------
 * Récupère la date du jour.
 */
void RecupererDate(struct tm *ptr_dateJour);



/* Fonction : AfficherDate
 * -----------------------
 * Entrée : date - Date à afficher.
 * Sortie : Aucune.
 *  Usage : AfficherDate(date);
 * -----------------------
 * Affiche une date au format jj/mm/aaaa
 */
void AfficherDate(struct tm date);



/* Fonction : SaisirDate
 * ---------------------
 * Entrée : ptr_d - Pointeur sur la date à saisir.
 * Sortie : Aucune.
 *  Usage : SaisirDate(ptr_d);
 * ---------------------
 * Saisie une date au format jj.mm.aaaa
 */
void SaisirDate(struct tm *ptr_d);



/* Fonction : ControleDate
 * -----------------------
 * Entrée : d - Date à controler.
 * Sortie : Un entier qui vaut 1 si la date est valide, O sinon.
 *  Usage : estValide = ControleDate(date);
 * -----------------------
 * Controle si une date est valide.
 */
int ControleDate(struct tm d);



/* Fonction : CalculRentreeScolaire
 * --------------------------------
 * Entrée : 		  	  today - Date du jour.
 *			ptr_rentreeScolaire - Pointeur sur la date de rentrée scolaire.
 * Sortie : Aucune.
 *  Usage : CalculRentreeScolaire(dateDuJour, ptr_dateDeRentreeScolaire);
 * --------------------------------
 * Définie la date de rentré scolaire en fonction de la date du jour.
 */
void CalculRentreeScolaire(struct tm today, struct tm *ptr_rentreeScolaire);



/* Fonction : CalculerAge
 * ----------------------
 * Entrée : dateJ - Date du jour.
 *			dateN - Date de naissance de l'élève.
 * Sortie : L'age de l'élève.
 *  Usage : ageDeEleve = CalculerAge(dateDuJour, dateDeNaissance);
 * ----------------------
 * Calcule l'age de l'élève en fonction de la date du jour.
 */
int CalculerAge(struct tm dateJ, struct tm dateN);



/* Fonction : CategorieAge
 * -----------------------
 * Entrée : dateN - Date de naissance de l'élève.
 * 			dateR - Date de rentré scolaire.
 * Sortie : La catégorie d'age de l'élève.
 *  Usage : categorieAge = CategorieAge(dateDeNaissance, dateDeRentreeScolaire);
 * -----------------------
 * Calcule la catégorie d'age de l'élève en fonctoin de son age.
 */
int CategorieAge(struct tm dateN, struct tm dateR);

#endif // DATE_H
