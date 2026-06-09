#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define eps 1e-10
#define LL long long
typedef struct _polynom
{
    int coefficient;
    int exponent;
  
} polynom, *Ppolynom;
int compare(const void *a, const void *b)
{
    polynom *c = (polynom *)a;
    polynom *d = (polynom *)b;
    return d->exponent - c->exponent;
}



int main()
{
    polynom p1[100], p2[100], p3[100];
    int i = 0 ; 
    do
    {
        scanf("%d %d", &p1[i++].coefficient, &p1[i].exponent); // @@ [Error: exponent is stored at index i after increment, causing off-by-one; should store coefficient and exponent at same index before increment.]
    } while (getchar() != '\n');
    int  j=0;
    while (~scanf("%d %d", &p2[j].coefficient, &p2[j].exponent)) // @@ [Error: loop condition should read until newline, not EOF; also no handling for newline, causing infinite loop or wrong input.]
    {
        j++;
    }
    
    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < j; l++)
        {
            p3[k*j+l].coefficient = p1[k].coefficient * p2[l].coefficient;
            p3[k*j+l].exponent = p1[k].exponent + p2[l].exponent;
        }
        
    }
    
    qsort(p3, i*j, sizeof(polynom), compare);
    int m = 0;
    for (; m < i*j-1; m++)
    {
        if (p3[m].exponent == p3[m+1].exponent )
        {
            p3[m+1].coefficient += p3[m].coefficient;
            continue; // @@ [Error: merging logic only combines into next term, but current term's coefficient is not zeroed; also with three or more equal exponents, earlier terms remain non-zero and are never printed.]
        }
        printf("%d %d\n", p3[m].coefficient, p3[m].exponent);
    }
    printf("%d %d ", p3[m].coefficient, p3[m].exponent); // @@ [Error: prints last term unconditionally without checking if its coefficient is zero; also misses possible merged terms before the last.]

    return 0;
}