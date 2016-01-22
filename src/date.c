#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
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
    printf("%d/%d/%d", ptr_d.tm_mday, ptr_d.tm_mon, ptr_d.tm_year);
}

void SaisirDate(struct tm *ptr_d)
{
	printf("(jj.mm.aaaa) : ");
	scanf("%d.%d.%d", &ptr_d->tm_mday, &ptr_d->tm_mon, &ptr_d->tm_year);
	ViderBuffer();
	ptr_d->tm_mday = ptr_d->tm_mday-1;
	ptr_d->tm_year = ptr_d->tm_year-1900;
}
