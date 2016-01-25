#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#ifndef DATE_H
#define DATE_H

void RecupererDate(struct tm *ptr_d);
void AfficherDate(struct tm ptr_d);
void SaisirDate(struct tm *ptr_d);
void CalculRentreeScolaire(struct tm today, struct tm *rentreeScolaire);
int CalculerAge(struct tm dateJ, struct tm dateN);
int CategorieAge(struct tm dateN, struct tm dateR);

#endif // DATE_H
