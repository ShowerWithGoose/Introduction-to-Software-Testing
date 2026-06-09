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
    for(int l=0;l<k;l++) // @@ The merging logic in the previous loop is flawed. It only merges adjacent pairs once. If there are three terms with the same exponent, or if merging creates a zero coefficient that needs to be skipped, the simple adjacent check fails. More critically, if poly3[l].coe becomes 0 after addition (though unlikely with non-zero inputs unless they cancel out), it should be handled. However, the main issue here is that the merging loop doesn't propagate the sum correctly if there are more than 2 terms with the same exponent, or if the sorting puts them together but the accumulation logic is insufficient. Actually, looking at the expected output vs buggy output: Buggy has `142 26` and `15 26`, Expected has `157 26`. This means the terms with exponent 26 were not fully merged. The input polynomials have terms that result in multiple product terms with exponent 26. The current loop only adds `l+1` to `l`. If there are 3 terms, `l` gets `l+1`, but `l+1` (now 0) is not added to `l+2` in a way that affects `l`. Wait, if `l` merges with `l+1`, `l+1` becomes 0. Then when `l` increments, it sees `l+1` (which was `l+2`) and compares. But the term at original `l+2` was never added to original `l`. The standard way is to accumulate all same exponents. The current logic fails for >2 terms.
    if(poly3[l].coe!=0)
    printf("%d %d ",poly3[l].coe,poly3[l].exp);
        
    return 0;
}