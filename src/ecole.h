#include "classe.h"


#ifndef ECOLE_H
#define ECOLE_H


#define TAILLECHAINE 40


typedef struct Ecole
{
	char nomEcole[TAILLECHAINE];
	int nbClasse;
	Classe_t *premiereClasse;	// Pointeur sur la première classe.
} Ecole_t;




void SupprimerEleveDansEcole(Ecole_t *ptr_ecole);



#endif