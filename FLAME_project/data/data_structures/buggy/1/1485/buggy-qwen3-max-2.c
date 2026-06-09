/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void pailie(int arr[],int p,int q){  //arr数组中，从第p个到第q个数全排列 
    int i;
    if(p==q){
        for(i=0;i<=p;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    else{
    
        for(i=p;i<=q;i++){
            change(arr,p,i);
            pailie(arr,p+1,q);
            changeback(arr,p,i);    
        }
    }
}
void change(int arr[],int p,int i){//右移 
    int c,k;
    c=arr[i];
    for(k=i-1;k>=p;k--){
        arr[k+1]=arr[k];
    }
    arr[p]=c;
}

void changeback(int arr[],int p,int i){//左移 
    int c,k;
    c=arr[p];
    for(k=p;k<i;k++){
        arr[k]=arr[k+1];
    }
    arr[i]=c;
}

int main()
{
    int arr[20];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=i+1;
    }
    pailie(arr,0,n-1);
    return 0;
} // @@ [The program outputs permutations without spaces between numbers and does not generate them in lexicographical order due to incorrect permutation generation logic. The `change` and `changeback` functions perform rotations instead of simple swaps, which disrupts the standard recursive backtracking approach needed for lexicographic order. Additionally, the output format requires a space between each number, but the current code prints digits consecutively (e.g., "12" instead of "1 2").]