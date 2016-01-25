#include <stdio.h>
#include <stdlib.h>

#include "fichier.h"

main()
{
	char nomFichier[] = "sauvegardeEcole.xls";
	
	Ecole_t ecole;
	
	
	RetourLigne(2);
		printf("\t fonction ecrireBaseEleve DEBUT");
			ecrireBaseEleve(nomFichier, ecole);
	RetourLigne(2);
		printf("\t fonction ecrireBaseEleve FIN");
			RetourLigne(2);
	printf("\t fonction lireBaseEleve DEBUT");
			lireBaseEleve(char *nomFichier, Ecole_t *ptr_ecole);
		RetourLigne(2);
	printf("\t fonction lireBaseEleve FIN ");
		RetourLigne(2);
}
