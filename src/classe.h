#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
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
	Eleve* classe;
	struct Classe *suivant;
}Classe_t;




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
void AfficherClasse(Classe_t classe);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void SupprimerEleveDansClasse(Classe_t *ptr_classe, Eleve_t *ptr_eleve);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
Classe_t* RechercherClasseEleve(Classe_t* ptr_classeCourante, Eleve_t * ptr_eleve);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void RepartitionEleveDansClasse(Classe_t *ptr_classe);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
Eleve_t* RechercherEleveDansClasse(Classe_t *ptr_classe, char *nom, char *prenom);



/* Fonction :
 * ----------
 * Entrée :
 * Sortie :
 *  Usage :
 * ----------
 * *Description*
 */
void AjouterEleveDansClasse(Classe_t* ptr_classe, Eleve_t* ptr_eleve)


#endif // CLASSE_H
