#include <stdio.h>
#include <stdlib.h>

#include "prof.h"


int main(int argc, char* argv[])
{
	Prof_t* ptr_prof;
	
	
	ptr_prof = CreationProf();
	
	SaisirProf(ptr_prof);
	
	RetourLigne(2);
	
	AfficherProf(*ptr_prof);
	
	SupprimerProf(ptr_prof);
	
	return 0;
}
