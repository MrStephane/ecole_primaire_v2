#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "fonctionAnnexe.h"


void ViderBuffer(void)
{
	char c;
	while((c=getchar()) != '\n');
}



void RetourLigne(int nb)
{
	int i;
	for (i = 0; i < nb; ++i)
		printf("\n");
}



void NormaliserNomPrenom(char * civilite, char * nom, char * prenom)
{
	int i=0;

	// ex : NOM
	for(i=0;i<strlen(nom); i++)
		nom[i] = toupper(nom[i]);
	// ex : Prenom
	for(i=0;i<strlen(prenom); i++)
	{
		if(i==0)
			prenom[i] = toupper(prenom[i]);

		else if(i>0)
			prenom[i] = tolower(prenom[i]);
	}
	// ex : Mme --> meme traitement que le prenom
	if(civilite)
	{
		for(i=0;i<strlen(civilite); i++)
		{
			if(i==0)
				civilite[i] = toupper(civilite[i]);

			else if(i>0)
				civilite[i] = tolower(civilite[i]);
		}
	}
}



int ControleChaine(char* ch)
{
	int tailleCh = strlen(ch);
	int i;


	for (i = 0; i < tailleCh; ++i)
	{
		if (!((ch[i] > 64 && ch[i] < 91) || (ch[i] > 96 && ch[i] < 123)))
            return 0;
	}

	return 1;
}
