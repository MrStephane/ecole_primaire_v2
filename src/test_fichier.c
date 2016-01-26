#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "fichier.h"



int main(int argc, char *argv[])
{
	char nomFichier[] = "sauvegardeEcole.csv";

///	struct récurs-           nom|prenom |age|genre|classe|adresse|*suivant|*precedent 	
		Eleve_t eleve1 = {"TOTO", "Jean", 9, {01,01,2008}, 0, "CP", "ruetruc", NULL, NULL}; // aucun élèves avant
		Eleve_t eleve2 = {"TITI", "Jean", 9, {02,01,2008}, 0, "CP", "ruetruc", NULL, NULL}; // aucun élèves après
		Eleve_t eleve3 = {"TATA", "Jean", 10, {03,01,2007}, 0, "CE1", "ruetruc", NULL, NULL}; // aucun élèves, ni avant ni après
		Eleve_t eleve4 = {"TUTU", "Jean", 11, {04,01,2006}, 0, "CE2", "ruetruc", NULL, NULL}; // aucun élèves avant
		Eleve_t eleve5 = {"TYTY", "Jean", 11, {05,01,2006}, 0, "CE2", "ruetruc", NULL, NULL}; // aucun élèves après

///	struct récurs- 	      civilite | nom  |  prenom | age
			Prof_t prof1 = {"Mr", "DURAND", "Pierre", 38};
			Prof_t prof2 = {"Mr", "DUPOND", "Paul", 38};
			Prof_t prof3 = {"Mr", "DUPIN", "Jack", 38};

///	struct récurs- nomClasse|prof|nbEleve|*1erEleve|ClasseSuivante
			Classe_t ce2 = {"CE2", &prof3, 2, &eleve4, NULL}; // pas d'autres classes		
			Classe_t ce1 = {"CE1", &prof2, 1, &eleve3, &ce2};
			Classe_t cp1 = {"CP", &prof1, 2, &eleve1, &ce1};

			Ecole_t ecole = {"LDNR", 3, &cp1};

/**	 Ici l'affectation des pointeurs est faite une fois tous les eleves declarés, car structure doublement chainées 	**/
/**	eleve 1 ne connait pas elee 2 au moment de sa declaration, eleve 4 ne connait pas son suivant, pourtant, il existe  **/
				eleve1.suivant = &eleve2;
				eleve1.precedent = NULL;
				eleve2.suivant = NULL;
				eleve2.precedent = &eleve1;
				eleve3.suivant = NULL;
				eleve3.precedent = NULL;
				eleve4.suivant = &eleve5;
				eleve4.precedent = NULL;
				eleve5.suivant = NULL;
				eleve5.precedent = &eleve4;




	RetourLigne(2);
	printf("\t fonction ecrireBaseEleve DEBUT");
	RetourLigne(2);		
		
		ecrireBaseEleve(nomFichier, ecole);	
	
	printf("\t fonction ecrireBaseEleve FIN");
	RetourLigne(2);
/**
		printf("\t fonction lireBaseEleve DEBUT");
		
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
