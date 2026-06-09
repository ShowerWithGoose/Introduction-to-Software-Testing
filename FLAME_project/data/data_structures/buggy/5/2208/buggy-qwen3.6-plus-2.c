#include <stdio.h>
typedef struct Arr
    {
        int coe;
        int exp;
    }arr;
int f(const void *a, const void *b) {  
    arr *x = (arr *)a;  
    arr *y = (arr *)b;  
    return y->exp - x->exp; // 降序排序  
}  
int main()
{
    arr poly1[100];
    arr poly2[100];
    arr poly3[10000];
    char ch;
    int i=0,j=0;
    do{
        scanf("%d%d%c",&poly1[i].coe,&poly1[i].exp,&ch);
        i++;
    }while(ch!='\n');
    do{
        scanf("%d%d%c",&poly2[j].coe,&poly2[j].exp,&ch);
        j++;
    }while(ch!='\n');
    
    int k=0;
    for(int m=0;m<i;m++)
    {
        for(int n=0;n<j;n++)
        {
            poly3[k].coe=poly1[m].coe*poly2[n].coe;
            poly3[k].exp=poly1[m].exp+poly2[n].exp;    
            k++;
        }    
    }
    qsort(poly3,k,sizeof(arr),f);
    int num=0;
    for(int l=0;l<k-1;l++)
    {
        if(poly3[l].exp==poly3[l+1].exp&&poly3[l].coe!=0)
        {
            poly3[l].coe+=poly3[l+1].coe;
            poly3[l+1].coe=0;
        }
    }
    for(int l=0;l<k;l++) // @@ The merging logic in the previous loop is flawed. It only merges adjacent pairs once. If there are three terms with the same exponent (e.g., A, B, C), it merges A+B into A, sets B to 0, but leaves C unmerged with A. Since the array is sorted, all terms with the same exponent are contiguous. The current loop fails to accumulate all coefficients for a given exponent if there are more than 2 terms or if the accumulation changes the relationship with subsequent terms (though here it just misses the third one). Specifically, in the test case, the term with exponent 26 has contributions from multiple products. The simple pairwise merge fails to combine all of them correctly before printing. A correct approach would be to accumulate coefficients for identical exponents into the first occurrence and zero out the others, potentially requiring a nested loop or a different strategy to ensure all like terms are combined. However, the specific error here is that the loop `for(int l=0;l<k-1;l++)` does not handle chains of identical exponents correctly. For example, if indices 0, 1, 2 have the same exp, it merges 0 and 1, then checks 1 (now 0) and 2. It doesn't merge 0 and 2. The term at index 2 remains non-zero and is printed separately, causing duplicate exponents or incorrect sums. In the provided test case, the coefficient for exponent 26 is expected to be 157, but the buggy code outputs 142 and 15 separately (142+15=157). This confirms the merging failure.
    if(poly3[l].coe!=0)
    printf("%d %d ",poly3[l].coe,poly3[l].exp);
        
    return 0;
}