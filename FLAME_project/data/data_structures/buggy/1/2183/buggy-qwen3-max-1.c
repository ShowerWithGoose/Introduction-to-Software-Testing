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
            swap(&list[k], &list[i]);             
            perm(list,k+1, m);
            swap(&list[k], &list[i]);
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
    perm(list, 0, n-1);        @@ The recursive permutation generation does not produce output in lexicographical order because swapping disrupts the sorted order needed for lexicographic sequence. The algorithm generates all permutations but not necessarily in sorted order, which violates the problem requirement.
    return 0; 
}