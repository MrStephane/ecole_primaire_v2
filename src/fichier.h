#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecole.h"
#include "fonctionAnnexe.h"



#ifndef FICHIER_H
#define FICHIER_H



/*************
 * Fonctions *
 *************/

 
/* Fonction : gestionErreurs();
 * ----------
 * Entrée : Un pointeur vers une structure FILE
 * Sortie :	Rien
 *  Usage : gestionErreurs(fichier);
 * ----------
 * Description : Stop le programme en cas d'erreur d'ouverture du fichier
 */
void gestionErreurs(FILE * fichier);


/* Fonction : ecrireBaseEleve();
 * ----------
 * Entrée : Le nom du fichier à écrire et la structure ecole_t a sauvegarder
 * Sortie :	Rien
 *  Usage : ecrireBaseEleve(nomFichier, ecole);
 * ----------
 * Description : Permet d'écrire toutes les données de l'école dans un fichier
 */
void ecrireBaseEleve(const char *nomFichier, Ecole_t ecole);


/* Fonction : lireBaseEleve();
 * ----------
 * Entrée : Le nom du fichier à lire et un pointeur vers la structure ecole_t
 * Sortie : Rien
 *  Usage : lireBaseEleve(nomFichier, &ecole);
 * ----------
 * Description : Permet de lire le fichier de sauvegarde en clair
 */
void lireBaseEleve(const char *nomFichier, Ecole_t *ptr_ecole);

#endif // FICHIER_H
