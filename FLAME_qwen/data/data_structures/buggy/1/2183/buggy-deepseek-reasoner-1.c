#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void swap(int *a,int *b){
    int m=*a;
    *a=*b;
    *b=m;
}                //交换数值 
void perm(int list[], int k, int m)   //用一个数组表示一行排列 
{
    int i;
    if(k > m){
        for(i = 0; i <= m; i++)
            printf("%d ", list[i]);
        printf("\n");                  //输出一行数组,临界情况 
    }
    else{
        for(i =k; i <= m; i++){
            swap(&list[k], &list[i]); // @@ [Simple swap does not preserve the relative order of remaining elements, so permutations are not generated in lexicographic order. The reference program uses a rotation (exchange) to maintain order.]             
            perm(list,k+1, m);
            swap(&list[k], &list[i]); // @@ [Same issue: restoring with simple swap disrupts the original order needed for lexicographic sequence.]
        }
    } 
} 
int main() 
{     
    int list[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        list[i]=i+1;
    }
    perm(list, 0, n-1);        
    return 0; 
}