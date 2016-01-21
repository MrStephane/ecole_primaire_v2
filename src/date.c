#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "date.h"


void RecupererDate(struct tm *ptr_d)
{
    time_t sec;
    time(&sec);
    ptr_d=localtime(&sec);

}

void Afficherdate(struct tm d)
{
    printf("%d/%d/%d", &d.tm_mday, &d.tm_mon, &d.tm_year);
}

/*void SaisirDate(Date *ptr_d)
{
	printf("(jj.mm.aaaa) : ");
	scanf("%d.%d.%d", &ptr_d->jour, &ptr_d->mois, &ptr_d->an);
	ViderBuffer();
}*/
