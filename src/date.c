#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "date.h"

/*typedef struct Date
{
	int jour;
	int mois;
	int an;
}Date;*/

void RecupererDate(struct tm *ptr_d)
{
    time_t sec;
    time(&sec);
    ptr_d=localtime(&sec);

}

void AfficherDate(struct tm ptr_d)
{
    printf("%d/%d/%d", &ptr_d.tm_mday, &ptr_d.tm_mon, &ptr_d.tm_year);
}

void SaisirDate(Date *d)
{
	printf("(jj.mm.aaaa) : ");
	scanf("%d.%d.%d", &d->jour, &d->mois, &d->an);
	ViderBuffer();
}
