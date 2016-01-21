#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#ifndef FICHIER_H
#define FICHIER_H



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
void ecrireBaseEleve(char *nomFichier, Classe_t ecole);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void lireBaseEleve(char *nomFichier, Classe_t *ptr_ecole);

#endif // FICHIER_H
