#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#ifndef DATE_H
#define DATE_H


/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void RecupererDate(struct tm *ptr_d);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void AfficherDate(struct tm ptr_d);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SaisirDate(struct tm *ptr_d);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void CalculRentreeScolaire(struct tm today, struct tm *rentreeScolaire);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
int CalculerAge(struct tm dateJ, struct tm dateN);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
int CategorieAge(struct tm dateN, struct tm dateR);

#endif // DATE_H
