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
        if(poly3[l].exp==poly3[l+1].exp&&poly3[l].coe!=0) // @@ The condition `poly3[l].coe!=0` is incorrect; it should combine terms regardless of whether the current coefficient is zero, because a zero coefficient may result from a previous combination. Also, after combining, the next term's coefficient should be added to the current one, but the loop only checks adjacent pairs once, missing cases where more than two terms have the same exponent.
        {
            poly3[l].coe+=poly3[l+1].coe;
            poly3[l+1].coe=0;
        }
    }
    for(int l=0;l<k;l++)
    if(poly3[l].coe!=0)
    printf("%d %d ",poly3[l].coe,poly3[l].exp);
        
    return 0;
}