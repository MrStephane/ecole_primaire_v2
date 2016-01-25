#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "fichier.h"
#include "ecole.h"
#include "personnel.h"
#include "classe.h"
#include "eleve.h"
#include "date.h"
#include "fonctionAnnexe.h"

int main(int argc, char *argv[])
{
	char nomFichier[] = "sauvegardeEcole.txt";
	
	Ecole_t ecole = {"LDNR", 3, &cp1};
	Classe_t cp1 = {"CP", &prof1, 2, &eleve1, &ce1};
	Classe_t ce1 = {"CE1", &prof2, 1, &eleve3, &ce1};
	Classe_t ce2 = {"CE2", &prof3, 2, &eleve4, &ce2};
	Prof_t prof1 = {"Mr", "DURAND", "Pierre", 38};
	Prof_t prof2 = {"Mr", "DUPOND", "Paul", 38};
	Prof_t prof3 = {"Mr", "DUPIN", "Jack", 38};
	/*                  nom|prenom |age|genre|classe|adresse|*suivant|*precendent */
	Eleve_t eleve1 = {"TOTO", "Jean", 9, , 0, "CP", "ruetruc", &eleve2, NULL};
	Eleve_t eleve2 = {"TITI", "Jean", 9, , 0, "CP", "ruetruc", NULL, &eleve1};
	Eleve_t eleve3 = {"TATA", "Jean", 10, , 0, "CE1", "ruetruc", NULL, NULL};
	Eleve_t eleve4 = {"TUTU", "Jean", 11, , 0, "CE2", "ruetruc", &eleve5, NULL};
	Eleve_t eleve5 = {"TYTY", "Jean", 11, , 0, "CE2", "ruetruc", NULL, eleve4};
	
	

	RetourLigne(2);
	printf("\t fonction ecrireBaseEleve DEBUT");
	RetourLigne(2);		
		
		ecrireBaseEleve(nomFichier, ecole);	
	
	printf("\t fonction ecrireBaseEleve FIN");
	RetourLigne(2);

/**	printf("\t fonction lireBaseEleve DEBUT");
	
		lireBaseEleve(nomFichier, &ecole);
	
	RetourLigne(2);
	printf("\t fonction lireBaseEleve FIN");
	RetourLigne(2);
*/
	
/*
	SaveBinaireBaseEleve(nomFichier, ecole);

	RecupSaveBinaireBaseEleve(nomFichier, &ecole);
*/
	

return 0;
}
