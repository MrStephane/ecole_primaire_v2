#include "prof.h"



Prof_t* CreationProf(void)
{
	Prof_t *ptr_prof;
	
	ptr_prof = (Prof_t*) calloc(1, sizeof(Prof_t));
	
	if (ptr_prof == NULL)
		exit(EXIT_FAILURE);
	
	return ptr_prof;
}



void AfficherProf(Prof_t p)
{
	printf("%s %s %s", p.civilite, p.nom, p.prenom);
}




void SaisirProf(Prof_t *ptr_p)
{
    int continuer = 0;


	SaisieChaineControle("Saisir la civilite du professeur ( Monsieur, Madame, Mademoiselle ) : ", ptr_p->civilite);
	SaisieChaineControle("Entrez le nom du professeur : ", ptr_p->nom);
	SaisieChaineControle("Entrez le prenom du professeur : ", ptr_p->prenom);

	NormaliserNomPrenom(ptr_p->civilite, ptr_p->nom, ptr_p->prenom);
}



void SupprimerProf(Prof_t *ptr_prof)
{
	free(ptr_prof);
}
