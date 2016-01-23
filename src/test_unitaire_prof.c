#include <stdio.h>
#include <stdlib.h>

#include "prof.h"


int main(int argc, char* argv[])
{
	Prof_t* ptr_prof;
	
	
	ptr_prof = CreationProf();
	
	RetourLigne(2);
	
	SaisirProf(ptr_prof);
	
	RetourLigne(2);
	
	printf("Professeur : ");
	AfficherProf(*ptr_prof);

	RetourLigne(2);
	
	SupprimerProf(ptr_prof);
	
	return 0;
}
