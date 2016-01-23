#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "classe.h"




void SupprimerEleveDansEcole(Ecole_t *ptr_ecole)
{
	Eleve_t *ptr_eleve;
	Classe_t *ptr_classe;
	
	char nom[TAILLECHAINE];
	char prenom[TAILLECHAINE];
	
	
	
	printf("\n\tNom prenom : ");
	scanf("%s %s", nom, prenom);
	ViderBuffer();

	NormaliserNomPrenom(NULL, nom, prenom);
	
	ptr_eleve = RechercherEleveDansEcole(ptr_ecole);
	
	if (ptr_eleve == NULL)
	{
		printf("Cet eleve n'exite pas.\n");
		return;
	}
	
	ptr_classe = RechercherClasseEleve(ptr_ecole->premiereClasse, ptr_eleve);
	if (ptr_classe == NULL)
		printf("Erreur dans la recherche de la classe");
	else
		SupprimerEleveDansClasse(ptr_classe, ptr_eleve);
}
