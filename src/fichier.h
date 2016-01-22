#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "ecole.h"


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
void gestionErreurs(FILE * fichier);

/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void ecrireBaseEleve(char *nomFichier, Ecole_t ecole);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void lireBaseEleve(char *nomFichier, Ecole_t *ptr_ecole);

#endif // FICHIER_H
