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
        scanf("%d %d", &p1[i++].coefficient, &p1[i].exponent); // @@ [Index error: after i++, the next access p1[i].exponent uses incremented i, so it writes to p1[i] instead of p1[i-1]. Should be &p1[i].coefficient, &p1[i].exponent; then i++]
    } while (getchar() != '\n');
    int  j=0;
    while (~scanf("%d %d", &p2[j].coefficient, &p2[j].exponent)) // @@ [Incorrect loop condition: ~scanf(...) is bitwise NOT of return value; should check for ==2 or >0. Also, this loop doesn't stop at newline and will wait for EOF, causing infinite loop on normal input ending with newline]
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
            continue;
        }
        printf("%d %d\n", p3[m].coefficient, p3[m].exponent);
    }
    printf("%d %d ", p3[m].coefficient, p3[m].exponent); // @@ [Potential out-of-bounds access if all terms cancel out or if i*j is 0; also, if last term was merged, it may print a zero-coefficient term]

    return 0;
}