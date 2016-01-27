#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "fichier.h"



int main(int argc, char *argv[])
{	// recuperation du nom du fichier BDD portant le nom de l'ecole via parametre au lancement
	char nomFichier[100] = "";
	char extension[] = ".csv";
	strcpy(nomFichier, argv[1]);
	strcat(nomFichier, extension);
	printf("\n\n\n\t-@- %s -@-\n\n", nomFichier);
/*-->**/
///	struct récurs-           nom|prenom |age|dateDNaissance|genre|classe|adresse|*suivant|*precedent 	
		Eleve_t eleve1 = {"TOTO", "Jean", 9, {0,0,0, 01,0, 108, 0, 0, 0}, 0, "CP", "ruetruc", NULL, NULL}; // aucun élèves avant
		Eleve_t eleve2 = {"TITI", "Jean", 9, {0,0,0, 02,0,108, 0, 0, 0}, 0, "CP", "ruetruc", NULL, NULL}; // aucun élèves après
		Eleve_t eleve3 = {"TATA", "Jean", 10, {0, 0, 0, 03,0,107, 0, 0, 0}, 0, "CE1", "ruetruc", NULL, NULL}; // aucun élèves, ni avant ni après
		Eleve_t eleve4 = {"TUTU", "Jean", 11, {0, 0, 0, 04,0,106, 0, 0, 0}, 0, "CE2", "ruetruc", NULL, NULL}; // aucun élèves avant
		Eleve_t eleve5 = {"TYTY", "Jean", 11, {0, 0, 0, 05,0,106, 0, 0, 0}, 0, "CE2", "ruetruc", NULL, NULL}; // aucun élèves après

///	struct récurs- 	      civilite | nom  |  prenom
			Prof_t prof1 = {"Mr", "DURAND", "Pierre"};
			Prof_t prof2 = {"Mr", "DUPOND", "Paul"};
			Prof_t prof3 = {"Mr", "DUPIN", "Jack"};

///	struct récurs-        nomClasse|prof|nbEleve|*1erEleve|*ClasseSuivante
			Classe_t ce2 = {"CE2", &prof3, 2, &eleve4, NULL};	
			Classe_t ce1 = {"CE1", &prof2, 1, &eleve3, &ce2};
			Classe_t cp1 = {"CP", &prof1, 2, &eleve1, &ce1};

			Ecole_t ecole = {"LDNR", 3, &cp1};

///	 Ici l'affectation des pointeurs est faite une fois tous les eleves declarés, car structure doublement chainées 	

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
/*<--**/

	RetourLigne(2);
	printf("\t fonction ecrireBaseEleve DEBUT");
	RetourLigne(2);		
		//A APPELER EN QUITTANT L APPLI
		ecrireBaseEleve(nomFichier, ecole);	

	printf("\t fonction ecrireBaseEleve FIN");
	RetourLigne(2);


/*
Ecole_t ecole;


		printf("\t fonction lireBaseEleve DEBUT");
		//A APPELER EN ENTRANT DANS L APPLI
			lireBaseEleve(nomFichier, &ecole);
		
		RetourLigne(2);
		printf("\t fonction lireBaseEleve FIN");
		RetourLigne(2);
*/
return 0;
}
