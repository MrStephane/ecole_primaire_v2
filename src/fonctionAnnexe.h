#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#ifndef FONCTIONANNEXE_H
#define FONCTIONANNEXE_H


void ViderBuffer(void);


void RetourLigne(int nb);


void NormaliserNomPrenom(char * civilite, char * nom, char * prenom);


int ControleChaine(char* ch);


#endif