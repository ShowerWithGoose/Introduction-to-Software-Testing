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
    polynom p1[100], p2[100], p3[100]; // @@ p3 array size is too small; the product of two polynomials can have up to num1*num2 terms, which can easily exceed 100. Should be increased to at least 20000.
    int i = 0 ; 
    do
    {
        scanf("%d %d", &p1[i++].coefficient, &p1[i].exponent); // @@ Undefined behavior: i is modified by i++ and read in the second argument without a sequence point. Also, i increments before reading the exponent, causing misalignment of coefficients and exponents.
    } while (getchar() != '\n');
    int  j=0;
    while (~scanf("%d %d", &p2[j].coefficient, &p2[j].exponent))
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
        printf("%d %d\n", p3[m].coefficient, p3[m].exponent); // @@ Should check if p3[m].coefficient is non-zero before printing to avoid outputting zero terms. Also, output format expects spaces, not newlines.
    }
    printf("%d %d ", p3[m].coefficient, p3[m].exponent); // @@ Does not check for zero coefficient; may print a zero term or uninitialized data if the loop condition was never met.

    return 0;
}