#include <stdio.h>
#include <stdlib.h>

#include "ecole.h"
#include "fichier.h"

int main(int argc, char *argv[])
{
	char nomFichier[] = "sauvegardeEcole.txt";
	
	Ecole_t ecole;
	
/*	
	RetourLigne(2);
	printf("\t fonction ecrireBaseEleve DEBUT");
	RetourLigne(2);		
		
		ecrireBaseEleve(nomFichier, ecole);
	
	printf("\t fonction ecrireBaseEleve FIN");
	RetourLigne(2);
	printf("\t fonction lireBaseEleve DEBUT");
	
		lireBaseEleve(nomFichier, &ecole);
	
	RetourLigne(2);
	printf("\t fonction lireBaseEleve FIN");
	RetourLigne(2);
*/
	SaveBinaireBaseEleve(nomFichier, ecole);

	RecupSaveBinaireBaseEleve(nomFichier, &ecole);

	

return 0;
}
