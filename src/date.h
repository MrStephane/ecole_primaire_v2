#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#ifndef DATE_H
#define DATE_H

void RecupererDate(struct tm *ptr_d);
void AfficherDate(struct tm ptr_d);
void SaisirDate(struct tm *ptr_d);

#endif // DATE_H
